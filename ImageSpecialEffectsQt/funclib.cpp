#include "funclib.h"

#define DEFAULTVAR long x,y,w=image->width(),h=image->height();
#define NEWIMAGE QImage *myImage=new QImage(w,h,QImage::Format::Format_RGB32);
#define DEFAULTLOOP for(y=0;y<h;y++) for(x=0;x<w;x++)

QRgb averageColor(const QImage *image){
	DEFAULTVAR;
	myRGB<> res;
	DEFAULTLOOP{
			res+=image->pixel(x,y);
	}
	res/=(h*w);
	return res.toQRGB();
}

QImage * lab(const QImage *image){
	DEFAULTVAR;
	NEWIMAGE;
	DEFAULTLOOP{
		myRGB<> tmp(image->pixel(x,y));
		long l,a,b;
		rgb2lab(tmp,l,a,b);
		l=l*255/100;
		a+=128;
		b+=128;
		myImage->setPixel(x,y,qRgb(l,a,b));
	}
	return myImage;
}

QImage *averageImage(const QImage *image1,const QImage *image2){
	long x,y,w=image1->width(),h=image1->height();
	Q_ASSERT(image2->height()==h);
	Q_ASSERT(image2->width()==w);
	NEWIMAGE;
	DEFAULTLOOP{
		myRGB<> tmp(image1->pixel(x,y));
		tmp+=image2->pixel(x,y);
		tmp/=2;
		myImage->setPixel(x,y,tmp.toQRGB());
	}
	return myImage;
}

QImage *salience(const QImage *image){
	DEFAULTVAR;
	QRgb avg=averageColor(image);
	NEWIMAGE;
	DEFAULTLOOP{
		long gray=long(myRGB<>(image->pixel(x,y)).distance(avg)/(255));
		myImage->setPixel(x,y,qRgb(gray,gray,gray));
	}
	return myImage;
}

bool getNeighborByDir(long dir,long &x,long &y,long maxx,long maxy){
	switch(dir){
		case 0:
			x--;
			if(x<0) return false;
			break;
		case 1:
			x++;
			if(x==maxx) return false;
			break;
		case 2:
			x--;
			if(x<0) return false;
			break;
		case 3:
			x++;
			if(x==maxx) return false;
			break;
		case 6:
			x--;
			if(x<0) return false;
			break;
		case 7:
			x++;
			if(x==maxx) return false;
			break;
	}
	switch(dir){
		case 0:
			y--;
			if(y<0) return false;
			break;
		case 1:
			y--;
			if(y<0) return false;
			break;
		case 6:
			y++;
			if(y==maxy) return false;
			break;
		case 4:
			y--;
			if(y<0) return false;
			break;
		case 5:
			y++;
			if(y==maxy) return false;
			break;
		case 7:
			y++;
			if(y==maxy) return false;
			break;
	}
	return true;
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

QImage * gray(const QImage *image){
	DEFAULTVAR;
	NEWIMAGE;
	DEFAULTLOOP{
			int avg=toGray(image->pixel(x,y));
			myImage->setPixel(x,y,qRgb(avg,avg,avg));
	}
	return myImage;
}

QImage *binarize(const QImage *image){
	DEFAULTVAR;
	NEWIMAGE;
	DEFAULTLOOP{
			int avg=toGray(image->pixel(x,y));
			if(avg>=128) avg=255; else avg=0;
			myImage->setPixel(x,y,qRgb(avg,avg,avg));
	}
	return myImage;
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
				if(getNeighborByDir(z,xx,yy,w,h)){
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
	//for(t=0;t<10;t++){
		tmp=res;
		res=new QImage(w,h,QImage::Format::Format_RGB32); 
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter=0; self=tmp->pixel(x,y);
				if(qRed(self)==255)
				for(z=0;z<8;z++){
					xx=x; yy=y;
					if(getNeighborByDir(z,xx,yy,w,h)){
						if(tmp->pixel(xx,yy)!=self){
							counter++;
						}
					}
				}
				flag=qRed(self);
				if(counter>4) flag=256-flag;
				res->setPixel(x,y,qRgb(flag,flag,flag));
			}
		}
		delete tmp;
	//}
	return res;
}

QImage *edgeDetection(const QImage * image,long clusterNum,long clusterTimes){
	long x,y,z,h=image->height(),w=image->width(),xx,yy,counter;
	//image=noLightnessRGB(image);
	QImage * res=new QImage(w,h,QImage::Format::Format_RGB32);
	//QImage * myImage=noLightnessRGB(image);
	//QImage * myImage=salience(image);
	const QImage * myImage=image;
	D2Array<long> *arr=clustering(myImage,clusterNum,clusterTimes);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			res->setPixel(x,y,qRgb(0,0,0));
			counter=0; double dis=0;
			myRGB<> self((*myImage).pixel(x,y));
			for(z=0;z<4;z++){
				xx=x; yy=y;
				if(getNeighborByDir(z,xx,yy,w,h))
				if((*arr)[y][x]!=(*arr)[yy][xx]){
					dis+=self.distance((*myImage).pixel(xx,yy));
					counter++;
				}
			}
			if(counter!=0){
				dis/=counter;
				if(dis>75){ //3.3
					res->setPixel(x,y,qRgb(255,255,255));
				}
			}
		}
	}
	//delete image;
	//delete myImage;
	delete arr;
	return res;
}

// formulas below from https://github.com/THEjoezack/ColorMine 

void rgb2xyz(myRGB<> color,double &X,double &Y,double &Z){
	static const auto PivotRgb=[](double n)->double{
		return (n > 0.04045 ? pow((n + 0.055) / 1.055, 2.4) : n / 12.92) * 100.0;
	};
	double r = PivotRgb(color.r / 255.0);
	double g = PivotRgb(color.g / 255.0);
	double b = PivotRgb(color.b / 255.0);
	// Observer. = 2бу, Illuminant = D65
	X = r * 0.4124 + g * 0.3576 + b * 0.1805;
	Y = r * 0.2126 + g * 0.7152 + b * 0.0722;
	Z = r * 0.0193 + g * 0.1192 + b * 0.9505;
}

QRgb xyz2rgb(double X,double Y,double Z){
	// (Observer = 2бу, Illuminant = D65)
	double x=X/100.0;
	double y=Y/100.0;
	double z=Z/100.0;
	double r = x * 3.2406 + y * -1.5372 + z * -0.4986;
	double g = x * -0.9689 + y * 1.8758 + z * 0.0415;
	double b = x * 0.0557 + y * -0.2040 + z * 1.0570;
	r = r > 0.0031308 ? 1.055 * pow(r, 1 / 2.4) - 0.055 : 12.92 * r;
	g = g > 0.0031308 ? 1.055 * pow(g, 1 / 2.4) - 0.055 : 12.92 * g;
	b = b > 0.0031308 ? 1.055 * pow(b, 1 / 2.4) - 0.055 : 12.92 * b;
	return myRGB<>(r,g,b).toQRGB();
}

void rgb2lab(myRGB<> color,long &l,long &a,long &b){
	double x,y,z;
	rgb2xyz(color,x,y,z);
	static const auto PivotXyz=[](double n)->double{
		if(n*24389>216) return pow(n,1.0/3.0);
		return (24389*n/27+16)/116;
	};
	x = PivotXyz(x/95.047);
	y = PivotXyz(y/100.000);
    z = PivotXyz(z/108.883);
	l = qRound(116*y-16); if(l<0) l=0;
    a = qRound(500 * (x - y));
    b = qRound(200 * (y - z));
}

void rgb2lab(QRgb color,long &l,long &a,long &b){
	return rgb2lab(myRGB<>(color),l,a,b);
}