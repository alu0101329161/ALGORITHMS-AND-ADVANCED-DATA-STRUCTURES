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
#define maxv 100

class Mundo {

    public:

    Mundo (std::string&, std::string&);
    ~Mundo ();

    int GetPosicionHormiga(int, int);
    void SetCambioValor(int&, int&, int&);
    int GetTablero(int&, int&);

    private:

    int fila_;
    int columna_;
    int tablero[maxv][maxv];

};