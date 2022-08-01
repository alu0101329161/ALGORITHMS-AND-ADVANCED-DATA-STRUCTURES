/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  Este programa es un simulador de la hormiga de langton
*               
*  Compilar:    g++ -g -o hormiga hormiga_langton.cc hormiga.cc mundo.cc
*              
*  Ejecutar:
*/

#include "mundo.h"
#include "hormiga.h"


#define maxv 100

int main(void) {

    std::string fila,columna,respuesta;
    int valor,nfila,ncolumna;
    std::cout<<"////////////////////LA HORMIGA DE LANGTON///////////////////////    "<<std::endl;
    std::cout<<"Representaremos a la hormiga con los caracteres  ‘<’, ‘>’, ‘^’, ‘v’ "<<std::endl;
    std::cout<<"Representaremos las casillas del tablero con ‘ ‘(blanca), ‘X’(negra)"<<std::endl;

    do {
    std::cout<<"Introduzca el numero de filas >2 <100"<<std::endl;
    std::cin >> fila;
    } while(stoi(fila) > maxv || stoi(fila) <=2);
     do {
    std::cout<<"Introduzca el numero de columnas >2 <100"<<std::endl;
    std::cin >> columna;
    } while(stoi(columna) > maxv || stoi(columna) <=2 );

    nfila=stoi(fila);
    ncolumna=stoi(columna);

    // Creo objeto mundo y objeto hormiga
    Mundo mundo(fila, columna);
    Hormiga hormiga(fila,columna);
    int contador = 0;
    int posicion_anteriorx, posicion_anteriory;
    int valor1;

    do {
        contador ++;
        posicion_anteriorx=hormiga.GetCordenadaX(); // Guardamos posicion anterior
        posicion_anteriory=hormiga.GetCordenadaY();

        for(int fila = 0; fila < nfila ; fila ++) {
            for(int columna = 0; columna < ncolumna; columna ++) {

                if(mundo.GetTablero(fila,columna) == 0) {
                if(columna == hormiga.GetCordenadaX() && fila == hormiga.GetCordenadaY()) {
                    std::cout<<hormiga.GetDireccion();
                } else
                std::cout<<" ";
                }
                else {
                if(columna == hormiga.GetCordenadaX() && fila== hormiga.GetCordenadaY()) {
                    std::cout<<hormiga.GetDireccion();
                } else
                std::cout<<"X";
                }
            }
        std::cout<<std::endl;
        }
        valor = mundo.GetPosicionHormiga(hormiga.GetCordenadaX(), hormiga.GetCordenadaY()); // Donde esta la hormiga hay un 0 o un 1
        hormiga.Avanzar(valor);                                                             // avanzo con la hormiga
        mundo.SetCambioValor(valor, posicion_anteriorx, posicion_anteriory);                 // cambio valor de mundo
        std::cout<<std::endl;
        if(contador == 3) {
        std::cout<<"Quieres continuar realizando pasos"<<std::endl;
        std::cin >> respuesta;
        if(respuesta == "si") contador = 0;
        else contador = 4;
        }

    }while(contador <=3);


    return 0;
}