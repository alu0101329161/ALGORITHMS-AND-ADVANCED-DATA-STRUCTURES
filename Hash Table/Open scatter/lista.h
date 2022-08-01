

#pragma once
#include <cstddef>
#include <vector>
#include <iomanip>
#include <iostream>
template<class Clave>
class lista
{
        
    public:
    
        lista();
        lista(int size);
        ~lista();

        bool buscar(Clave& x);
        bool insertar(Clave& x);
        void resize(int size);
        void push(int valor);
        void limpiar();

        void mostrar();
    
    private:
    
        std::vector<Clave> vec_list;
        int nClaves;
};


template<class Clave>
lista<Clave>::lista() {
    nClaves = 0;
}


template<class Clave>
lista<Clave>::lista(int size){
    nClaves = size;
 
    vec_list.resize(nClaves);
    
    for(int recorrido = 0; recorrido <= vec_list.size(); recorrido++)
        vec_list[recorrido] = 0;
}


template<class Clave>
lista<Clave>::~lista()
{
    vec_list.clear();
}


template<class Clave>
void lista<Clave>::resize(int size) {

    vec_list.resize(size);

}


template<class Clave>
bool lista<Clave>::buscar(Clave& x)
{
    for(unsigned recorrido = 0; recorrido < vec_list.size(); recorrido++)
    { 
        if(x == vec_list[recorrido])
            return true;
    }
    return false;
}


template<class Clave>
bool lista<Clave>::insertar(Clave& x)
{
    if(Buscar(x))
        return false;
         

    return true;
}


template<class Clave>
void lista<Clave>::push(int valor) {

    vec_list.push_back(valor);
}


template<class Clave>
void lista<Clave>::limpiar() {

    for(unsigned recorrido = 0; recorrido < vec_list.size();recorrido++)
        vec_list[recorrido] = 0;
}


template<class Clave>
void lista<Clave>::mostrar() {
        for (unsigned recorrido=0; recorrido<vec_list.size(); recorrido++)
            std::cout << std::fixed << std::setw(9)<<vec_list[recorrido]<< "  ";
        std::cout << std::endl;
}