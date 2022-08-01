/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  Este programa es un simulador de la hormiga de langton
*               
*  Compilar:    g++ -std=c++14 -g -Wall -o 
*              
*  Ejecutar:
*/
#pragma once

#include <iostream>

class Mundo;

class Hormiga {

    public:

    Hormiga (int = 0, int = 0);
    virtual ~Hormiga ();
    void Resize(int, int);

    virtual void ActualizarMovimiento(int);
    

    void SetCordenadaX(int);
    void SetCordenadaY(int);
    int GetCordenadaY();
    int GetCordenadaX();
    int GetDireccion ();
    void GetCabeza();
    
    protected:

    virtual void GirarCabeza(int&) = 0;
    virtual void DesplazarHormiga() = 0;

    int direccion_;
    int cordenadax_, cordenaday_;
    std::string direcciones = "<A^B>CvD";
};


class HormigaLangton:public Hormiga {

    public:
    HormigaLangton (int = 0, int = 0);
    HormigaLangton operator=(HormigaLangton&);
    private:

    virtual void GirarCabeza (int &);
    virtual void DesplazarHormiga ();
    
};

class HormigaLangtonModif:public Hormiga {

    public:
    HormigaLangtonModif (int = 0, int = 0);
    HormigaLangtonModif operator=(HormigaLangtonModif&);
    private:

    virtual void GirarCabeza (int &);
    virtual void DesplazarHormiga ();
    
};