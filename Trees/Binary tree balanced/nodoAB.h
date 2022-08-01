



#pragma once
#include <cstdio>


template <class T>
class nodoAB {

    public:

    nodoAB();
    nodoAB(const T , nodoAB<T> *izq=NULL, nodoAB<T> *dch=NULL);
    ~nodoAB();
    
    void set_dato (T dato);

    T dato_;  
    nodoAB<T> *izq_;  
    nodoAB<T> *dch_;

};


template <class T>
nodoAB<T>::nodoAB() {
    izq_ = NULL;
    dch_ = NULL;
}


template <class T>
nodoAB<T>::nodoAB (const T dato, nodoAB<T> *izq, nodoAB<T> *dch){
    dato_ = dato;
    izq_ = izq;
    dch_ = dch;
}


template <class T>
nodoAB<T>::~nodoAB() {
    delete izq_;
    delete dch_;
    dch_ = NULL;
    izq_ = NULL;
}

template <class T>
void 
nodoAB<T>::set_dato (T dato){
    dato_ = dato;
}
