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

// Creo el objeto mundo
Mundo::Mundo (int inix, int iniy) 
{
    Construir (inix, iniy);
}



void
Mundo::Construir (int inix, int iniy) {

    max_x_= inix;
    max_y_= iniy;
    min_x_ = - inix;
    min_y_ = - iniy;

    Resize ();
}



void
Mundo::Reconstruir (int minx, int maxx, int miny, int maxy) {

    max_x_= maxx;
    max_y_= maxy;
    min_x_ = minx;
    min_y_ = miny;

   tablero_.Resize(min_y_, max_y_);
   for (int i = min_y_; i < max_y_; i++)
     tablero_[i].Resize(min_x_, max_x_);

    for (int i = min_y_; i < max_y_; i++) {
        for (int j = min_x_; j < max_x_; j++){
            tablero_[i][j] = 0;
        }
    }
}



void
Mundo::Resize() 
{
    
   tablero_.Resize(min_y_, max_y_);
   for (int i = min_y_; i < max_y_; i++)
     tablero_[i].Resize(min_x_, max_x_);

    for (int i = min_y_; i < max_y_; i++) {
        for (int j = min_x_; j < max_x_; j++){
            tablero_[i][j] = 0;
        }
    }
}

Mundo::~Mundo() {

}

// Antes de avanzar la hormiga cambia el valor de la casilla donde este
void
Mundo::SetCambioValor(int& valor, int& cordenadax, int& cordenaday) {
    if(valor == 0)
        tablero_[cordenaday][cordenadax] = 1;
    else
        tablero_[cordenaday][cordenadax] = 0;
}


// Acceder a tablero
int
Mundo::GetTablero(int nfila, int ncolumna) 
{
    return tablero_[nfila][ncolumna];
}



// Obtener posicion de la hormiga en el tablero asi saber si esta
// en un 0 o un 1
int
Mundo::GetPosicionHormiga(int cordenaday, int cordenadax) 
{
    return tablero_[cordenadax][cordenaday];
}


int
Mundo::GetMaxX () {
    return max_x_;
}



int
Mundo::GetMaxY () {
    return max_y_;
}



int
Mundo::GetMinX () {
    return min_x_;
}



int
Mundo::GetMinY () {
    return min_y_;
}



void 
Mundo::Actualizar (int x, int y) {

    int aumentar_x = 0;
    int aumentar_y = 0;
    int disminuir_x = 0;
    int disminuir_y = 0;

    if (x < GetMinX())
        disminuir_x = disminuir_x - 10;
    if (y < GetMinY())
        disminuir_y = disminuir_y - 10;
    if (x >= GetMaxX())
        aumentar_x = aumentar_x + 10;
    if (y >= GetMaxY())
        aumentar_y = aumentar_y + 10;

    if (aumentar_x != 0 || aumentar_y != 0 || disminuir_x != 0 || disminuir_y != 0) {

        vector_t<vector_t<int>> aux;
        aux.Resize(min_y_, max_y_);
        
        for (int i = min_y_; i < max_y_; i++)
            aux[i].Resize(min_x_, max_x_);

        for (int i = min_y_; i < max_y_; i++)
            for (int j = min_x_; j < max_x_; j++)
                aux[i][j] = tablero_[i][j];


        Reconstruir (disminuir_x + min_x_, aumentar_x + max_x_, disminuir_y + min_y_, aumentar_y + max_y_);
        for (int i = min_y_ - disminuir_y; i < max_y_ - aumentar_y; i++) {
            for (int j = min_x_ - disminuir_x; j < max_x_ - aumentar_x; j++) {
                tablero_[i][j] = aux[i][j];
            }
        }
    }
}