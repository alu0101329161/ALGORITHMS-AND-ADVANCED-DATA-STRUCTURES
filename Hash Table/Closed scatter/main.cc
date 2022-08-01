/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  Trabajar con tablas de hash y comprobar el rendimiento de tablas pequeñas con tablas grandes
*               
*  Compilar:    g++ -g -o prueba main.cc

*/

#include "tablahash.h"
#include <iostream>
#include <random>


int main(void){

    int aux_nc, aux_nv, aux_type, aux_type1, lectura, aux;
    std::cout << "Bienvenido" <<std::endl;
    std::cout << "Introduzca el numero de celdas de la tabla : " <<std::endl;
    std::cin>>aux_nc;
    std::cout << "Introduzca el numero de claves de cada celda : " <<std::endl;
    std::cin>>aux_nv;

    unsigned valor;
    do {
        std::cout << "Tipo de dispersion a aplicar:  " << std::endl;
        std::cout << "0. Dispersion por modulo       " << std::endl;
        std::cout << "1. Dispersion pseudo-aleatoria " << std::endl;
        std::cin>> aux_type;
    } while((aux_type < 0) || (aux_type > 1));

        do {
        std::cout << "Tipo de exploracion a realizar:  " << std::endl;
        std::cout << "0. lineal       " << std::endl;
        std::cout << "1. Cuadratica " << std::endl;
        std::cout << "2. Doble dispersion       " << std::endl;
        std::cout << "3. Redispersion" << std::endl;
        std::cin>> aux_type1;
    } while((aux_type1 < 0) || (aux_type1 > 3));

    tablaHash<unsigned> tabla(aux_nc,aux_nv, aux_type, aux_type1);
    bool quit = true;
    do{
        std::cout << "1.Para  insertar valor en la tabla      " << std::endl;
        std::cout << "2.Para buscar una valor en la tabla    " << std::endl;
        std::cout << "3.Para mostrar la tabla                " << std::endl;
        std::cout << "4.Para finalizar  programa             " << std::endl;
        std::cout << "5.Para mostrar mayor colision                " << std::endl;
        std::cin >> lectura;
        switch (lectura)
        {

        case 1:
        std::cout << "Valor a insertar: " << std::endl; 
        std::cin >> valor;
        if(tabla.insertar(valor))
        std::cout<<"Valor insertado"<<std::endl;
        else
        std::cout<<"No se pudo insertar"<<std::endl;
        break;

        case 2:
        std::cout << "Valor a buscar:  " << std::endl; 
        std::cin >>valor;
        if(tabla.buscar(valor))
        std::cout<<"Valor encontrado"<<std::endl;
        else
        std::cout<<"Valor no insertado en la tabla"<<std::endl;
        break;

        case 3:
        tabla.mostrar();
        break;

        case 4:
        std::cout << "Programa Finalizado " << std::endl;
        quit = false;
        break;

        case 5:
        aux=tabla.mostrarcolisiones();
        std::cout<<aux<<std::endl;
        break;

        default:
        std::cout << " Valor no valido, vuelva a intentarlo" << std::endl;
        break;
        }


    }while(quit==true);

 return 0;
    
}