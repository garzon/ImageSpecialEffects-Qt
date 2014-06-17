#ifndef FUNCLIB_H
#define FUNCLIB_H

#include "myRGB.h"
#include <qimage.h>
#include <cmath>

#define PI 3.14159265

template <typename T>
class D2Array;

template <typename T>
T inline imax(T a,T b){
	if(a>b) return a; else return b;
}

template <typename T>
T inline imin(T a,T b){
	if(a<b) return a; else return b;
}

D2Array<long> * clustering(const D2Array<double> *image,long clusterNum,long clusterTimes);
D2Array<long> * clustering(const QImage *image,long clusterNum,long clusterTimes);

D2Array<double> * noLightness(const QImage * image);

QImage * transform(const QImage *image,double zoom);

int toGray(const QRgb &c);
QImage * gray(const QImage *image);

QString * image2Text(QImage *image,QString *chars);

QImage *edgeDetection(const QImage * image,long clusterNum,long clusterTimes);

void getNeighborByDir(long dir,long &x,long &y,long maxx,long maxy);

#endif