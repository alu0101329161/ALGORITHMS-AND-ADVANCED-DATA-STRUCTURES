



#pragma once
#include <cstdio>


template <class T>
class nodoABB {

    public:

    nodoABB();
    nodoABB(const T ,const T, nodoABB<T> *izq=NULL, nodoABB<T> *dch=NULL);
    ~nodoABB();

    T dato_;  
    T clave_;
    T balanceo_;
    nodoABB<T> *izq_;  
    nodoABB<T> *dch_;

};


template <class T>
nodoABB<T>::nodoABB() {
    izq_ = NULL;
    dch_ = NULL;
}


template <class T>
nodoABB<T>::nodoABB (const T dato, const T clave, nodoABB<T> *izq, nodoABB<T> *dch) {
    dato_ = dato;
    clave_ = clave;
    izq_ = izq;
    dch_ = dch;
}


template <class T>
nodoABB<T>::~nodoABB() {
    delete izq_;
    delete dch_;
    dch_ = NULL;
    izq_ = NULL;
}