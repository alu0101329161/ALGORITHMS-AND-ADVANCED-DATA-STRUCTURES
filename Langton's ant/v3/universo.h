

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "mundo.h"
#include "hormiga.h"

class Universo {

    public:

    Universo (Mundo*, std::vector<Hormiga>&);
    ~Universo ();

   
    void RunSystemFinito();
    void RunSystemInfinito();
    void Contador(Mundo*, std::vector<Hormiga>&);

    void OrdenarHormigas(std::vector<Hormiga>&);
    private:
    int contador1;
};