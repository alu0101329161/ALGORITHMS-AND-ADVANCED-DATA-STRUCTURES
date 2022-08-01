 /*
 *  GRAFO.CPP - Implementación de la clase GRAFOS
 *
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Fecha : 2013-2020
 */

#include "grafo.h"

GRAFO::~GRAFO() //no Lo uso 
{
    LS.clear(); //resteo ls
	LP.clear(); //reseteo lp
}

void 
GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    LS.clear(); //resteo ls
	LP.clear(); //reseteo lp

	ifstream textfile; 
    textfile.open(nombrefichero);
    
    if (!textfile.is_open())
    {
        errorapertura==1;
    }
    else
    {
       errorapertura == 0;
       textfile >> (unsigned&)n >> (unsigned&)m >> (unsigned&)dirigido;
       LS.resize(n);
       ElementoLista dummy,dummy1;
       unsigned i,j,c,k;

       for(int k =0; k < m; k++)
       {
           textfile >> i >> j >> c;
            if(dirigido == 0)                
            {
                dummy.c = c;
                dummy.j = j -1;
                LS[i - 1].push_back(dummy);
                if(i != j)
                {
                    dummy1.c = c;
                    dummy1.j = i -1;           
                    LS[j - 1].push_back(dummy1);
                }
            }
            if(dirigido == 1)                  
            {
                LP.resize(n);
                dummy.c = c;
                dummy.j = j -1;
                LS[i - 1].push_back(dummy);

                dummy1.c = c;
                dummy1.j = i -1;           
                LP[j - 1].push_back(dummy1);
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
Mostrar_Lista(vector<LA_nodo> L)  //Hecho
{
	 for (unsigned i = 0; i < L.size(); i++)                                     
    {
        cout << " Nodo[" << i + 1 << "]: {";                                   

        for (unsigned j = 0; j < L[i].size(); j++)                               
        {
            if(j != 0)
            { 
                cout << " || ";                          //ponga coma despues de cada arista y separarlas con sus costes
            }
            cout << L[i][j].j + 1 << "(" << L[i][j].c << ")";             
        }
        cout << "}" << endl;
    }
};

void 
GRAFO :: Mostrar_Listas (int l) //Antes lo usaba de peor forma
{
	if (l == 0 || l == 1)
        Mostrar_Lista(LS);                   //sucesores o adyacentes
    else if (l == -1)
        Mostrar_Lista(LP);                  //predecesores 
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
GRAFO::ComponentesConexas()                      //Hecho
{
    vector<bool> visitado(n);                    //vector de marca
	for(int i = 1; i < n; i++)
	{
		visitado[i] = false;                    //cuando visita vector marca =  false 
	}

	int contador = 0;                            //contador q almacena el numero de componentes conexas

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
	if(contador <= 1)                          //si contador >1 ->no conexo
		cout << "El grafo es conexo." << endl;
	else
		cout << "El grafo no es conexo." << endl;
}
void GRAFO::Kruskal()  //hecho
{
    vector <AristaPesada> Aristas;
    Aristas.resize(m);

    unsigned k = 0;  //RECORRE TODO EL GRAFO
    for (unsigned i = 0; i<n; i++){
        for (unsigned j=0; j<LS[i].size();j++){
            if (i < LS[i][j].j) {
                Aristas[k].extremo1 = i;
                Aristas[k].extremo2 = LS[i][j].j;
                Aristas[k++].peso = LS[i][j].c;
                }
        }
    };
    /*Inicializamos el indice a la cabeza del vector*/
    unsigned head = 0;
    AristaPesada AristaDummy; //Para los intercambios en la ordenacion parcial
    /*Inicializamos el contador de aristas en la solucion*/
    unsigned a = 0;
    /*Inicializamos el peso de la solucion*/
    unsigned pesoMST = 0;
    /*Inicializamos el registro de componentes conexas: cada nodo esta en su compomente conexa*/
    vector <unsigned> Raiz;
    Raiz.resize(n);
    for (unsigned q = 0;q < n; q++){
        Raiz[q]=q;
    };
    /*Comenzamos Kruskal*/
    do {
		unsigned Candidata = head;
        for (unsigned i = head + 1; i < m; i++)
            if (Aristas[i].peso < Aristas[Candidata].peso)
                Candidata = i;
        if (Candidata != head)
        {
            AristaDummy = Aristas[Candidata];
            for (unsigned j = Candidata; j > head; j--)
            Aristas[j] = Aristas[j - 1];
            Aristas[head] = AristaDummy;
        }
        if (Raiz[Aristas[head].extremo1] != Raiz[Aristas[head].extremo2])
        {
            a++;
            for (unsigned i = 0; i < n; i++)
                if (Raiz[i] == Raiz[Aristas[head].extremo2] && i != Aristas[head].extremo2)
                    Raiz[i] = Raiz[Aristas[head].extremo1];
            cout << "|| Arista numero " << a << " incorporada( " << Aristas[head].extremo1+1 << "," << Aristas[head].extremo2+1 << " ), con coste -->"<< Aristas[head].peso << endl;
            Raiz[Aristas[head].extremo2] = Raiz[Aristas[head].extremo1];
            pesoMST += Aristas[head].peso;
        }

        head++;
        } while ((a < (n-1)) && (head < m));

        if (a == (n - 1)){
            cout << "El peso del arbol generador de minimo coste es " << pesoMST << endl;
        }
        else {
            cout << "El grafo no es conexo, y el bosque generador de minimo coste tiene peso " << pesoMST << endl;
        };
}

void 
GRAFO::ListaPredecesores() //antes lo usaba
{	
}

//Por ello, el siguiente procedimiento recursivo, recorre el vector pred , mostrando los caminos
//mínimos almacenados

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred)      //Hecho profe
{
  if (i != s)
  {
    MostrarCamino(s,pred[i],pred);
    cout << pred[i]+1 << "->";
  }
}

void GRAFO::Dijkstra()
{
  vector<bool> Perma_Etiquetado;
  vector<int> d;
  vector<unsigned> pred;
  int minimo;
  unsigned s, candidato;                                      
  //Inicialmente no hay ningun nodo permanentemente etiquetado
  Perma_Etiquetado.resize(n,false);     
  //Inicialmente todas las etiquetas distancias son infinito                      
  d.resize(n,maxint); 
  //Inicialmente el pred es null                                       
  pred.resize(n,UERROR);                                     
  //Solicitamos al usuario nodo origen
  cout << endl;
  cout << "Caminos minimos: Dijkstra" << endl;
  cout << "Nodo de partida? [1-"<< n << "]: ";
  cin >> (unsigned &) s;
  //La etiqueta distancia del nodo origen es 0, y es su propio pred                                    
  d[--s]=0; pred[s]=s;
  do
  {
     minimo = maxint;                                                                                  
	for (int i = 0 ; i<n; i++)
    {
		if((Perma_Etiquetado[i] == false) && (minimo == maxint || d[minimo] > d[i]))
        {
			if(d[i] != maxint)
            {
				minimo = i;
			}
		}
	}
	if (minimo < maxint)
    {
		Perma_Etiquetado[minimo] = true;
		for (int j = 0; j < LS[minimo].size(); j++)
        {
			if(Perma_Etiquetado[LS[minimo][j].j]==false)
            {
				if (LS[minimo][j].c + d[minimo] < d[LS[minimo][j].j])
                {
					d[LS[minimo][j].j] = LS[minimo][j].c + d[minimo];
					pred[LS[minimo][j].j] = minimo;
				}
			}
		}
    }
  }while( minimo < maxint );

  cout << "Soluciones: " << endl;
  for (int i = 0; i<n; i++)
  {
		if(i != s)
        {
			if (pred[i] != UERROR)
            {
				cout << "\nCamino minimo de " << s+1 << " a " << i+1 << ": { ";
				MostrarCamino(s,i,pred);
				cout << i+1 << "} \t-de longitud " << d[i]<< endl;
			}				
			else
				cout << "\nNo hay caminos minimos de " << s+1 << " a " << i+1 << endl;
		}
  }
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)   //Hecho
{  
 actualizar(nombrefichero, errorapertura);                //lamo a actualizar para no repetir código
}



