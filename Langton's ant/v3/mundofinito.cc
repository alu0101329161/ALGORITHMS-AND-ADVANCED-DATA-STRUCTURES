
#include "mundo.h"

// Creo el objeto mundo
MundoFinito::MundoFinito (int inix, int iniy) : Mundo (inix, iniy) {}



void 
MundoFinito::Actualizar (Hormiga& hormiga) {

    if(hormiga.GetCordenadaX() >= max_x_) hormiga.SetCordenadaX(min_x_);
    if(hormiga.GetCordenadaY() >= max_y_) hormiga.SetCordenadaY(min_y_);
    if(hormiga.GetCordenadaX() < min_x_) hormiga.SetCordenadaX(max_x_ -1);
    if(hormiga.GetCordenadaY() < min_y_) hormiga.SetCordenadaY(max_y_ -1);
}