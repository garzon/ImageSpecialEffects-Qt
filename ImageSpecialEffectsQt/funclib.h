#ifndef FUNCLIB_H
#define FUNCLIB_H

#include "myRGB.h"
#include <qimage.h>
#include <cmath>
#include <functional>


template <typename T>
T inline imax(T a,T b){
	if(a>b) return a; else return b;
}

template <typename T>
T inline imin(T a,T b){
	if(a<b) return a; else return b;
}

template <typename T>
T *caller(T* (*f)(const T*),T *a){
	T *b=f(a);
	delete [] a;
	return b;
}

void getNeighborByDir(long dir,long &x,long &y,long maxx,long maxy);
inline bool isNeighbor(long x,long y,long xx,long yy);

QRgb averageColor(const QImage *image);

//D2Array<long> * clustering(const D2Array<double> *image,long clusterNum,long clusterTimes);
D2Array<long> * clustering(const QImage *image,long clusterNum,long clusterTimes);

QImage * noLightnessRGB(const QImage * image);
//D2Array<double> * noLightnessGray(const QImage * image);

QImage * transform(const QImage *image,double zoom);

int toGray(const QRgb &c);
QImage * gray(const QImage *image);
QImage * binarize(const QImage *image);

QImage *salience(const QImage *image); 

QString * image2Text(const QImage *image,QString *chars);

QImage *noiseReduce(const QImage *image);
//QImage *noiseReduce2(const QImage *image);

QImage *edgeSmoothing(const QImage * image);

QImage *edgeDetection(const QImage * image,long clusterNum=10,long clusterTimes=100);

#endif