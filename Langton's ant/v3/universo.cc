
#include "universo.h"

Universo::Universo(Mundo* mundo, std::vector<Hormiga>& vector_hormigas) 
{
    contador1 = 0;
    int contador = 0, vhormiga;
    int posx, posy;
    bool valor = true;
    std::string respuesta;
    do {

    OrdenarHormigas(vector_hormigas);
    Contador(mundo, vector_hormigas);
    
    for(int y = mundo->GetMinY(); y < mundo->GetMaxY() ; y++) {
        for(int x = mundo->GetMinX(); x < mundo->GetMaxX(); x++) {

            switch (mundo->GetTablero(y, x))
            {
            case 0:
                for (unsigned a = 0; a < vector_hormigas.size(); a++) {
                    if (valor == true && vector_hormigas[a].GetCordenadaX() == x && vector_hormigas[a].GetCordenadaY() == y) {
                        vector_hormigas[a].GetCabeza();
                        valor = false;
                    }
                }
                if (valor)
                    std::cout << "\u2588";
                break;
            case 1:
                for (unsigned a = 0; a < vector_hormigas.size(); a++) {
                    if (valor == true && vector_hormigas[a].GetCordenadaX() == x && vector_hormigas[a].GetCordenadaY() == y) {
                        vector_hormigas[a].GetCabeza();
                        valor = false;
                    }
                }
                if (valor)
                    std::cout << " ";
                break;
            }
            valor = true;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for (unsigned a = 0; a < vector_hormigas.size(); a++) {
        posx = vector_hormigas[a].GetCordenadaX();
        posy = vector_hormigas[a].GetCordenadaY();

        vhormiga = mundo->GetTablero(posy, posx);
        vector_hormigas[a].ActualizarMovimiento(vhormiga);
        
        mundo->SetCambioValor(vhormiga, posx, posy);
        mundo->Actualizar(vector_hormigas[a]);
    }

 contador ++;
 if(contador == 3) {
  std::cout<<"Quieres continuar realizando pasos"<<std::endl;
  std::cin >> respuesta;
  if(respuesta == "1") contador = 0;
  else contador = 4;
 }
 respuesta.clear();
}while(contador <=3);

std::cout<< contador1;

}



Universo::~Universo() {}



void
Universo::OrdenarHormigas(std::vector<Hormiga>& vector) {

  Hormiga auxiliar;

  for (unsigned i = 0; i < vector.size(); i ++) {
    for (unsigned j = i + 1; j < vector.size(); j++) {

      if (vector[i].GetCordenadaY() > vector[j].GetCordenadaY() || 
         (vector[i].GetCordenadaY() == vector[j].GetCordenadaY() && 
         vector[i].GetCordenadaX() > vector[j].GetCordenadaX())) {

        auxiliar = vector[i];
        vector[i] = vector[j];
        vector[j] = auxiliar;
      }
    }
  }

  //for (unsigned i = 0; i < vector.size(); i ++) {
    //for (unsigned j = i + 1; j < vector.size(); j++) {

      //if(vector[i].GetCordenadaY() == vector[j].GetCordenadaY() && vector[i].GetCordenadaX() == vector[j].GetCordenadaX())
       //contador1 ++;

    
  
}

void
Universo::Contador(Mundo* mundo, std::vector<Hormiga>& vector_hormigas) {
    int aux = 0;

    for(int y = mundo->GetMinY(); y < mundo->GetMaxY() ; y++) {
        for(int x = mundo->GetMinX(); x < mundo->GetMaxX(); x++) {

             for (unsigned a = 0; a < vector_hormigas.size(); a++) {

                 if(vector_hormigas[a].GetCordenadaX()== x && vector_hormigas[a].GetCordenadaY() == y)
                 aux ++;
                 }

             if(aux > 1) {contador1++;}
              aux = 0;
        }
    }

}