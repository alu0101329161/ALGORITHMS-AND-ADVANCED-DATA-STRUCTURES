/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  Este programa es un simulador de la hormiga de langton
*               
*  Compilar:    g++ -g -o hormiga_langton hormiga_langton.cc hormiga.cc mundo.cc universo.cc mundofinito.cc mundoinfinito.cc
*              
*  Ejecutar:
*/

#include "mundo.h"
#include "hormiga.h"
#include "universo.h"
#include "vector.h"
#define maxv 100

int main (int argc, char* argv[]) {

    std::string ayuda = "--help";
    int valor, inix, iniy, comportamiento;
    
    std::cout<<"////////////////////LA HORMIGA DE LANGTON///////////////////////    "<<std::endl;
    if (argc == 2 && argv[1] == ayuda) {

     std::cout<<"Representaremos a la hormiga con los caracteres  ‘<’, A ‘>’  B, ‘^’, C ‘v’ D "<<std::endl;
     std::cout<<"Representaremos las casillas del tablero con ‘ ‘(blanca), ‘X’(negra)"<<std::endl;

     return 0;
  }

    do {
    std::cout<<"Mundo finito(0) o mundo infinito(1)"<<std::endl;
    std::cin >> valor;
    }while(valor != 0 && valor != 1);

    do {

      std::cout<<"Introduzca los valores iniciales de tablero(INIDICE X INDICE Y)"<<std::endl;
      std::cin >> inix;
      std::cin >> iniy;

    } while(inix == 0 || iniy == 0 );

    Hormiga* puntero = NULL;
    std::vector<Hormiga*> vector_hormigas;
    int cantidad_hormigas, aux_x, aux_y;

    std::cout<<"Introduzca la cantidad de hormigas que desea"<<std::endl;
    std::cin >> cantidad_hormigas;


    for(int recorrido = cantidad_hormigas; recorrido > 0; recorrido --) {
       std::cout << "Introduzca posicion hormiga "<< recorrido << std::endl;
       std::cin >> aux_x;
       std::cin >> aux_y;
       std::cout << "Introduzca el comportamiento 1 o 2  "<< "Hormiga{" <<recorrido<< "}"<< std::endl;
       std::cin >> comportamiento;
       if (comportamiento == 1)
       puntero = new HormigaLangton (aux_x, aux_y);
      else
       puntero = new HormigaLangtonModif (aux_x, aux_y);
      puntero->Resize(aux_x, aux_y);
      vector_hormigas.push_back(puntero);
    }

    Mundo* auxiliar = NULL;

    if (valor == 1)
      auxiliar = new MundoInfinito (inix, iniy);
    else
      auxiliar = new MundoFinito (inix, iniy);

   Universo universo1(auxiliar, vector_hormigas);

    delete auxiliar;
    delete puntero;
    auxiliar = NULL;
    puntero = NULL;

    return 0;
}

