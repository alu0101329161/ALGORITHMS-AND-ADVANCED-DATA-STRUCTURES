

#pragma once

#include "lista.h"
#include "fdispersion.h"
#include <iostream>
template<class Clave>
class tablaHash
{
        
    public:
    
        tablaHash(int numceldas, int t_d);
        ~tablaHash();
        
        // No modifica la tabla
        bool buscar(Clave& x) ;

        // Modifica la tabla
        bool insertar( Clave& x);

        void mostrar();
        void push(int valor);

    private:
        // Tamaño de la tabla de hash
        unsigned int nCeldas; 

        // Tipo de dispersion
        unsigned int disp_type;
        
        std::vector <lista<Clave>> vDatos;
        FuncionDispersion<Clave> * fd;

};

template<class Clave>
tablaHash<Clave>::tablaHash(int nceldas, int t_d) {

    nCeldas = nceldas;
    disp_type = t_d;

    vDatos.resize(nCeldas);


    switch(disp_type)
    {
        case 0:
             
         fd = new fdModulo<Clave>(nCeldas); 

        break;

        case 1:
         
         fd = new fdAleatoria<Clave>(nCeldas);
 
        break;
    }
}


template<class Clave>
tablaHash<Clave>::~tablaHash(){}


template<class Clave>
bool tablaHash<Clave>::insertar( Clave& x) {

    if(buscar(x))      
     return false;

    return true;

}

template<class Clave>
bool tablaHash<Clave>::buscar(Clave& x) {
    

    if(vDatos[fd->operator()(x)].buscar(x))           
        return true;

    return false;
}

template<class Clave>
void tablaHash<Clave>::push(int valor) {

    vDatos[fd->operator()(valor)].push(valor);

}

template<class Clave>
void tablaHash<Clave>::mostrar()  {
    for(unsigned recorrido = 0; recorrido < vDatos.size() ; recorrido ++)
        vDatos[recorrido].mostrar();
    std::cout << std::endl;
}





