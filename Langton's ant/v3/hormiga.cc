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


// Redimensionamos los atributos
void
Hormiga::Resize(int x, int y) 
{
    cordenadax_ = x;
    cordenaday_ = y;
    direccion_ = 1;
}

Hormiga::~Hormiga() {

}


// Imprimir cabeza de la hormiga   <A^B>CvD
void
Hormiga::GetCabeza() {
    switch(direcciones[direccion_]) {
        case '<': std::cout << "\u2190";
        break;
        case 'A': std::cout << "\u2196";
        break;
        case '^': std::cout << "\u2191";
        break;
        case 'B': std::cout << "\u2197";
        break;
        case '>': std::cout << "\u2192";
        break;
        case 'C': std::cout << "\u2198";
        break;
        case 'v': std::cout << "\u2193";
        break;
        case 'D': std::cout << "\u2199";
        break;
    }
}



// Realiza movimiento completo de la hormiga
void
Hormiga::ActualizarMovimiento(int valor) {

    GirarCabeza(valor);
    DesplazarHormiga();
}


// Giro de la cabeza de la hormiga
void
Hormiga::GirarCabeza(int& posicion_actual) {

    switch (posicion_actual)
    {
    case 0: direccion_ = direccion_ - 1; break;
    case 1: direccion_ = direccion_ + 1; break;
    }

    if(direccion_ > 7) direccion_= 0;
    if(direccion_ < 0) direccion_= 7;

}

// Desplazamiento de la hormiga
void
Hormiga::DesplazarHormiga() {

     switch (direccion_)     
    {
     case 0: cordenadax_ --;                 break;
     case 1: cordenadax_ --; cordenaday_ --; break;
     case 2: cordenaday_ --;                 break;
     case 3: cordenadax_ ++; cordenaday_ --; break;
     case 4: cordenadax_ ++;                 break;
     case 5: cordenadax_ ++; cordenaday_ ++; break;
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



int
Hormiga::GetDireccion () {

  return direccion_;
}



void
Hormiga::SetCordenadaX(int x) {

  cordenadax_ = x;
}



void
Hormiga::SetCordenadaY(int y) {

  cordenaday_ = y;
}



Hormiga
Hormiga::operator=(Hormiga& a) {

    cordenadax_ = a.GetCordenadaX();
    cordenaday_ = a.GetCordenadaY();
    direccion_ = a.GetDireccion();

    return *this;
}