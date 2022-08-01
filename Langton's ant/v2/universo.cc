
#include "universo.h"

Universo::Universo(int& inix, int& iniy) 
{
    mundo.Construir(inix, iniy);
    
    Hormiga aux;
    vector_hormiga.push_back(aux);
    //aux.Resize(1,1);
    //vector_hormiga.push_back(aux);

}



Universo::~Universo() {}



void
Universo::RunSystem() {
   
    int posicion_anteriorx, posicion_anteriory;
    int contador = 0;
    int hormiga_posicion = 0;
    int valor = 0;
    std::string respuesta;
    do {

    int valor = 0;
    for(int y = mundo.GetMinY(); y < mundo.GetMaxY() ; y++) {
        for(int x = mundo.GetMinX(); x < mundo.GetMaxX(); x++) {

            switch (mundo.GetTablero(y, x))
            {
            case 0:
                for (unsigned a = 0; a < vector_hormiga.size(); a++) {
                    if (valor == 0 && vector_hormiga[a].GetCordenadaX() == x && vector_hormiga[a].GetCordenadaY() == y) {
                        std::cout << vector_hormiga[a].GetDireccion();
                        valor = 1;
                    }
                }
                if (valor == 0)
                    std::cout << " ";
                break;
            case 1:
                for (unsigned a = 0; a < vector_hormiga.size(); a++) {
                    if (valor == 0 && vector_hormiga[a].GetCordenadaX() == x && vector_hormiga[a].GetCordenadaY() == y) {
                        std::cout << vector_hormiga[a].GetDireccion();
                        valor = 1;
                    }
                }
                if (valor == 0)
                    std::cout << "X";
                break;
            }
            valor = 0;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for (unsigned a = 0; a < vector_hormiga.size(); a++) {
        posicion_anteriorx = vector_hormiga[a].GetCordenadaX();
        posicion_anteriory = vector_hormiga[a].GetCordenadaY();
        hormiga_posicion = mundo.GetPosicionHormiga(vector_hormiga[a].GetCordenadaX(), vector_hormiga[a].GetCordenadaY());
        vector_hormiga[a].Avanzar(hormiga_posicion);
        mundo.SetCambioValor(hormiga_posicion, posicion_anteriorx, posicion_anteriory); 
        mundo.Actualizar(vector_hormiga[a].GetCordenadaX(), vector_hormiga[a].GetCordenadaY());
    }

        contador ++;
        if(contador == 3) {
        std::cout<<"Quieres continuar realizando pasos"<<std::endl;
        std::cin >> respuesta;
        if(respuesta == "si") contador = 0;
        else contador = 4;
        }
    respuesta.clear();
    }while(contador <=3);

}