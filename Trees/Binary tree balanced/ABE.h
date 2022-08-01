



#pragma once

#include "nodoAB.h"
#include "queue_l_t.h"
#include <queue>


extern bool value;

template <class T>
class ABE {

    public:

    ABE();
    ABE(nodoAB<T>* raiz);
    ~ABE();

    // Asegurar que se empieza por la raiz
    const int Tam() { return TamRama(raiz_); }
    const bool Equilibrado() { return EquilibrioRama(raiz_); }
    void InsertaEquil(const T& dato) {
        if (raiz_ == NULL) raiz_ = new nodoAB<T>(dato, NULL, NULL);
        else InsertaEquilRama(dato, raiz_);}
    void Buscar(T& dato) { return BuscarRama(raiz_, dato); }


    void Podar (nodoAB<T>* &nodo);
    bool EsVacio(nodoAB<T>* nodo);
    bool EsHoja(nodoAB<T>* *nodo);

    void RecorridoN(void);
    void MostrarRecorrido(void);

    private:

    // Metodos que llaman a los público
    void Preorden( nodoAB<T> *nodo );
    void Inorden( nodoAB<T> *nodo );
    void Postorden( nodoAB<T> *nodo );
    const int TamRama(nodoAB<T>* nodo);
    const bool EquilibrioRama(nodoAB<T> *nodo);
    void BuscarRama (nodoAB<T>* nodo, T dato);    
    void InsertaEquilRama(const T dato, nodoAB<T>* nodo);

    nodoAB<T> *raiz_;
};


// Constructor por defecto
template <class T>
ABE<T>::ABE() {
    raiz_ = NULL;
}


// Constructor
template <class T>
ABE<T>::ABE(nodoAB<T>* raiz) {
    raiz_ = raiz;
}


// Destructor primero izq y luego dch
template <class T>
ABE<T>::~ABE() {
    Podar(raiz_);
}


// Elimina rama
template <class T> 
void
ABE<T>::Podar (nodoAB<T>* &nodo) {

    if (nodo != NULL) {  
        Podar(nodo->izq_);
        Podar(nodo->dch_);  
        delete nodo; 
        nodo = NULL;
    }
}

template<class T>
bool 
ABE<T>::EsVacio(nodoAB<T>* nodo) {
    return nodo == NULL;
}


template<class T>
bool 
ABE<T>::EsHoja(nodoAB<T>* *nodo) {
    return !nodo->dcho && !nodo->izdo;
}


// Tamaño del arbol = n de nodos
template <class T>
const int 
ABE<T>::TamRama(nodoAB<T>* nodo) {

    if (nodo == NULL) return 0 ;
        // nodos lado dch mas izquierdo
        return (1 + TamRama(nodo->izq_) + TamRama(nodo->dch_) );
}

template <class T>
void
ABE<T>::Preorden( nodoAB<T> *nodo ) {

    if (nodo == NULL) return;
    std::cout<< nodo->dato_;
    Preorden(nodo->izq_);
    Preorden(nodo->dch_);
}


template <class T>
void
ABE<T>::Inorden( nodoAB<T> *nodo ) {

    if (nodo == NULL) return;
    Inorden(nodo->izq_);
    std::cout<< nodo->dato_;
    Inorden(nodo->dch_);
}


template <class T>
void
ABE<T>::Postorden( nodoAB<T> *nodo ) {

    if (nodo == NULL) return;
    Postorden(nodo->izq_);
    Postorden(nodo->dch_);
    std::cout<< nodo->dato_;
}


template <class T> 
void 
ABE<T>::MostrarRecorrido() {

    Preorden(raiz_);

}


// Comprobar que esta equilibrado
template <class T>
const bool 
ABE<T>::EquilibrioRama(nodoAB<T> *nodo) {

    if (nodo == NULL) return true ;
    // La diferencia entre nodos es como mucho 1
    int eq = TamRama(nodo->izq_) - TamRama(nodo->dch_);
    switch (eq) {
        case -1:
        case 0:
        case 1:
            // Si todo esta equilibrado retorna true
            return EquilibrioRama(nodo->izq_) && EquilibrioRama(nodo->dch_);
        default: return false;
    }
}


// Busca dato en la rama
template <class T> 
void
ABE<T>::BuscarRama (nodoAB<T>* nodo, T dato) {

    queue_l_t<std::pair <nodoAB<T> *, int>> cola;
    int nivel {0}, nivel_actual {0};           
    cola.push(std::make_pair(raiz_, 0)); 
    // Mientras la cola no esté vacía...
    while (!cola.empty()) {
        nodo = cola.front().first;
        nivel = cola.front().second;
        cola.pop();
        // Si el nivel extraído es mayor que el nivel actual, se aumenta el nivel actual
        if (nivel > nivel_actual) 
            nivel_actual = nivel;
        if(nodo != NULL) {
        std::cout<<"Nodo a comprobar: "<< nodo->dato_<<" Nivel: "<<nivel_actual<<std::endl;
            if(nodo -> dato_ == dato) {
                value = true;
                return;
            }
        }
        if (nodo != NULL) {
            cola.push(std::make_pair(nodo->izq_, nivel+1));
            cola.push(std::make_pair(nodo->dch_, nivel+1));
        }
    }
}


// Insertar equilibrado
template <class T> 
void 
ABE<T>::InsertaEquilRama(const T dato, nodoAB<T>* nodo) {

    // nodo izquiero
    if (TamRama(nodo->izq_) <= TamRama(nodo->dch_)) {
        if (nodo->izq_ != NULL)
            InsertaEquilRama(dato, nodo->izq_);
        else
            nodo->izq_ = new nodoAB<T>(dato, NULL, NULL);
    }
    // nodo derecho
    else {
        if (nodo->dch_ != NULL)
            InsertaEquilRama(dato, nodo->dch_);
        else
            nodo->dch_ = new nodoAB<T>(dato, NULL, NULL);
    }
}



template <class T> 
void 
ABE<T>::RecorridoN() {

    queue_l_t<std::pair <nodoAB<T> *, int>> cola;
    
    nodoAB<T>* nodo;                  // Nodo auxiliar
    int nivel {0}, nivel_actual {0};            // Nivel auxiliar

    cola.push(std::make_pair(raiz_, 0));  // Se inserta el primer nodo y nivel (nodo raíz y nivel 0)
    std::cout << "Nivel 0: ";
    // Mientras la cola no esté vacía...
    while (!cola.empty()) {
        nodo = cola.front().first;
        nivel = cola.front().second;
        cola.pop();
        // Si el nivel extraído es mayor que el nivel actual, se aumenta el nivel actual
        if (nivel > nivel_actual) {
            nivel_actual = nivel;
            std::cout << "\nNivel " << nivel_actual << ": ";
        }
        if (nodo != NULL) std::cout << "[" << nodo->dato_ << "]";
        else std::cout << "[.]";
        
        // Si el nodo extraído no está vacío, se insertan sus dos hijos en la cola
        if (nodo != NULL) {
            cola.push(std::make_pair(nodo->izq_, nivel+1));
            cola.push(std::make_pair(nodo->dch_, nivel+1));
        }
    }
}