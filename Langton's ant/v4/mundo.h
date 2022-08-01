




#pragma once

#include "vector.h"
#include "hormiga.h"
#include "exception.h"
class Hormiga;

// Clase padre no puede instanciar objeto
class Mundo {

    public:

    Mundo(int, int);
    virtual ~Mundo();

    void Construir (int, int);
    void Reconstruir (int ,int , int, int);
    void Resize();

    int GetMaxX ();
    int GetMaxY ();
    int GetMinX ();
    int GetMinY ();

    void SetCambioValor(int&, int&, int&);
    int GetTablero(int&, int&);
    void SetTablero(int&, int&, int&);
    void ControlarError(int&, int&);

    //Se redefinde en clase hijo
    virtual void Actualizar(Hormiga*) = 0;


    protected:

    int min_x_, min_y_;
    int max_x_, max_y_;  
    vector_t <vector_t<int>> tablero_;
};


class MundoFinito:public Mundo {

    public:
    MundoFinito (int = 0, int = 0);

    virtual void Actualizar (Hormiga*);
};


class MundoInfinito:public Mundo {

    public:
    MundoInfinito (int = 0, int = 0);

    virtual void Actualizar (Hormiga*);
};