#ifndef MYRGB_H
#define MYRGB_H

#include <qrgb.h>
#include <qimage.h>

template <typename T=long long>
class myRGB{
public:
	T r,g,b;
	myRGB(){
		r=0;g=0;b=0;
	}
	myRGB(int rr,int gg,int bb):r(rr),g(gg),b(bb){}
	myRGB(const QRgb & tmp){
		r=qRed(tmp); 
		g=qGreen(tmp);
		b=qBlue(tmp);
	}
	void randomize(){}
	void clear(){
		r=g=b=0;
	}
	long distance(const QRgb &c){
		long res=0;
		res+=(r-qRed(c))*(r-qRed(c));
		res+=(g-qGreen(c))*(g-qGreen(c));
		res+=(b-qBlue(c))*(b-qBlue(c));
		return res;
	}
	T distance(const myRGB<T> &c){
		T res=0;
		res+=(r-c.r)*(r-c.r);
		res+=(g-c.g)*(g-c.g);
		res+=(b-c.b)*(b-c.b);
		return res;
	}
	myRGB<T>& operator +=(const QRgb & tmp){
		r+=qRed(tmp); 
		g+=qGreen(tmp);
		b+=qBlue(tmp);
		return *this;
	}
	myRGB<T>& operator +=(const myRGB<T> & tmp){
		r+=tmp.r;
		g+=tmp.g;
		b+=tmp.b;
		return *this;
	}
	myRGB<T>& operator +=(const double & tmp){
		r=(T)(r+tmp);
		g=(T)(g+tmp);
		b=(T)(b+tmp);
		return *this;
	}
	myRGB<T>& operator -=(const myRGB<T> & tmp){
		r-=tmp.r;
		g-=tmp.g;
		b-=tmp.b;
		return *this;
	}
	myRGB<T>& operator -=(const double & tmp){
		r=(T)(r-tmp);
		g=(T)(g-tmp);
		b=(T)(b-tmp);
		return *this;
	}
	myRGB<T>& operator *=(const double & tmp){
		r=(T)(r*tmp);
		g=(T)(g*tmp);
		b=(T)(b*tmp);
		return *this;
	}
	myRGB<T>& operator /=(T area){
		r/=area; g/=area; b/=area;
		return *this;
	}
	void trim(){
		_trim(r); _trim(g); _trim(b);
	}
	void vmul(double rr,double gg,double bb){
		r=(T)(rr*r);
		g=(T)(gg*g);
		b=(T)(bb*b);
	}
	QRgb toQRGB(){
		trim();
		return qRgb(long(r),long(g),long(b));
	}
	T sum() const{
		return (r+g+b);
	}
	T toGray() const{
		myRGB tmp(*this);
		tmp.vmul(0.3,0.59,0.11);
		return tmp.sum();
	}
	void toLab(long &L,long &a,long &b) const{
		// from http://hao.qinz.net/comments.php?y=08&m=07&entry=entry080727-033517
		L = (13933 * r + 46871 * g + 4732 * b) >> 16;
		a = 377 * (14503 * r - 22218 * g + 7714 * b) >> 24 + 128
		b = 160 * (12773 * r + 39695 * g - 52468 * b) >> 24 + 128
	}
private:
	void _trim(T &v){
		if(v>255) v=255;
		if(v<0)   v=0;
	}
};

template <>
void myRGB<long long>::randomize(){
	r=rand()%256;
	g=rand()%256;
	b=rand()%256;
}

template <>
void myRGB<double>::randomize(){
	double res=(rand()%6000)*1.0/1000-3;
	r=res; res=(rand()%6000)*1.0/1000-3;
	g=res; res=(rand()%6000)*1.0/1000-3;
	b=res;
}

template <typename T>
class D2Array{
public:
	T **p; long row,col;
	D2Array(long _row,long _col):row(_row),col(_col){
		long y;
		p=new T* [row];
		for(y=0;y<row;y++){
			p[y]=new T [col];
		}
	}
	~D2Array(){
		long y;
		for(y=0;y<row;y++){
			delete [] p[y];
		}
		delete [] p;
	}
	T * operator [](long y){
		return p[y];
	}
};

template <typename T>
class myRGBImage:public D2Array<myRGB<T> >{
public:
	long h,w;
	myRGBImage(long _h,long _w):h(_h),w(_w),D2Array<myRGB<T> >(_h,_w){}
	myRGBImage(const QImage *image):h(image->height()),w(image->width()),D2Array<myRGB<T> >(image->height(),image->width()){
		long x,y;
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				p[y][x]=image->pixel(x,y);
			}
		}
	}
	myRGB<T> pixel(long x,long y) const{
		return p[y][x];
	}
	void setPixel(long x,long y,const myRGB<T> &pix){
		p[y][x]=pix;
	}
	long height() const { return h; }
	long width()  const { return w; }
};


#endif