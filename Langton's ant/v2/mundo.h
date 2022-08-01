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
#include "vector.h"
#define maxv 100

class Mundo {

    public:
    Mundo (int = 0, int = 0);
    ~Mundo ();

    int GetPosicionHormiga(int, int);
    void SetCambioValor(int&, int&, int&);
    int GetTablero(int, int);
    void Resize();

    int GetMaxX ();
    int GetMaxY ();
    int GetMinX ();
    int GetMinY ();

    void Construir (int inix, int iniy);
    void Reconstruir (int ,int , int, int);
    void Actualizar (int x, int y);
    private:

    int min_x_, min_y_;
    int max_x_, max_y_;
    vector_t <vector_t<int>> tablero_;

};