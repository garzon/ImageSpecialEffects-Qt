#ifndef FUNCLIB_H
#define FUNCLIB_H

template <typename T>
T inline imax(T a,T b){
	if(a>b) return a; else return b;
}

template <typename T>
T inline imin(T a,T b){
	if(a<b) return a; else return b;
}

#endif