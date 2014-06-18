#include "funclib.h"

void getNeighborByDir(long dir,long &x,long &y,long maxx,long maxy){
	switch(dir){
		case 0:
			x--;
			if(x<0) x++;
			break;
		case 1:
			x++;
			if(x==maxx) x--;
			break;
		case 2:
			y--;
			if(y<0) y++;
			break;
		case 3:
			y++;
			if(y==maxy) y--;
			break;
	}
}

inline bool isNeighbor(long x,long y,long xx,long yy){
	if(x!=xx) return true;
	if(y!=yy) return true;
	return false;
}

D2Array<long> * clustering(const QImage *image,long clusterNum,long clusterTimes){
	long n=clusterNum; 
	const long h=image->height(),w=image->width();
	long x,y,z,t;
	myRGB<> *centerPoint=new myRGB<>[n];
	D2Array<long> *arr=new D2Array<long>(h,w);
	for(x=0;x<n;x++)
		centerPoint[x].randomize();
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			long mindist=999999999,tmp;
			for(z=0;z<n;z++){
				tmp=centerPoint[z].distance(image->pixel(x,y));
				if(tmp<mindist){
					mindist=tmp;
					(*arr)[y][x]=z;
				}
			}
		}
	}
	long *counter=new long[n];
	for(t=0;t<clusterTimes;t++){
		for(z=0;z<n;z++){ centerPoint[z].clear(); counter[z]=0; }
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter[(*arr)[y][x]]++;
				centerPoint[(*arr)[y][x]]+=image->pixel(x,y);
			}
		}
		for(z=0;z<n;z++) if(counter[z]) centerPoint[z]/=counter[z]; else centerPoint[z].randomize();
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				long mindist=999999999,tmp;
				for(z=0;z<n;z++){
					tmp=centerPoint[z].distance(image->pixel(x,y));
					if(tmp<mindist){
						mindist=tmp;
						(*arr)[y][x]=z;
					}
				}
			}
		}
	}
	delete [] centerPoint;
	delete [] counter;
	return arr;
}

QImage * transform(const QImage *image,double zoom){
	long x,y,i,j,w=(long)(image->width()/zoom),h=(long)(image->height()/zoom);
	QImage *displayImage=new QImage(w,h,QImage::Format::Format_ARGB32);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			long b=(long)(x*zoom),c=(long)(y*zoom);
			myRGB<> sum; long area=0;
			for(i=b;i<b+zoom;i++){
				for(j=c;j<c+zoom;j++){
					sum+=image->pixel(i,j);
					area++;
				}
			}
			sum/=area;
			displayImage->setPixel(x,y,sum.toQRGB());
		}
	}
	return displayImage;
}

int toGray(const QRgb &c){
	myRGB<> sum(c);
	sum.vmul(0.3,0.59,0.11);
	int res=sum.r+sum.g+sum.b;
	return res;
}

QImage * gray(const QImage *originalImage){
	QImage *image=new QImage(*originalImage);
	long x,y,w=image->width(),h=image->height();
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			int avg=toGray(image->pixel(x,y));
			image->setPixel(x,y,qRgb(avg,avg,avg));
		}
	}
	return image;
}

QImage *binarize(const QImage *originalImage){
	QImage *image=new QImage(*originalImage);
	long x,y,w=image->width(),h=image->height();
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			int avg=toGray(image->pixel(x,y));
			if(avg>=128) avg=255; else avg=0;
			image->setPixel(x,y,qRgb(avg,avg,avg));
		}
	}
	return image;
}

QString * image2Text(const QImage *image,QString *chars){
	QString *tmp=new QString("");
	long n=chars->length();
	long x,y,z,h=image->height(),w=image->width(),t;
	QImage *myImage=noLightnessRGB(image);
	D2Array<long> *arr=clustering(myImage,n,100);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			tmp->push_back((*chars)[(*arr)[y][x]]);
		}
		tmp->push_back('\n');
	}
	delete arr;
	delete myImage;
	return tmp;
}

QImage * noLightnessRGB(const QImage *image){
	long x,y,w=image->width(),h=image->height();
	QImage *myImage=new QImage(w,h,QImage::Format::Format_RGB32);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			myRGB<double> tmp(image->pixel(x,y));
			//tmp.vmul(0.7,0.41,0.89);
			double gray=tmp.toGray();
			tmp-=gray;
			tmp*=4.0;
			tmp+=40.0;
			myImage->setPixel(x,y,tmp.toQRGB());
		}
	}
	return myImage;
}

QImage *noiseReduce(const QImage *image){
	long x,y,z,h=image->height(),w=image->width(),xx,yy,counter;
	QImage * myImage=new QImage(w,h,QImage::Format_RGB32);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			myRGB<> tmp; counter=0;
			for(z=0;z<4;z++){
				xx=x; yy=y;
				getNeighborByDir(z,xx,yy,w,h);
				if(isNeighbor(x,y,xx,yy)){
					tmp+=image->pixel(xx,yy);
					counter++;
				}
			}
			tmp/=counter;
			myImage->setPixel(x,y,tmp.toQRGB());
		}
	}
	return myImage;
}

QImage *edgeSmoothing(const QImage * image){
	QImage *res=new QImage(*image);
	long x,y,z,h=image->height(),w=image->width(),xx,yy,counter; 
	QImage *tmp; QRgb self;
	long t,flag;
	for(t=0;t<10;t++){
		tmp=res;
		res=new QImage(w,h,QImage::Format::Format_RGB32); 
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter=0; self=tmp->pixel(x,y);
				for(z=0;z<4;z++){
					xx=x; yy=y;
					getNeighborByDir(z,xx,yy,w,h);
					if(isNeighbor(x,y,xx,yy)){
						if(tmp->pixel(xx,yy)!=self){
							counter++;
						}
					}
				}
				flag=qRed(self);
				if(counter>2) flag=256-flag;
				res->setPixel(x,y,qRgb(flag,flag,flag));
			}
		}
		delete tmp;
	}
	return res;
}

QImage *edgeDetection(const QImage * image,long clusterNum,long clusterTimes){
	long x,y,z,h=image->height(),w=image->width(),xx,yy,counter; 
	QImage * res=new QImage(w,h,QImage::Format::Format_RGB32);
	QImage * myImage=noLightnessRGB(image);
	D2Array<long> *arr=clustering(myImage,clusterNum,clusterTimes);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			res->setPixel(x,y,qRgb(0,0,0));
			counter=0; double dis=0;
			myRGB<> self((*myImage).pixel(x,y));
			for(z=0;z<4;z++){
				xx=x; yy=y;
				getNeighborByDir(z,xx,yy,w,h);
				if(isNeighbor(x,y,xx,yy))
				if((*arr)[y][x]!=(*arr)[yy][xx]){
					dis+=self.distance((*myImage).pixel(xx,yy));
					counter++;
				}
			}
			if(counter!=0){
				dis/=counter;
				if(dis>95){ //3.3
					res->setPixel(x,y,qRgb(255,255,255));
				}
			}
		}
	}
	delete myImage;
	delete arr;
	return res;
}