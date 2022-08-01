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
Hormiga::Hormiga(std::string& string_fila, std::string& string_columna) {
    
   int ramdonx, ramdony;
   int condicion1 = 0;
   nfila_ = stoi(string_fila)-1;
   ncolumna_ =stoi(string_columna)-1;

   do 
   {
    ramdonx=rand()%(nfila_-1);
    ramdony=rand()%(ncolumna_-1);
    if(ramdonx == 0 || ramdonx == 1 || ramdonx == nfila_-1 || ramdony == 0 || ramdony == 1 || ramdony == ncolumna_-1 ) 
    {
        condicion1=0;

    } else
    condicion1 = 1;
    } while (condicion1 == 0);

    cordenadax_ = ramdonx;
    cordenaday_ = ramdony;
    direcciones = "<^>v";
    direccion_=1;
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
    switch (posicion_actual)
    {
    case 0: direccion_ = direccion_ -1; break;
    case 1: direccion_ = direccion_ +1; break;
    }

    if(direccion_ > 3) direccion_= 0;
    if(direccion_ < 0) direccion_= 3;

    switch (direccion_)
    {
    case 0: cordenadax_ --; break;
    case 1: cordenaday_ --; break;
    case 2: cordenadax_ ++; break;
    case 3: cordenaday_ ++; break;
    }

    if(cordenadax_ > ncolumna_) cordenadax_= 0;
    if(cordenaday_ > nfila_) cordenaday_= 0;
    if(cordenadax_ < 0) cordenadax_= ncolumna_;
    if(cordenaday_ < 0) cordenaday_= nfila_;
    
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