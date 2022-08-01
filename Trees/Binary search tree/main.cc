/** Univerdidad: Universidad de La Laguna.
* Grado:       Grado de ingeniería informática.
*  Asignatura:  Asignatura de algoritmos y estructura de datos avanzada.
*  Autor:       Joseph Gabino Rodríguez
*  Correo:      alu0101329161@ull.edu.es
*  Práctica nº: 1
*  Comentario:  Práctica 9: Implementación de árboles binarios equilibrados
*               
*  Compilar:    g++ -g -o main main.cc

1. Generar un ABB vacío.
2. Presentar un menú con las siguientes opciones:
[0] Salir
[1] Insertar Clave
[2] Buscar Clave
3. Para cada inserción o búsqueda, solicitar el valor de clave y realizar la operación en el ABB.
4. Tras cada operación de inserción, mostrar el árbol resultante mediante un recorrido por
niveles. En cada nivel se muestran los nodos de izquierda a derecha. El subárbol vacío se
visualiza con [.].
*/

#include "termcolor.hpp"
#include "ABB.h"

#include <iostream>


bool value;

int main(void) {

    int opcion = 0;
    std::cout << "Creando arbol binario de busqueda vacio...";
    ABB<int> ABB;  
    std::cout << std::endl;
    ABB.RecorridoN();  
    std::cout << std::endl;


    while (opcion != 5) {  
        std::cout << std::endl;
        std::cout << "----- MODO DEMOSTRACION -----" << std::endl;
        std::cout << "\t1. Insertar clave" << std::endl;
        std::cout << "\t2. Buscar clave" << std::endl;
        std::cout << "\t3. Eliminar clave" << std::endl;
        std::cout << "\t4. Mostrar Recorridos" << std::endl;
        std::cout << "Elija la operación: ";
        std::cin >> opcion;
        std::cout << std::endl;
        value = false;

        int aux; 
                    
        switch (opcion) {
            case 1:
                std::cout << "Introduzca la clave a insertar: ";
                std::cin >> aux;
                ABB.Insertar(aux);  
                std::cout << std::endl;
                ABB.RecorridoN();
                std::cout << std::endl;
            break;

            case 2:
                std::cout << "Introduzca la clave a buscar: ";
                std::cin >> aux;
                ABB.Buscar(aux);
                if(value)
                    std::cout<<"Valor encontrado";
                else
                 std::cout<<"Valor no encontrado";
                
            break;
                        
            case 3:
                std::cout << "Introduzca la clave a eliminar: ";
                std::cin >> aux;
                ABB.Eliminar(aux);  
                std::cout << std::endl;
                ABB.RecorridoN();
                std::cout << std::endl;
            break;

            case 4:
                ABB.MostrarRecorrido();  
            break;
        }
    }
return 0;
}