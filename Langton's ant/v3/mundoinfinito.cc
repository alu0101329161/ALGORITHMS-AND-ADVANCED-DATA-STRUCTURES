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
MundoInfinito::MundoInfinito(int inix, int iniy) : Mundo(inix, iniy) {}



void 
MundoInfinito::Actualizar (Hormiga& hormiga) {

    int aumentar_x = 0;
    int aumentar_y = 0;
    int disminuir_x = 0;
    int disminuir_y = 0;
    int x = hormiga.GetCordenadaX();
    int y = hormiga.GetCordenadaY();

    if (x < GetMinX()) {
        disminuir_x = disminuir_x - 5;
        //hormiga.SetCordenadaX(GetMaxX() -1);
    }
    if (y < GetMinY()) {
        disminuir_y = disminuir_y - 5;
        //hormiga.SetCordenadaY(GetMaxY() -1);
    }
    if (x >= GetMaxX()) {
        aumentar_x = aumentar_x + 5;
        //hormiga.SetCordenadaX(GetMinX());
    }
    if (y >= GetMaxY()) {
        aumentar_y = aumentar_y + 5;
        //hormiga.SetCordenadaY(GetMinY());

    }

    

    if (aumentar_x != 0 || aumentar_y != 0 || disminuir_x != 0 || disminuir_y != 0) {

        vector_t<vector_t<int>> aux;
        aux.Resize(min_y_, max_y_);
        
        for (int i = min_y_; i < max_y_; i++)
            aux[i].Resize(min_x_, max_x_);

        for (int i = min_y_; i < max_y_; i++)
            for (int j = min_x_; j < max_x_; j++)
                aux[i][j] = GetTablero(i, j);


        Reconstruir (disminuir_x + min_x_, aumentar_x + max_x_, disminuir_y + min_y_, aumentar_y + max_y_);
        for (int i = min_y_ - disminuir_y; i < max_y_ - aumentar_y; i++) {
            for (int j = min_x_ - disminuir_x; j < max_x_ - aumentar_x; j++) {
                SetTablero(i, j, aux[i][j]);
            }
        }
    }
}

