
#include "grafo.h"

GRAFO::~GRAFO()
{
	LS.clear();
	LP.clear();
}

void 
GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
	LS.clear();
	LP.clear();

    ElementoLista dummy;
	ElementoLista dummy2;
	ifstream fichero(nombrefichero);
	int i,j;

	if(!fichero) 
	{
		errorapertura==1;
		cout << "Error en la apertura del fichero: revisa nombre y formato" << endl;
	}
	else
	{
		errorapertura == 0;
		fichero >> n >> m >> dirigido;
		LS.resize(n);

		if(Es_dirigido() == 1)
		{
			LP.resize(n);
			for(int k = 0; k < m; k++)  
			{  
				fichero >> i >> j;
				dummy.j = j-1;
				LS[i-1].push_back(dummy);
			}
		}

		if(Es_dirigido() == 0)
		{
			for(int k = 0; k < m; k++)   
			{    
				fichero >> i >> j;
					dummy.j = j-1;
					LS[i-1].push_back(dummy);
					if(i != j)
					{
						dummy2.j = i-1;
						LS[j-1].push_back(dummy2);
				    }
			}
		}
	}
    
}

void 
GRAFO::Info_Grafo()                //Hecho por profe
{
    if (dirigido == 1)
    {
        cout << "Grafo dirigido ";
    }
    else
    {
        cout << "Grafo no dirigido ";
    };
    cout << " | nodos " << n << " | ";
    if (dirigido == 1)
    {
        cout << " arcos ";
    }
    else
    {
        cout << "aristas ";
    };
    cout << m << " " << endl;
}

unsigned 
GRAFO::Es_dirigido()                //Hecho por profe
{
	return dirigido;
}

void 
Mostrar_Lista(vector<LA_nodo> L)  //no uso
{
};

void 
GRAFO :: Mostrar_Listas (int l)  //la uso para imprimir los sucesores
{
	if(l == 0) 
	{
		cout << "Grafo dirigido." << endl;
		cout << "Nodos de la lista de sucesores:" << endl;

		for(int i = 0; i < LS.size(); i++) 
		{
			cout << "[" << i+1 << "]: ";
			for(int k = 0;k < LS[i].size(); k++) 
			{
				cout << LS[i][k].j+1 << "|";
			}
			cout << endl;
		}
	}
	if(l == 1)
	{
		cout << "Grafo no dirigido." << endl;
		cout << "Nodos de la lista de adyacencia: " << endl;

		for(int i = 0; i < LS.size(); i++) 
		{
			cout << "[" << i+1 << "]: ";
			for(int k = 0;k < LS[i].size(); k++) 
			{
				cout << LS[i][k].j+1 << "|";
			}
			cout << endl;
		}
	}
};

void 
GRAFO::dfs(unsigned i, vector<bool> &visitado)    //Hecho por profe
{
	visitado[i] = true;
    cout << i+1 << ", ";
	for (unsigned j=0;j<LS[i].size();j++)
             if (visitado[LS[i][j].j] == false)
                 dfs(LS[i][j].j, visitado);
}

void 
GRAFO::ComponentesConexas()       //Hecho
{
    vector<bool> visitado(n);      //vector de marca
	for(int i = 1; i < n; i++)
	{
		visitado[i] = false;
	}

	int contador = 0;

	for(int i = 0; i < n; i++)
	{
		if(visitado[i] == false)
		{
			cout << "Las componentes conexas de " << contador++ << " son: | ";
			dfs(i,visitado);
			cout << "|";
			cout << endl;
		}
	}
	if(contador <= 1)                   //si contador mayor q si significa q no desde cualquier nodo se llega a otro
		cout << "El grafo es conexo." << endl;
	else
		cout << "El grafo no es conexo." << endl;
}

void 
GRAFO::ListaPredecesores()   // la uso
{	
	ElementoLista dummy;                 //construyo lista de predecesores
	LP.resize(n);
	for(int i = 0; i < LS.size(); i++)
	{
		for(int k = 0;k < LS[i].size(); k++)
		{
			dummy.j = i;
			LP[LS[i][k].j].push_back(dummy);
		}
	}
	cout << "Grafo dirigido." << endl;
	cout << "Nodos de la lista de predecesores:" << endl;

		for(int i = 0; i < LP.size(); i++)             //imrpimo lo predecesores
		{
			cout << "[" << i+1 << "]: ";
			for(int k = 0; k < LP[i].size(); k++) 
			{
				cout << LP[i][k].j+1 << "|";
			}
			cout << endl;
        }
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)   //Hecho
{
    ElementoLista dummy;
	ElementoLista dummy2;
	ifstream fichero(nombrefichero);
	int i,j;

	if(!fichero) 
	{
		errorapertura==1;
		cout << "Error en la apertura del fichero: revisa nombre y formato" << endl;
	}
	else{
		errorapertura == 0;
		fichero >> n >> m >> dirigido;
		LS.resize(n);

		if(Es_dirigido() == 1)
		{
			LP.resize(n);
			for(int k = 0; k < m; k++) 
			{   
				fichero >> i >> j;
				dummy.j = j-1;
				LS[i-1].push_back(dummy);
			}
		}

		if(Es_dirigido() == 0)
		{
			for(int k = 0; k < m; k++) 
			{    
				fichero >> i >> j;
					dummy.j = j-1;
					LS[i-1].push_back(dummy);
					if(i != j)
					{
						dummy2.j = i-1;
						LS[j-1].push_back(dummy2);
		            }
			}
		}
	}
}




