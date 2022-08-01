/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  Este programa es un simulador de la hormiga de langton
*               
*  Compilar:    g++ -g -o hormiga hormiga_langton.cc hormiga.cc mundo.cc universo.cc
*              
*  Ejecutar:
*/

#include "mundo.h"
#include "hormiga.h"
#include "universo.h"
#include "vector.h"
#define maxv 100

int main(void) {
    std::string respuesta, inix, iniy;
    int int_inix, int_iniy;
    
    std::cout<<"////////////////////LA HORMIGA DE LANGTON///////////////////////    "<<std::endl;
    std::cout<<"Representaremos a la hormiga con los caracteres  ‘<’, A ‘>’  B, ‘^’, C ‘v’ D "<<std::endl;
    std::cout<<"Representaremos las casillas del tablero con ‘ ‘(blanca), ‘X’(negra)"<<std::endl;
    //std::cout<<"Introducir indices positivos en el constructor hace los negativos por ejemplo 5 -5"<<std::endl;

        std::cout<<"Introduzca los valores iniciales de tablero(INIDICE X INDICE Y)"<<std::endl;
        std::cin >> inix;
        std::cin >> iniy;

    int_inix= stoi(inix);
    int_iniy= stoi(iniy);


    Universo universo1(int_inix, int_iniy);


       universo1.RunSystem();


    return 0;
}