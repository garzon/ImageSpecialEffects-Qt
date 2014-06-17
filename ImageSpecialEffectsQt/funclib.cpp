#include "funclib.h"

long **clustering(QImage *image,long n,long clusteringTimes){
	const long h=image->height(),w=image->width();
	long x,y,z,t;
	myRGB *centerPoint=new myRGB[n];
	long **arr=new long*[h];
	for(x=0;x<h;x++){
		arr[x]=new long[w];
	}
	for(x=0;x<n;x++)
		centerPoint[x].randomize();
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			long mindist=999999999,tmp;
			for(z=0;z<n;z++){
				tmp=centerPoint[z].distance(image->pixel(x,y));
				if(tmp<mindist){
					mindist=tmp;
					arr[y][x]=z;
				}
			}
		}
	}
	long *counter=new long[n];
	for(t=0;t<clusteringTimes;t++){
		for(z=0;z<n;z++){ centerPoint[z].clear(); counter[z]=0; }
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter[arr[y][x]]++;
				centerPoint[arr[y][x]]+=image->pixel(x,y);
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
						arr[y][x]=z;
					}
				}
			}
		}
	}
	delete [] centerPoint;
	delete [] counter;
	return arr;
}

QImage * transform(QImage *image,double zoom){
	long x,y,i,j,w=(long)(image->width()/zoom),h=(long)(image->height()/zoom);
	QImage *displayImage=new QImage(w,h,QImage::Format::Format_ARGB32);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			long b=(long)(x*zoom),c=(long)(y*zoom);
			myRGB sum; long area=0;
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

void gray(QImage *image){
	long x,y,w=image->width(),h=image->height();
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			int avg=myRGB::toGray(image->pixel(x,y));
			image->setPixel(x,y,qRgb(avg,avg,avg));
		}
	}
}

QImage *edgeDetection(QImage * image){
	long **arr=clustering(image,50);
	long x,y,z,h=image->height(),w=image->width(),xx,yy; 
	QImage * res=new QImage(w,h,QImage::Format::Format_RGB32);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			res->setPixel(x,y,qRgb(0,0,0));
			for(z=0;z<4;z++){
				xx=x; yy=y;
				switch(z){
				case 0:
					xx--;
					if(xx<0) xx=w-1;
					break;
				case 1:
					xx++;
					if(xx==w) xx=0;
					break;
				case 2:
					yy--;
					if(yy<0) yy=h-1;
					break;
				case 3:
					yy++;
					if(yy==h) yy=0;
					break;
				}
				if(arr[y][x]!=arr[yy][xx]){
					res->setPixel(x,y,qRgb(255,255,255));
					break;
				}
			}
		}
	}
	return res;
}