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

class Hormiga {

    public:
    Hormiga (int = 0, int = 0);
    ~Hormiga ();
    void Resize(int, int);

    void Avanzar(int&);
    int GetCordenadaX();
    int GetCordenadaY();
    char GetDireccion();

    private:

    int direccion_;
    int nfila_, ncolumna_;
    int cordenadax_, cordenaday_;
    std::string direcciones;

};