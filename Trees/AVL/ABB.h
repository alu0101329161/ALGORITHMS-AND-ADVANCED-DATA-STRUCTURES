



#pragma once

#include "nodoABB.h"
#include "queue_l_t.h"

extern bool value;

template <class T>
class ABB {

    public:

    ABB();
    ABB(nodoABB<T>* raiz);
    ~ABB();

    // Asegurar que se empieza por la raiz
    const int Tam() { return TamRama(raiz_); }

    
    void Buscar(T& clave) { BuscarRama(raiz_, clave); }
    virtual void Insertar(const T& clave) { InsertarRama(raiz_, clave); }
    virtual void Eliminar(T& clave) { EliminarRama(raiz_, clave); }

    void RecorridoN(void);
    void MostrarRecorrido(void);

    protected:

    // Meotodos que llaman a los público
    void Podar (nodoABB<T>* &nodo);
    bool EsVacio(nodoABB<T>* nodo);
    bool EsHoja(nodoABB<T>* *nodo);
    void Preorden( nodoABB<T> *nodo );
    void Inorden( nodoABB<T> *nodo );
    void Postorden( nodoABB<T> *nodo );
    const int TamRama(nodoABB<T>* nodo);
    nodoABB<T>* BuscarRama (nodoABB<T>* nodo, T clave);
    virtual void Sustituir (nodoABB<T>* &eliminar, nodoABB<T>* &sust);
    virtual void EliminarRama (nodoABB<T>* &nodo, T clave);    
    virtual void InsertarRama (nodoABB<T>* &nodo, T clave_dada);    

    nodoABB<T> *raiz_;
};


// Constructor por defecto
template <class T>
ABB<T>::ABB() {
    raiz_ = NULL;
}


// Constructor
template <class T>
ABB<T>::ABB(nodoABB<T>* raiz) {
    raiz_ = raiz;
}


// Destructor primero izq y luego dch
template <class T>
ABB<T>::~ABB() {
    Podar(raiz_);
}


// Elimina rama
template <class T> 
void
ABB<T>::Podar (nodoABB<T>* &nodo) {

    if (nodo != NULL) {  
        Podar(nodo->izq_);
        Podar(nodo->dch_);  
        delete nodo; 
        nodo = NULL;
    }
}

template<class T>
bool 
ABB<T>::EsVacio(nodoABB<T>* nodo) {
    return nodo == NULL;
}


template<class T>
bool 
ABB<T>::EsHoja(nodoABB<T>* *nodo) {
    return !nodo->dcho && !nodo->izdo;
}



// Tamaño del arbol = n de nodos
template <class T>
const int 
ABB<T>::TamRama(nodoABB<T>* nodo) {

    if (nodo == NULL) return 0 ;
        // nodos lado dch mas izquierdo
        return (1 + TamRama(nodo->izq_) + TamRama(nodo->dch_) );
}


template <class T>
void
ABB<T>::Preorden( nodoABB<T> *nodo ) {

    if (nodo == NULL) return;
    std::cout<< nodo->clave_;
    Preorden(nodo->izq_);
    Preorden(nodo->dch_);
}


template <class T>
void
ABB<T>::Inorden( nodoABB<T> *nodo ) {

    if (nodo == NULL) return;
    Inorden(nodo->izq_);
    std::cout<< nodo->clave_;
    Inorden(nodo->dch_);
}


template <class T>
void
ABB<T>::Postorden( nodoABB<T> *nodo ) {

    if (nodo == NULL) return;
    Postorden(nodo->izq_);
    Postorden(nodo->dch_);
    std::cout<< nodo->clave_;
}


template <class T> 
void 
ABB<T>::MostrarRecorrido() {
    std::cout<<"Recorrido preorden: ";
    Preorden(raiz_);
    std::cout<<std::endl;
    std::cout<<"Recorrido inorde: ";
    Inorden(raiz_);
    std::cout<<std::endl;
    std::cout<<"Recorrido postorden: ";
    Postorden(raiz_);
    std::cout<<std::endl;
}

// Busca clave en la rama
template <class T> 
nodoABB<T>* 
ABB<T>::BuscarRama (nodoABB<T>* nodo, T clave) {
        
    // Si el nodo está vacío, no se ha encontrado el clave buscado
    if (nodo == NULL) {
        return NULL;
    }
    if (clave == nodo->clave_) {
        value = true;
        return nodo;
    }
    if (clave < nodo->clave_){
        return BuscarRama (nodo->izq_, clave);
    }
    if (clave > nodo->clave_){
        return BuscarRama (nodo->dch_, clave);
    }
    return nodo;
    value = false;
}


// Insertar clave en la rama sin equilibrio
template <class T> 
void 
ABB<T>::InsertarRama (nodoABB<T>* &nodo, T clave_dada) {
    if (nodo == NULL)
        nodo = new nodoABB<T>(clave_dada, clave_dada);

    else if (clave_dada < nodo->clave_)
        InsertarRama(nodo->izq_, clave_dada);
    else
        InsertarRama(nodo->dch_, clave_dada);
}



// Intercambia el clave a eliminar con el mayor de la rama especificada (normalmente la izquierda)
template <class T> 
void 
ABB<T>::Sustituir (nodoABB<T>* &eliminar, nodoABB<T>* &sust) {

    // Si el nodo tiene hijo derecho (mayor), vuelve a llamar a la función con dicho hijo derecho
    if (sust->dch_ != NULL)
        Sustituir(eliminar, sust->dch_);
    // Si el nodo no tiene hijo derecho, ya se ha encontrado el valor mayor de la rama
    // Se intercambia el clave a eliminar con el valor mayor encontrado
    else {
        eliminar ->clave_ = sust->clave_;
        eliminar = sust ;
        sust = sust->izq_;
    }
}

// Elimina un clave de una rama
template <class T> 
void
ABB<T>::EliminarRama (nodoABB<T>* &nodo, T clave) {

    // rama vacia
    if (nodo == NULL) {
        std::cerr << "El nodo a eliminar no esta en el arbol!" << std::endl;

    }
                
    // Rama no vacia
    else {
        // clave igual eliminar
        if (clave == nodo->clave_) {
            // Si la rama derecha está vacía, se sustituye el nodo a eliminar por el nodo raíz de la rama izquierda
            if (nodo->dch_ == NULL) {
                nodo = nodo->izq_;
            }
            // Si la rama derecha NO está vacía...
            else {
                // Si la rama izquierda está vacía, se sustituye el nodo a eliminar por el nodo raíz de la rama derecha
                if (nodo->izq_ == NULL) {
                    nodo = nodo->dch_;
                }
                // Si el nodo tiene 2 hijos, se intercambia el clave a eliminar con el mayor de la rama izquierda
                else {
                    nodoABB<T>* eliminar = nodo;  // Nodo que se pretende eliminar
                    Sustituir(eliminar, nodo->izq_);
                }
            }
        }
        // clave distinto eliminar
        else {
        // Si el clave es mayor que el que se quiere eliminar, se vuelve a llamar al método con la rama izquierda
            if (clave < nodo->clave_) {
                EliminarRama(nodo->izq_, clave);
            }
            // Si el clave NO es mayor que el que se quiere eliminar...
            else {
            // Si el clave es menor que el que se quiere eliminar, se vuelve a llamar al método con la rama derecha
                if (clave > nodo->clave_) {
                    EliminarRama(nodo->dch_, clave);
                }
            }
        }
    }
}


template <class T> 
void 
ABB<T>::RecorridoN() {

    queue_l_t<std::pair <nodoABB<T> *, int>> cola;
    
    nodoABB<T>* nodo;                  // Nodo auxiliar
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
        if (nodo != NULL) std::cout << "[" << nodo->clave_ << "]";
        else std::cout << "[.]";
        
        // Si el nodo extraído no está vacío, se insertan sus dos hijos en la cola
        if (nodo != NULL) {
            cola.push(std::make_pair(nodo->izq_, nivel+1));
            cola.push(std::make_pair(nodo->dch_, nivel+1));
        }
    }
}


