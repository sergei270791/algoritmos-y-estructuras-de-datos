//Grafos Matriz de Adyacencia
#include <iostream>
#include <string>
using namespace std;
class Vertice
{
private:
	string nombre;
	int numVertice;
public:
	Vertice() {} //Vertice vacio
	Vertice(string x)
	{ // inicializa el nombre y pone el número de vértice e -1
		nombre = x;
		numVertice = -1; //No pertenece a ningun grafo
	}
	Vertice(string x, int n)
	{ // inicializa el nombre y el número de vértice
		nombre = x;
		numVertice = n;
	}
	string getNombre()
	{ // retorna el nombre del vértice
		return nombre;
	}
	void setNombre(string nom)
	{ // cambia el nombre del vértice
		nombre = nom;
	}
	bool igual(string nom)
	{ // Comprueba la igualdad de nombres
		return nombre == nom;
	}
	void setNumVertice(int n)
	{ // cambia el número del vértice
		numVertice = n;
	}
	int getNumVertice()
	{ // retorna el número del vértice
		return numVertice;
	}
};
class GrafoMatriz
{
private:
	int maxVerts; // máximo numero de vértices
	int numVerts; // número de vértices actual
	Vertice* verts; // vector de vértices
	int** matAd; // matriz de adyacencia
public:
	GrafoMatriz(int mx)
	{
		maxVerts = mx;
		verts = new Vertice[mx]; // crea vector de vértices vacios
		matAd = new int* [mx]; // crea vector de punteros a enteros
		numVerts = 0; // inicializa numVerts a 0 o sea sin vertices
		for (int i = 0; i < mx; i++)
			matAd[i] = new int [mx] {}; // crea matriz de adyacencia con ceros
	}
	int getCasilla(int i, int j) { return matAd[i][j]; } //Devuelve el
	//contenido de la celda(i,j) de la matriz de adyacencia
	void setCasilla(int i, int j, int n) { matAd[i][j] = n; } //Fija el
	//contenido de la celda(i,j) de la matriz de adyacencia a n
	int getNumDeVertices() { return numVerts; } //Devuelve el
	//numero de vertices del grafo
	void setNumDeVertices(int n) { numVerts = n; } //Fija el
	//numero de vertices del grafo a n
	int buscarNumVertice(string); //Devuelve el numero asignado al vertice
	void crearNuevoVertice(string); //Crea nuevo vertice
	void crearNuevoArco(string, string); //Crea un nuevo arco haciendo
				//referencia a sus nombres
	void crearNuevoArco(int, int); //Crea un nuevo arco haciendo
				//referencia al numero de su vertice
	void crearNuevoArco(int, int, int); //Crea un nuevo arco haciendo referencia
		//al numero de su vertice, pero coloca el peso (ultimo argumento)
		// en la matriz de adyacencia.
	int maxNumVertice() { return maxVerts; }; //Devuelve el numero maximo de vertices del grafo
};
int GrafoMatriz::buscarNumVertice(string nom)
{
	int i;
	for (i=0;i<numVerts;i++)
		if (verts[i].igual(nom))
			return i;
	return -1;
}
void GrafoMatriz::crearNuevoVertice(string nom)
{
	int i;
	for (i=0;i<numVerts;i++)
		if (verts[i].igual(nom))
			return;
	verts[numVerts].setNombre(nom);
	numVerts++;	
}
void GrafoMatriz::crearNuevoArco(string a, string b) 
{
	int inda=buscarNumVertice(a);
	int indb=buscarNumVertice(b);
	if(inda!=-1 && indb!=-1)
	    matAd[inda][indb]=1;
	else
		return;
}
int main()
{
	GrafoMatriz miGrafo(10);
	miGrafo.crearNuevoVertice("uno");
	miGrafo.crearNuevoVertice("dos");
	miGrafo.crearNuevoVertice("tres");
	miGrafo.crearNuevoVertice("cuatro");
	miGrafo.crearNuevoVertice("dos"); //Repetido
	miGrafo.crearNuevoVertice("tres"); //Repetido
	miGrafo.crearNuevoVertice("cinco");
	/*cout<<miGrafo.getNumDeVertices()<<endl;  //Devuelve 5
	cout<<"El indice de \"tres\" es: "<<miGrafo.buscarNumVertice("tres")<<endl; //devuelve 2
	cout<<"El indice de \"cinco\" es: "<<miGrafo.buscarNumVertice("cinco")<<endl; //devuelve 4*/
	return 0;
}