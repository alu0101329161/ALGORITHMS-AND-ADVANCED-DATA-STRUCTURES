
#include "mundo.h"

Mundo::Mundo(int inix, int iniy) {

  Construir (inix, iniy);
}



Mundo::~Mundo() {}



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
Mundo::Resize() {
    
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
Mundo::SetCambioValor(int& valor, int& cordenadax, int& cordenaday) {
    if(valor == 0)
        tablero_[cordenaday][cordenadax] = 1;
    else
        tablero_[cordenaday][cordenadax] = 0;
}



int
Mundo::GetTablero(int& cordenaday, int& cordenadax) 
{
    return tablero_[cordenaday][cordenadax];
}



void 
Mundo::SetTablero(int& cordenadax, int& cordenaday, int& valor) {
    tablero_[cordenadax][cordenaday] = valor;
}

void 
Mundo::ControlarError(int& cordenadax, int& cordenaday) {
    if(cordenadax >= max_x_|| cordenadax < max_x_|| cordenaday >= max_y_ || cordenaday < max_y_)
    throw exception_core();
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