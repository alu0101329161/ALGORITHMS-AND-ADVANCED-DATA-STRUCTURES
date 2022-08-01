
/*
● Inserción
● QuicrecorridoSort
● Por Incrementos Decrecientes (ShellSort): debe permitir seleccionar la constante de
reducción alfa, siendo 0 < alfa < 1
● Selección
● MergeSort
● HeapSort
*/


#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

extern int modo;
extern int comparaciones;

class Miclave {
    private:
     int Clave;
    public:

    void Setter(int valor) {
        Clave = valor;
    }

    static int contador;
    bool operator == (Miclave clave) {
       contador ++;
       return Clave == clave.Clave;
    }
    bool operator > (Miclave clave) {
        contador ++;
        return Clave > clave.Clave;
    }
    bool operator < (Miclave clave) {
        contador ++;
        return Clave < clave.Clave;
    }
    void write() {
        std::cin >> Clave;
    }

    friend std::istream &operator>>(std::istream &is, Miclave& clave){
    clave.write();
    return is;
    }

    friend std::ostream &operator<<(std::ostream &os,const Miclave clave) {
    std::cout << clave.Clave;
    return os;
    }
};



template<class Clave>
void Mostrar(std::vector<Clave> &v, Clave pivote, int i, int f){
        // Imprimimos usando metodo Quicksort.
        if(modo == 0){
        getchar();
        std::cout<<"Pivote:"<<pivote<<", i ="<<i<<", f="<<f<<std::endl;
        for(int recorrido = 0; recorrido < v.size(); recorrido++){
            if(recorrido == i)
                std::cout<<termcolor::blue<<std::fixed<<std::setw(3)<<" "<<v[recorrido]<<termcolor::reset;
            else if( recorrido == f)
                std::cout<<termcolor::magenta<<std::fixed<<std::setw(3)<<" "<<v[recorrido]<<termcolor::reset;
            
            else
                std::cout<<" "<<v[recorrido];
        }
        
        std::cout<<std::endl;
    }

}


template<class Clave>
void Insercion(std::vector<Clave> &v, int tamano) {
    Clave aux;
    unsigned j;
    // Recorremos el vector desde la posicion 1 hasta el final.
    for(unsigned i = 1; i <= v.size()-1; i ++) {
        aux = v[i];
        if(modo == 0) {
            getchar();
            for(unsigned recorrido= 0; recorrido < v.size(); recorrido++)
                if(recorrido < i)
                    std::cout<<termcolor::green<<std::fixed<<std::setw(3)<<v[recorrido]<<" "<<termcolor::reset;
                else if(recorrido == i)
                    std::cout<<termcolor::red<<std::fixed<<std::setw(3)<<v[recorrido]<<" "<<termcolor::reset;
                else
                    std::cout<<std::fixed<<std::setw(3)<<v[recorrido]<<" ";
        }
        std::cout<<std::endl;
        j = i-1;
        // Se comprueba posicion actual con las anteriores.
        while(( j > 0 ) && ( aux < v[j] ) ) {
            comparaciones ++;
            v[j+1] = v[j];
            j --;
        }
        v[j+1] = aux;
    }
}



template<class Clave>
void OrdQuicksort(std::vector<Clave> &v, int ini, int fin) {
    int i = ini;
    int f = fin;
    Clave pivote = v[(i+f)/2];
    Clave swap;
    Mostrar(v,pivote,i,f);
    // Intercambiamos los valores que sean mayor y menor que el pivote.
    while(i <= f) {
        while(v[i] < pivote) { 
            comparaciones ++;
            i++;
            Mostrar(v,pivote,i,f);
        }
        while(v[f] > pivote){ 
            comparaciones ++;
            f--;
            Mostrar(v,pivote,i,f);    
        }
        if(i <= f) {
            comparaciones ++;
            swap = v[i];
            v[i] = v[f];
            v[f] = swap;
            i++;
            f--;
            Mostrar(v,pivote,i,f);
        }
    }
    // Realizamos lo mismo con las subcadenas.
    if(ini < f) {
        OrdQuicksort(v, ini, f);
    }
    if(i < fin) {
        OrdQuicksort(v, i, fin);
    }
}

template <class Clave> 
void Quicksort(std::vector<Clave> &v, int tam){
  OrdQuicksort(v,0,tam);
}


template<class Clave>
void Shellsort(std::vector<Clave> &v, unsigned d) {
    Clave x;
    unsigned j;
    unsigned it = 0;
    // Creamos valores de delta.
    while( d > 1) {
        d = d/2;
        std::cout<<"\t Delta: "<<d<<std::endl;
        for(unsigned i = d; i < v.size(); i++){
            x = v[i];
            j = i;
            it++;

            if(modo == 0) {
                getchar();
                std::cout<<"Iteracion: "<<it<<std::endl;
                for(unsigned recorrido = 0 ; recorrido < v.size(); recorrido++) 
                    if(recorrido == j)
                        std::cout<<termcolor::red<<std::fixed<<std::setw(3)<<v[j]<<"\t "<<termcolor::reset;
                    else if( recorrido == (j-d))
                        std::cout<<termcolor::red<<std::fixed<<std::setw(3)<<v[j-d]<<"\t "<<termcolor::reset;
                    else
                        std::cout<<v[recorrido]<<"\t ";
            }
            // Mientras no sea menor y no sea el final vamos moviendo los elementos.
            while((j >= d) && (x < v[j-d])){
                comparaciones ++;
                v[j] = v[j-d];
                j = j - d;
            }
            v[j] = x;
            
        }
    }
}


template<class Clave>
void Seleccion(std::vector<Clave> &v, int tamano) {

    int min;
    Clave aux;

    for (unsigned i = 0; i< v.size()-1; i++) {

        min = i;
        for (unsigned j = i+1; j< v.size(); j++) 
            if(v[j] < v[min])
            min = j;
        
    
        aux = v[min] ;
        v[min] = v[i] ;
        v[i] = aux ;
    }
}

template<class Clave>
void Mezcla(std::vector<Clave> &v, int ini, int cen, int fin) {
    Clave aux[v.size()];
    int i = ini;
    int j = cen+1;
    int k = ini;
    while((i <=cen) && (j <= fin)) {

        if(v[i] < v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
    k++;
    }
    if(i > cen)
        while(j <= fin) {
            aux[k] = v[j];
            j++;
            k++;
        }
    else
        while(i <= cen)
        {
            aux[k] = v[i];
            i++;
            k++;
        }
    for(int k = ini; k <= fin; k++)
        v[k] = aux[k];
}




template<class Clave>
void OrdMSort(std::vector<Clave> &v, int ini, int fin) {

    if(ini < fin) {
        int cen = (ini + fin) / 2;
        OrdMSort(v, ini, cen);
        OrdMSort(v, cen+1, fin);
        Mezcla(v, ini, cen, fin);
    }
}

template<class Clave>
void MSort(std::vector<Clave> &v, int tamano) {

    OrdMSort(v, 0, v.size()-1);

}


template<class Clave>
void Baja (int i, std::vector<Clave> &v,int n) {
    int larg = i;
    int h1 = 2*i +1;
    int h2 = 2*i + 2;
    
    if(modo == 0){
       getchar();

        for(int k = 0;k< n;k++){
            if(k == larg)
                std::cout<<termcolor::red<<v[k]<<" "<<termcolor::reset;
            else if( k == h1)
                std::cout<<termcolor::blue<<v[k]<<" "<<termcolor::reset;
            else if(k == h2)
                std::cout<<termcolor::yellow<<v[k]<<" "<<termcolor::reset;
            else
                std::cout<<v[k]<<" ";

        }
        std::cout<<std::endl;
    }
    
    
    if(h1 < n && v[h1] > v[larg]){
        larg = h1;
        std::cout<<"BAJA "<<std::endl;
    }
    if(h2 < n && v[h2]>v[larg]){
        larg = h2;
        std::cout<<" SUBE "<<std::endl;
    }
    if(larg != i){
        std::cout<<"COLOCADO "<<std::endl;
        Clave x = v[i];
        v[i] = v[larg];
        v[larg] = x;
        
        Baja(larg,v,n);
    }
}


template<class Clave>
void HeapSort(std::vector<Clave> &v, int tamano) {

    for (int i = (v.size()/2) -1; i >= 0; i--) {
        Baja(i,v,v.size());
    }
    for (int i = v.size() -1; i >= 1 ; i--) {
        Clave aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        Baja(0,v,i);
    }

}

