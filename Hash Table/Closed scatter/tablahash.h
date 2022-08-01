

#pragma once

#include "lista.h"
#include "fexploracion.h"

#include <iostream>
template<class Clave>
class tablaHash
{
        
    public:
    
        tablaHash(int numceldas, int numbloques, int t_d, int t_e);
        ~tablaHash();
        
        // No modifica la tabla
        bool buscar(Clave& x) ;

        // Modifica la tabla
        bool insertar( Clave& x);

        void mostrar();
        void push(int valor);
        int mostrarcolisiones();
        void reset_count();

    private:
        // Tamaño de la tabla de hash
        unsigned int nCeldas; 
        
        // Tamaño de los vectores
        unsigned int nSinonimos;

        // Tipo de dispersion
        unsigned int disp_type;

        // Tipo de exploracíon
        unsigned int exp_type;

        unsigned int contador;
        
        std::vector <lista<Clave>> vDatos;
        FuncionDispersion<Clave> * fd;
        FuncionExploracion<Clave> * fe;

};

template<class Clave>
tablaHash<Clave>::tablaHash(int nceldas, int numbloques, int t_d, int t_e) {

    nCeldas = nceldas;
    nSinonimos = numbloques;
    disp_type = t_d;
    exp_type = t_e;
    contador = 0;


    vDatos.resize(nCeldas);

     for(unsigned recorrido = 0; recorrido < nCeldas; recorrido++) {
        vDatos[recorrido].resize(nSinonimos);
        vDatos[recorrido].limpiar();
    }


    switch(disp_type)
    {
        case 0:
             
         fd = new fdModulo<Clave>(nCeldas); 

        break;

        case 1:
         
         fd = new fdAleatoria<Clave>(nCeldas);
 
        break;
    }


    switch(exp_type)
    {
        case 0:
             
         fe = new feLineal<Clave>(nCeldas); 

        break;

        case 1:
         
         fe = new feCuadratica<Clave>(nCeldas);
 
        break;


        case 2:
         
         fe = new feDoble<Clave>(fd);
 
        break;


        case 3:
         
         fe = new feRedispersion<Clave>(nCeldas);
 
        break;
    }
}


template<class Clave>
tablaHash<Clave>::~tablaHash(){
    fd = NULL;
    fe = NULL;
}

template<class Clave>
void tablaHash<Clave>::reset_count() {
    contador = 0;
}


template<class Clave>
bool tablaHash<Clave>::insertar( Clave& x) {
    unsigned int pos = fd->operator()(x);
    unsigned int desp;
    contador = 1;

    if(vDatos[pos].insertar(x))
    return true;
    if(!vDatos[pos].full())
    return false;

    while(contador < nCeldas) {
        desp = fe->operator()(x, pos);

        if(vDatos[(pos + desp) % nCeldas].insertar(x))
        return true;
        if(!vDatos[(pos + desp) % nCeldas].full())
        return true;

        pos++;
        if(pos >= nCeldas)
            pos = 0;
        contador++;

    }
    return false;
}

template<class Clave>
bool tablaHash<Clave>::buscar(Clave& x) {

    unsigned int pos = fd->operator()(x);
    unsigned int desp;
    contador = 1;

    if(vDatos[pos].buscar(x))
    return true;
    if(!vDatos[pos].full())
    return false;

    while(contador < nCeldas) {
        desp = fe->operator()(x, pos);

        if(vDatos[(pos + desp) % nCeldas].buscar(x))
        return true;
        if(!vDatos[(pos + desp) % nCeldas].full())
        return true;

        pos ++;
        if(pos >= nCeldas)
            pos = 0;
        contador++;

    }
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

template<class Clave>
int tablaHash<Clave>::mostrarcolisiones()  {
    std::vector< int > aux;
    for(unsigned recorrido = 0; recorrido < vDatos.size() ; recorrido ++)
        aux.push_back(vDatos[recorrido].mostrarcolisiones());

    int mayor = aux[0];
    for(unsigned recorrido = 0; recorrido < aux.size() ; recorrido ++) {
        if(aux[recorrido] > mayor)
        {
             mayor = aux[recorrido];

        }
    }
    aux.clear();
    return mayor;

}




