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

#include "mundo.h"


#define maxv 100

// Creo el objeto mundo
Mundo::Mundo (std::string& string_fila, std::string& string_columna) {
   fila_=stoi(string_fila);
   columna_=stoi(string_columna);

   int tablero[fila_][columna_];
   for(int fila = 0; fila < fila_ ; fila ++) {
       for(int columna = 0; columna < columna_; columna ++) {
           tablero[fila][columna] = 0;
       }
   }
}

Mundo::~Mundo() {

}
// Antes de avanzar la hormiga cambia el valor de la casilla donde este
void
Mundo::SetCambioValor(int& valor, int& cordenadax, int& cordenaday) {
    if(valor == 0)
    tablero[cordenaday][cordenadax] = 1;
    else
    tablero[cordenaday][cordenadax] = 0;
}
// Acceder a tablero
int
Mundo::GetTablero(int& nfila, int& ncolumna) {
    return tablero[nfila][ncolumna];
}

// Obtener posicion de la hormiga en el tablero asi saber si esta
// en un 0 o un 1
int
Mundo::GetPosicionHormiga(int cordenadax, int cordenaday) {
    return tablero[cordenaday][cordenadax];
}
