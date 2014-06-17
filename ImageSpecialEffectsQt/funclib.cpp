#include "funclib.h"

void getNeighborByDir(long dir,long &x,long &y,long maxx,long maxy){
	switch(dir){
		case 0:
			x--;
			if(x<0) x=maxx-1;
			break;
		case 1:
			x++;
			if(x==maxx) x=0;
			break;
		case 2:
			y--;
			if(y<0) y=maxy-1;
			break;
		case 3:
			y++;
			if(y==maxy) y=0;
			break;
	}
}

D2Array<long> * clustering(D2Array<double> *image,long clusterNum,long clusterTimes){
	long n=clusterNum; 
	const long h=image->row,w=image->col;
	long x,y,z,t;
	double *centerPoint=new double[n];
	D2Array<long> *arr=new D2Array<long>(h,w);
	for(x=0;x<n;x++)
		centerPoint[x]=(rand()%255000)/1000;
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			double mindist=999999999; double tmp;
			for(z=0;z<n;z++){
				tmp=centerPoint[z]-(*image)[y][x];
				tmp=tmp*tmp;
				if(tmp<mindist){
					mindist=tmp;
					(*arr)[y][x]=z;
				}
			}
		}
	}
	long *counter=new long[n];
	for(t=0;t<clusterTimes;t++){
		for(z=0;z<n;z++){ centerPoint[z]=0; counter[z]=0; }
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter[(*arr)[y][x]]++;
				centerPoint[(*arr)[y][x]]+=(*image)[y][x];
			}
		}
		for(z=0;z<n;z++) if(counter[z]) centerPoint[z]/=counter[z]; else centerPoint[z]=(rand()%255000)/1000;
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				double mindist=999999999; double tmp;
				for(z=0;z<n;z++){
					tmp=centerPoint[z]-(*image)[y][x];
					tmp=tmp*tmp;
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

QString * image2Text(const QImage *image,QString *chars){
	QString *tmp=new QString("");
	long n=chars->length();
	long x,y,z,h=image->height(),w=image->width(),t;
	D2Array<double> *myImage=noLightness(image);
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

D2Array<double> * noLightness(const QImage * image){
	long x,y,h=image->height(),w=image->width();
	D2Array<double> *myImage=new D2Array<double>(h,w);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			myRGB<double> tmp(image->pixel(x,y));
			(*myImage)[y][x]=tmp.r*0.35+tmp.g*0.205+tmp.b*0.445;
		}
	}
	return myImage;
}

QImage *edgeDetection(const QImage * image,long clusterNum,long clusterTimes){
	long x,y,z,h=image->height(),w=image->width(),xx,yy; 
	QImage * res=new QImage(w,h,QImage::Format::Format_RGB32);
	D2Array<double> * myImage=noLightness(image);
	D2Array<long> *arr=clustering(myImage,clusterNum,clusterTimes);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			res->setPixel(x,y,qRgb(0,0,0));
			long counter=0; double dis=0;
			double self=(*myImage)[y][x];
			for(z=0;z<4;z++){
				xx=x; yy=y;
				getNeighborByDir(z,xx,yy,w,h);
				if((*arr)[y][x]!=(*arr)[yy][xx]){
					dis+=abs(self-(*myImage)[yy][xx]);
					counter++;
				}
			}
			if(counter!=0){
				dis/=counter;
				if(dis>3.3){
					res->setPixel(x,y,qRgb(255,255,255));
				}
			}
		}
	}
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			if(res->pixel(x,y)==qRgb(255,255,255)){
				long counter=0;
				for(z=0;z<4;z++){
					xx=x; yy=y;
					getNeighborByDir(z,xx,yy,w,h);
					if(res->pixel(xx,yy)!=qRgb(255,255,255)){
						counter++;
					}
				};
				if(counter>2){
					res->setPixel(x,y,qRgb(0,0,0));
				}
			}
		}
	}
	delete myImage;
	delete arr;
	return res;
}