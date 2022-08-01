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

#include "hormiga.h"


//Constructor Asigno a la hormiga una posicion inicial
Hormiga::Hormiga(int x, int y) {

    Resize(x, y);
}



void
Hormiga::Resize(int x, int y) 
{

    cordenadax_ = x;
    cordenaday_ = y;
    direcciones = "<A^B>CvD";
    direccion_ = 1;
    

}

Hormiga::~Hormiga() {

}

char
Hormiga::GetDireccion() {
    return direcciones[direccion_];
}



// Avanzo con la hormiga
void
Hormiga::Avanzar(int& posicion_actual) {

    switch (posicion_actual) //girar cabeza
    {
    case 0: direccion_ = direccion_ - 1; break;
    case 1: direccion_ = direccion_ + 1; break;
    }

    if(direccion_ > 7) direccion_= 0;
    if(direccion_ < 0) direccion_= 7;

    switch (direccion_)     //desplazar
    {
    case 0: cordenadax_ --;                 break;
    case 1: cordenadax_ --; cordenaday_ --; break;
    case 2: cordenaday_ --;                 break;
    case 3: cordenadax_ ++; cordenaday_ --; break;
    case 4: cordenadax_ ++;                 break;
    case 5: cordenadax_ ++; cordenaday_ ++;  break;
    case 6: cordenaday_ ++;                 break;
    case 7: cordenadax_ --; cordenaday_ ++; break;
    }

}

// Getter para saber posicion de la hormiga en eje x
int 
Hormiga::GetCordenadaX() {
    return cordenadax_;
}
// Getter para saber posicion de la hormiga en eje y
int 
Hormiga::GetCordenadaY() {
    return cordenaday_;
}