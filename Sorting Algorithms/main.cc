/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  diferentes mecanismo para ordenar un vector
*               
*  Compilar:    g++ -g -o main main.cc

*/
#include "termcolor.hpp"
#include "ordenacion.h"
#include <iostream>
#include <cstdio>
#include <random>
#include <cstddef>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 

int modo;
int comparaciones;

int Miclave::contador=0;

int main(void) {

    int opcion, tamano, type;
    bool salida = true;
    std::vector<Miclave> vector;
    std::cout << "\t1. Desea el modo Demostracion(0) o modo Normal(1)" << std::endl;
    std::cin >> modo;
    Miclave numero;
    do {  
        std::cout << "\t----- ALGORITMOS DE ORDENACION -----" << std::endl;
        std::cout << "\t1. Ordenacion por insercion" << std::endl;
        std::cout << "\t2. Ordenacion quicksort" << std::endl;
        std::cout << "\t3. Ordenacion por shellsort" << std::endl;
        std::cout << "\t4. Ordenacion por Seleccion" << std::endl;
        std::cout << "\t5. Ordenacion por Mergesort" << std::endl;
        std::cout << "\t6. Ordenacion por HeapSort" << std::endl;
        std::cout << "\t7. Salir del programa" << std::endl;
        std::cout << "Elija el algoritmo de ordenacion: ";
        std::cin >> opcion;
        std::cout << std::endl;
        std::cout << "\nQuiere introducirla manual(0) o ramdon(1): ";
        std::cin>>type;
        std::cout << "\ntamano de la secuencia a ordenar: ";
        std::cin>>tamano;

        if(type == 0) {
            std::cout << "\nIntroduzca los elementos del vector: ";
            for(int contador = 0; contador < tamano; contador ++) {
                std::cout<<"posicion["<<contador<<"] ";std::cin>> numero;
                vector.push_back(numero);
            }
        } else {
            Miclave valor;
            srand(time(NULL));
            for(int contador = 0; contador < tamano; contador ++) {
                valor.Setter(rand()%10000);
                vector.push_back(valor);
            }
        } 

        std::cout << std::endl;
        std::cout << "\nVector que se va a ordenar: ";
        for (unsigned recorrido = 0; recorrido < vector.size(); recorrido++)
        std::cout<<termcolor::yellow<<std::fixed<<std::setw(7)<< vector[recorrido]<<termcolor::reset;
        std::cout << std::endl;

        switch (opcion) {

        case 1:
        Insercion<Miclave>(vector, vector.size() -1);
//
        std::cout<<"Numero de comparaciones gucci: " << Miclave::contador << std::endl;
        break;

        case 2:
        Quicksort<Miclave>(vector, vector.size() -1);
//
        std::cout<<"Numero de comparaciones gucci: " << Miclave::contador << std::endl;
        break;

        case 3:
        Shellsort<Miclave>(vector, vector.size() -1);
//
        std::cout<<"Numero de comparaciones gucci: " << Miclave::contador << std::endl;
        break;

        case 4:
        Seleccion<Miclave>(vector, vector.size() -1);
//
        std::cout<<"Numero de comparaciones gucci: " << Miclave::contador << std::endl;
        break;

        case 5:
        MSort<Miclave>(vector, vector.size() -1);
//
        std::cout<<"Numero de comparaciones gucci: " << Miclave::contador << std::endl;
        break;

        case 6:
        HeapSort<Miclave>(vector, vector.size() -1);
//
        std::cout<<"Numero de comparaciones gucci: " << Miclave::contador << std::endl;
        break;

        case 7:
        salida = false;
        break;

        default:
        std::cout << "Vuelva a introducir el valor";
        break;
        }


        std::cout << std::endl;
        if(modo == 1 || modo == 0) {
            std::cout << "Vector ordenado: ";    
            for (unsigned recorrido = 0; recorrido < vector.size(); recorrido++)
                std::cout<<termcolor::yellow<<std::fixed<<std::setw(7)<< vector[recorrido]<<termcolor::reset;
           
        }
        std::cout << std::endl;
        vector.clear();
        comparaciones = 0;
        Miclave::contador = 0;
    } while(salida == true);

  return 0;
}