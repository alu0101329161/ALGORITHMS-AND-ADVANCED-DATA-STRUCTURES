


#pragma once

#include <cstdio>
#include <cstdlib>

template<class Clave>
class FuncionDispersion
{
    public:
        // Metodo que retorna valor entre 0 y nDatos-1
        virtual unsigned operator()(const Clave& x) = 0;

};

//////////////////////////////////////////////////////Modulo

template<class Clave>
class fdModulo: public FuncionDispersion<Clave> {
    public:

        fdModulo(int size);
        ~fdModulo();
        
        unsigned operator()(const Clave& x);

    private:

        unsigned nDatos_;

};

template<class Clave>
fdModulo<Clave>::fdModulo(int size) {
    nDatos_ = size;

}


template<class Clave>
unsigned fdModulo<Clave>::operator()(const Clave& x) {
     return  x % nDatos_;
}

//////////////////////////////////////////////////////Aleatoria

template<class Clave> 
class fdAleatoria: public FuncionDispersion<Clave> {

    public:

        fdAleatoria(int size);
        ~fdAleatoria();

        unsigned operator()(const Clave& x);

    private:

        int nDatos_;
};

template<class Clave>
fdAleatoria<Clave>::fdAleatoria(int size) {

    nDatos_ = size;
}

template<class Clave>
unsigned fdAleatoria<Clave>::operator()(const Clave& x) {
    
    srand(x);
    return (rand() % nDatos_);
}

//////////////////////////////////////////////////////Suma

template<class Clave> 
class fdSuma: public FuncionDispersion<Clave> {

    public:

        fdSuma(int size);
        ~fdSuma();

        unsigned operator()(const Clave& x);

    private:

        int nDatos_;
};

template<class Clave>
fdSuma<Clave>::fdSuma(int size) {

    nDatos_ = size;
}

template<class Clave>
unsigned fdSuma<Clave>::operator()(const Clave& x) {
    
    int d = 0;
    int y = 0;
    while (x > 0){

        y = x % 10;
        d = d + y;
        x = x / 10;

    }
    return (d % nDatos_);
}