#ifndef FUNCLIB_H
#define FUNCLIB_H

#include "myRGB.h"
#include <qimage.h>

template <typename T>
T inline imax(T a,T b){
	if(a>b) return a; else return b;
}

template <typename T>
T inline imin(T a,T b){
	if(a<b) return a; else return b;
}

long **clustering(QImage *image,long n,long clusteringTimes=50);

QImage * transform(QImage *image,double zoom);

void gray(QImage *image);

QImage *edgeDetection(QImage * image);

#endif