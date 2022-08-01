


#include "hormiga.h"

HormigaLangton::HormigaLangton (int cordenadax, int cordenaday) : Hormiga(cordenadax, cordenaday) {}



void
HormigaLangton::GirarCabeza(int& posicion_actual) {

    switch (posicion_actual)
    {
    case 0: direccion_ = direccion_ - 2; break;
    case 1: direccion_ = direccion_ + 2; break;
    }

    if(direccion_ > 6) direccion_= 0;
    if(direccion_ < 0) direccion_= 6;

}


void
HormigaLangton::DesplazarHormiga() {
    switch (direccion_)     
    {
     case 0: cordenadax_ --;                 break;
     case 2: cordenaday_ --;                 break;
     case 4: cordenadax_ ++;                 break;
     case 6: cordenaday_ ++;                 break;
    }
}

HormigaLangton
HormigaLangton::operator=(HormigaLangton& a) {

    cordenadax_ = a.GetCordenadaX();
    cordenaday_ = a.GetCordenadaY();
    direccion_ = a.GetDireccion();

    return *this;
}