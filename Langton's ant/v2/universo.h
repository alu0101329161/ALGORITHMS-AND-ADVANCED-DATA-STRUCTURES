

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "mundo.h"
#include "hormiga.h"

class Universo {

    public:

    Universo (int& , int&);
    ~Universo ();


    void RunSystem();


    private:

    std::vector<Hormiga> vector_hormiga;
    Mundo mundo;

};