

#pragma once

#include <cstdio>
#include <cstdlib>
#include "fdispersion.h"


template<class Clave>
class FuncionExploracion {

    public:

    virtual unsigned operator()(const Clave& k, unsigned i) const = 0;
};

//////////////////////////////////////////////////////lineal


template<class Clave>
class feLineal: public FuncionExploracion<Clave> {

    private:

    int nSinonimos_;

    public:

    feLineal (int nSinonimos) {

        nSinonimos_ = nSinonimos;
    }

    unsigned operator()(const Clave& x, unsigned i) const {
        return i;
    }
};

//////////////////////////////////////////////////////Cuadratica


template <class Clave>
class feCuadratica : public FuncionExploracion<Clave> {
    
    private:

    int nSinonimos_;
    
    public:

    feCuadratica (int nSinonimos){
        nSinonimos_ = nSinonimos;;
    }

    unsigned operator()(const Clave& x, unsigned i) const {

        return (i * i);
    }
};

//////////////////////////////////////////////////////doble


template <class Clave>
class feDoble : public FuncionExploracion<Clave> {
    
    private:
    FuncionDispersion<unsigned>* fd_;
    
    public:

    feDoble (FuncionDispersion <unsigned>* fd) {
        fd_ = fd;
    }

    unsigned operator()(const Clave& x, unsigned i) const {
        return ((i) * (fd_->operator()(x)));
    }
};


//////////////////////////////////////////////////////redispersion


template <class Clave>
class feRedispersion : public FuncionExploracion<Clave> {
    
    private:

    int nSinonimos_;
    
    public:

    feRedispersion (int nSinonimos){
        nSinonimos_ = nSinonimos;;
    }
    
    unsigned operator()(const Clave& x, unsigned i) const {
        srand(x);
        unsigned aux;
        for(unsigned recorrido = 0; recorrido < i; recorrido ++) {
            aux = rand() % nSinonimos_;
        }
    return aux;
    }
};