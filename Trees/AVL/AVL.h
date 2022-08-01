


#include "ABB.h"
#include <iostream>


template <class T>
class AVL: public ABB<T> {

    public:

    AVL();
    AVL(nodoABB<T>* raiz);
    ~AVL();

    void Insertar(T clave);
    void Eliminar(T clave);
    void Eliminar(nodoABB<T>* &nodo, T valor, bool& decrece);
    void Sustituye(nodoABB<T>* &eliminado, nodoABB<T>* &sust, bool &decrece);
    void eliminar_re_bal_I(nodoABB<T>* &nodo, bool& decrece);
    void eliminar_re_bal_D(nodoABB<T>* &nodo, bool& crece);
    void inserta_bal( nodoABB<T>* &nodo, nodoABB<T>* nuevo, bool& crece);
    void insert_re_balancea_izda(nodoABB<T>* &nodo, bool& crece);
    void insert_re_balancea_dch(nodoABB<T>* &nodo, bool& crece);
    void rotacion_II(nodoABB<T>* &nodo);
    void rotacion_DD(nodoABB<T>* &nodo);
    void rotacion_ID(nodoABB<T>* &nodo);
    void rotacion_DI(nodoABB<T>* &nodo);

    bool traza {false};

};

template <class T>
AVL<T>::AVL() {
    this->raiz_ = NULL;
}

template <class T>
AVL<T>::AVL(nodoABB<T>* raiz) {

  ABB<T>(this->raiz_);

}

template <class T>
AVL<T>::~AVL() {
    
    this->Podar(this->raiz_);

}


template <class T>
void 
AVL<T>::rotacion_II(nodoABB<T>* &nodo) {
        //std::cout<<"ROTACION 2 ENLACES II"<<std::endl;

        nodoABB<T>* nodo1 = nodo->izq_;
        nodo->izq_ = nodo1->dch_;
        nodo1->dch_ = nodo;

        if(nodo1->balanceo_ == 1) {
            nodo->balanceo_ = 0;
            nodo1->balanceo_ =0;
        } else {
            nodo->balanceo_ = 1;
            nodo1->balanceo_ = -1;
        }
        nodo = nodo1;
}


template <class T>
void 
AVL<T>::rotacion_DD(nodoABB<T>* &nodo) {
        //std::cout<<"ROTACION 2 ENLACES DD"<<std::endl;

        nodoABB<T>* nodo1 = nodo->dch_;
        nodo->dch_ = nodo1->izq_;
        nodo1->izq_ = nodo;

        if(nodo1->balanceo_ == -1) {
            nodo->balanceo_ = 0;
            nodo1->balanceo_ = 0;
        } else {
            nodo->balanceo_ = -1;
            nodo1->balanceo_ = 1;
        }
        nodo = nodo1;
}

template <class T>
void 
AVL<T>::rotacion_ID(nodoABB<T>* &nodo) {
        //std::cout<<"ROTACION 3 ENLACES ID"<<std::endl;

        nodoABB<T>* nodo1 = nodo->izq_;
        nodoABB<T>* nodo2 = nodo1->dch_;
        nodo->izq_ = nodo2->dch_;
        nodo2->dch_ = nodo;
        nodo1->dch_ = nodo2->izq_;
        nodo2->izq_ = nodo1;


        if(nodo2->balanceo_ == -1) {
            nodo1->balanceo_ = 1;
        } else {
            nodo1->balanceo_ = 0;
        }
        if(nodo2->balanceo_ == 1)
            nodo->balanceo_ = -1;
        else
            nodo->balanceo_ = 0;

        nodo2->balanceo_ = 0;
        nodo = nodo2;
}

template <class T>
void 
AVL<T>::rotacion_DI(nodoABB<T>* &nodo) {
        //std::cout<<"ROTACION 3 ENLACES DI"<<std::endl;

        nodoABB<T>* nodo1 = nodo->dch_;
        nodoABB<T>* nodo2 = nodo1->izq_;
        nodo->dch_ = nodo2->izq_;
        nodo2->izq_ = nodo;
        nodo1->izq_ = nodo2->dch_;
        nodo2->dch_ = nodo1;


        if(nodo2->balanceo_ == 1) {
            nodo1->balanceo_ = -1;
        } else {
            nodo1->balanceo_ = 0;
        }
        if(nodo2->balanceo_ == -1)
            nodo->balanceo_ = 1;
        else
            nodo->balanceo_ = 0;

        nodo2->balanceo_ = 0;
        nodo = nodo2;
}



template <class T>
void 
AVL<T>::insert_re_balancea_izda(nodoABB<T>* &nodo, bool& crece) {

    switch(nodo->balanceo_) {
        case -1:
            nodo->balanceo_ = 0;
            crece = false;
            break;

        case 0:
            nodo->balanceo_ = 1;
            break;

        case 1:
            if(traza) {
                std::cout<<"Desbalanceado: "<<std::endl;
                this->RecorridoN();
            }
            nodoABB<T>* nodo1 = nodo->izq_;
            if(nodo1->balanceo_ == 1) {
                if(traza)
                    std::cout<<"\n Rotacion II ["<<nodo->clave_<<"]"<<std::endl;
                rotacion_II(nodo);
            }
            else {
                if(traza)
                    std::cout<<"\n Rotacion ID ["<<nodo->clave_<<"]"<<std::endl;
                rotacion_ID(nodo);
            }
            crece = false;
            break;
        }
}

template <class T>
void 
AVL<T>::insert_re_balancea_dch(nodoABB<T>* &nodo, bool& crece) {

        switch(nodo->balanceo_) {
        case 1:
            nodo->balanceo_ = 0;
            crece = false;
            break;

        case 0:
            nodo->balanceo_ = -1;
            break;

        case -1:
            if(traza) {
                std::cout<<"Desbalanceado: "<<std::endl;
                this->RecorridoN();
            }
            nodoABB<T>* nodo1 = nodo->dch_;
            if(nodo1->balanceo_ == -1) {
                if(traza)
                    std::cout<<"\n Rotacion DD ["<<nodo->clave_<<"]"<<std::endl;
                rotacion_DD(nodo);
            }
            else {
                if(traza)
                    std::cout<<"\n Rotacion DI ["<<nodo->clave_<<"]"<<std::endl;
                rotacion_DI(nodo);
            }
            crece = false;
            break;
        }
    }

template <class T>
void 
AVL<T>::inserta_bal( nodoABB<T>* &nodo, nodoABB<T>* nuevo, bool& crece) {

    if (!nodo) {
        nodo = nuevo;
        crece = true;
    }

    else {

        if (nuevo->clave_ == nodo->dato_) {
            std::cerr << "Clave ya insertada!" << std::endl;
        }

        else if (nuevo->dato_ < nodo->dato_) {
            inserta_bal(nodo->izq_,nuevo,crece);
            if (crece) {
                 insert_re_balancea_izda(nodo,crece);
            }
        }

        else {
            inserta_bal(nodo->dch_,nuevo,crece);
            if (crece) {
                insert_re_balancea_dch(nodo,crece);
            }
        }
    }
}


template <class T>
void
AVL<T>::eliminar_re_bal_I(nodoABB<T>* &nodo, bool& decrece) {
    nodoABB<T>* nodo1 = nodo->dch_;
    switch(nodo->balanceo_) {
        case -1:
            if(nodo1->balanceo_ > 0) {
                if(traza)
                    std::cout<<"\n Rotacion DI ["<<nodo->clave_<<"]"<<std::endl;
                rotacion_DI(nodo);
            } else {
                if(traza)
                    std::cout<<"\n Rotacion DD ["<<nodo->clave_<<"]"<<std::endl;
                if(nodo1->balanceo_ == 0) 
                    decrece = false;
                rotacion_DD(nodo);
            }
        break;

        case 0:
            nodo->balanceo_ = -1;
            decrece = false;
        break;

        case 1:
            nodo->balanceo_ = 0;
    }
}

template <class T>
void
AVL<T>::eliminar_re_bal_D(nodoABB<T>* &nodo, bool& crece) {
    nodoABB<T>* nodo1 = nodo->izq_;
    switch(nodo->balanceo_) {
        case 1:
            if(nodo1->balanceo_ < 0) {
                if(traza)
                    std::cout<<"\n Rotacion ID ["<<nodo->clave_<<"]"<<std::endl;
                rotacion_ID(nodo);
            }
            else {
                if(traza)
                    std::cout<<"\n Rotacion II ["<<nodo->clave_<<"]"<<std::endl;
                
                if(nodo1->balanceo_ == 0) 
                    crece = false;
                rotacion_II(nodo);
                
            }
        break;

        case 0:
            nodo->balanceo_ = 1;
            crece = false;
        break;

        case -1:
            nodo->balanceo_ = 0;
        }
}

template <class T>
void 
AVL<T>::Sustituye(nodoABB<T>* &eliminado, nodoABB<T>* &sust, bool &decrece) {
        if(sust->dch_) {
            Sustituye(eliminado, sust->dch_, decrece);
            if(decrece)
                eliminar_re_bal_D(sust, decrece);
        } else {
            eliminado->dato_ = sust->clave_;
            eliminado = sust;	
            sust = sust->izq_;
            decrece = true;
        }
}

template <class T>
void 
AVL<T>::Eliminar(nodoABB<T>* &nodo, T valor, bool& decrece) {
        if(!nodo) {
            std::cerr << "El nodo a eliminar no esta en el arbol!" << std::endl;
            return;
        }

        if(valor < nodo->clave_) {
            Eliminar(nodo->izq_, valor, decrece);
            if(decrece)
                eliminar_re_bal_I(nodo, decrece);
        } else if(valor > nodo->clave_) {
            Eliminar(nodo->dch_, valor,decrece);
            if(decrece)
                eliminar_re_bal_D(nodo, decrece);
        } else {
            nodoABB<T>* eliminado = nodo;
            if(!nodo->izq_) {
                nodo = nodo->dch_;
                decrece = true;
            } else if(!nodo->dch_) {
                nodo = nodo->izq_;
                decrece = true;
            } else {
                Sustituye(eliminado, nodo->izq_, decrece);
                if(decrece)
                    eliminar_re_bal_I(nodo, decrece);
            }
            delete eliminado;
        }
}

template <class T>
void
AVL<T>::Eliminar(T clave) {

    bool decrece = false;
    Eliminar(this->raiz_,clave, decrece);

}



template <class T>
void
AVL<T>::Insertar(T clave) {

    nodoABB<T>* nuevo = new nodoABB<T>(clave, clave);
    nuevo->balanceo_ = 0;
    bool crece = false;
    inserta_bal(this->raiz_, nuevo, crece);

}

