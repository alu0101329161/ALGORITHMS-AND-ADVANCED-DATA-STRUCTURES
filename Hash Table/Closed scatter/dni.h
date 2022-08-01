

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <string>



class Dni{
    
    public:
    
    Dni(void){
        numero_dni = 0;
    }
    
    Dni (long int dni){
        numero_dni = dni;
    }
    
    long int dni(void){
        return numero_dni;
    }

    std::string get_name(void) const{
    	return name;
    }

    void set_name(std::string name_){
    	name = name_;
    }
    
    long int operator% (const int& num){
        long int resultado = numero_dni % num;
        return resultado;
    }
    
    void operator= (const int& num){
        numero_dni = num;
    }
    
    bool operator== (const Dni& other) const{
        if (numero_dni == other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator== (const int& num) const{
        if (numero_dni == num)
            return true;
        else
            return false;
    }
    
    
    bool operator!= (const Dni& other){
        if (this->numero_dni == other.numero_dni)
            return false;
        else
            return true;
    }
    
    bool operator> (const Dni& other) const{
        if (this->numero_dni > other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator> (const int& num) const{
        if (this->numero_dni > num)
            return true;
        else
            return false;
    }
    
    bool operator< (const Dni& other){
        if (numero_dni < other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator>= (const Dni& other){
        if (numero_dni >= other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator<= (const Dni& other){
        if (numero_dni <= other.numero_dni)
            return true;
        else
            return false;
    }
    
    operator long int () const{
        return numero_dni;
    }

        
    private:
    
    long int numero_dni;
    std::string name;
    
};