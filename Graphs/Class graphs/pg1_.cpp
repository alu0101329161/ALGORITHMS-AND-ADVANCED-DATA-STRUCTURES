 /*
 *  PG1.CPP - Actividad I de Optimiza!cion.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Fecha : Marzo-2020
 */

#include <string.h>
#include "grafo.h"

void clrscr() //pijada
{
	system("cls");
}


void menu (unsigned dirigido, char &opcion)
{
    		if(dirigido==1) { 
            cout << "Actividad I, Optimizacion: carga del grafo y conectividad" << endl;
			cout << "////////////////////Optimizacion/////////////////////////" << endl;
			cout << "c. [c]argar grafo desde fichero." << endl;
			cout << "i. Mostrar [i]nformacion basica del grafo." << endl;
			cout << "s. Mostrar lista de [s]ucesores del grafo." << endl;
			cout << "p. Mostrar lista de [p]redecesores del grafo." << endl;
			cout << "q. Finalizar el programa" << endl;
			cout << "////////////////////Optimizacion/////////////////////////" << endl;
            cout << "Introduce la letra de la opcion a ejecutar > ";
		    cin >> opcion;
		    cout << endl;
            }
            else{
            cout << "Actividad I, Optimizacion: carga del grafo y conectividad" << endl;
            cout << "////////////////////Optimizacion/////////////////////////" << endl;
		    cout << "c. [c]argar grafo desde fichero." << endl;
		    cout << "i. Mostrar [i]nformacion basica del grafo." << endl;
		    cout << "a. Mostrar lista de [a]dyacencia." << endl;
		    cout << "o. Mostrar c[o]mponentes conexas del grafo." << endl;
		    cout << "q. Finalizar el programa" << endl;
		    cout << "////////////////////Optimizacion/////////////////////////" << endl;
            cout << "Introduce la letra de la opcion a ejecutar > ";
		    cin >> opcion;
		    cout << endl;
            }
};

// El principal es simplemente un gestor de menu, diferenciando acciones para grafo dirigido y para no dirigido
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;

	clrscr();
    //Cargamos por defecto el fichero que se pasa como argumento del ejecutable
	if (argc > 1)
    {
		cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
		clrscr();
    }
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero: revisa nombre y formato" << endl;
    }
    else
    {
        do
        {
            menu(G.Es_dirigido(), opcion);
            if(G.Es_dirigido()==1)
            {
                switch (opcion) 
				{
					case 'c':
							cout << "Introduzca el nombre del nuevo fichero a leer" << endl;
							cin >> nombrefichero;
                            clrscr();
							G.actualizar(nombrefichero,error_apertura);
							break;
					case 'i':
                            clrscr();
							G.Info_Grafo();
							break;
					case 's':
                            clrscr();
							G.Mostrar_Listas(0);  //sucesores
							break;
					case 'p':
                            clrscr();
							G.ListaPredecesores();  //predecesores
							break;
				}
			} 
		
		
    else {
        switch (opcion) 
		        {
				case 'c':
						cout << "Introduzca el nombre del nuevo fichero a leer" << endl;
						cin >> nombrefichero;
                        clrscr();
						G.actualizar(nombrefichero,error_apertura);
						break;
				case 'i':
                        clrscr();
						G.Info_Grafo();	
						break;
				case 'a':
                        clrscr();
						G.Mostrar_Listas(1);   //adyacencia
						break;
				case 'o':
                        clrscr();
						G.ComponentesConexas();
						break;		 
		        }
		      }
    }while (opcion != 'q');
};
cout << "Fin del programa" <<endl;
return(0);
};
