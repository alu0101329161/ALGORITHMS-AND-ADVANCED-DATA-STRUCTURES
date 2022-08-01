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
    ~Hormiga ();
    void Resize(int, int);

    void ActualizarMovimiento(int);

    void SetCordenadaX(int);
    void SetCordenadaY(int);

    int GetCordenadaX();
    int GetCordenadaY();
    void GetCabeza();
    int GetDireccion ();
    Hormiga operator=(Hormiga&);

    private:
    void GirarCabeza(int&);
    void DesplazarHormiga();

    int direccion_;
    int cordenadax_, cordenaday_;
    std::string direcciones = "<A^B>CvD";
};