

#include "hormiga.h"

HormigaLangtonModif::HormigaLangtonModif (int cordenadax, int cordenaday) : Hormiga(cordenadax, cordenaday) {}



void
HormigaLangtonModif::GirarCabeza(int& posicion_actual) {

    switch (posicion_actual)
    {
    case 0: direccion_ = direccion_ + 1; break;
    case 1: direccion_ = direccion_ - 1; break;
    }

    if(direccion_ > 7) direccion_= 0;
    if(direccion_ < 0) direccion_= 7;

}


void
HormigaLangtonModif::DesplazarHormiga() {
    switch (direccion_)     
    {
     case 0: cordenadax_ --;                 break;
     case 1: cordenadax_ --; cordenaday_ --; break;
     case 2: cordenaday_ --;                 break;
     case 3: cordenadax_ ++; cordenaday_ --; break;
     case 4: cordenadax_ ++;                 break;
     case 5: cordenadax_ ++; cordenaday_ ++; break;
     case 6: cordenaday_ ++;                 break;
     case 7: cordenadax_ --; cordenaday_ ++; break;
    }
}


HormigaLangtonModif
HormigaLangtonModif::operator=(HormigaLangtonModif& a) {

    cordenadax_ = a.GetCordenadaX();
    cordenaday_ = a.GetCordenadaY();
    direccion_ = a.GetDireccion();

    return *this;
}