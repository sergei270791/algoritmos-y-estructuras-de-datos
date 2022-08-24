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
	void crearNuevoArco(string, string, int);
	int maxNumVertice() { return maxVerts; }; //Devuelve el numero maximo de vertices del grafo
	void mostrarMatriz();
	void completarGrafo();
	void completarArcos();
	bool adyacente(int,int);
	bool adyacente(string,string);
	int obtenerValor(string,string);
	void pesoValor(string,string,int);
	Vertice obtenerVertice(string);
	void reemplazarVertice(int,Vertice);
	Vertice obtenerVertice(int);
    int** getMatriz(){ return matAd; };
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
	int i=buscarNumVertice(nom);
	if (i==-1)
	{
		Vertice v=Vertice(nom,numVerts);
		verts[numVerts]=v;
		numVerts++;
	}
	return;
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
void GrafoMatriz::crearNuevoArco(string a, string b, int peso) 
{
	int inda=buscarNumVertice(a);
	int indb=buscarNumVertice(b);
	if(inda!=-1 && indb!=-1)
	    matAd[inda][indb]=peso;
	else
		return;
}
void GrafoMatriz::crearNuevoArco(int inda, int indb) 
{
	if(inda>=0 && indb>=0 && inda<numVerts && indb<numVerts)
	    matAd[inda][indb]=1;
	else
		return;
}
void GrafoMatriz::crearNuevoArco(int inda, int indb, int peso) 
{
	if(inda>=0 && indb>=0 && inda<numVerts && indb<numVerts)
	    matAd[inda][indb]=peso;
	else
		return;
}
void GrafoMatriz::mostrarMatriz()
{
	for (int i=0;i<numVerts;i++)
	{
		for (int j=0;j<numVerts;j++)
			cout<<matAd[i][j]<<"   ";
		cout<<endl;
	}
}
void GrafoMatriz::completarGrafo()
{
	int n;
	string nombre;
	cout<<"Ingrese la cantidad de vertices: ";
	cin>>n;
	if (n>maxVerts)
		return;
	else
		for (int i=0;i<n;i++)
		{
			cout<<"Nombre "<<i<<": ";
			cin>>nombre;
			crearNuevoVertice(nombre);
		}
}
void intercambiar(string& x, string& y) {
	string temp = x;
	x = y;
	y = temp;
}

void ordBurbuja(string vector[], int n){
	bool flag=true;	
	for(int i = 0; i<n-1;i++)
	{
		flag=false;
		for (int j=0 ;j<n-1-i; j++)
			if (vector[j]>vector[j+1])
			{
				intercambiar(vector[j],vector[j+1]);
				flag=true;
			}
		if (!flag)
			return;
	}	
}
void GrafoMatriz::completarArcos()//Mediante indices y peso
{
	int i,n;
	n=numVerts;
	string arrayElementos[n];
	for(i=0;i<n;i++)
	{	
		arrayElementos[i]=verts[i].getNombre();
	}
	ordBurbuja(arrayElementos,n);
	for (i = 0; i < n-2; i++)
	{	
		crearNuevoArco(arrayElementos[i], arrayElementos[i+1]);
		crearNuevoArco(arrayElementos[i+1], arrayElementos[i]);
		crearNuevoArco(arrayElementos[i], arrayElementos[n-1]);
		crearNuevoArco(arrayElementos[n-1], arrayElementos[i]);
	}
	crearNuevoArco(arrayElementos[n-2], arrayElementos[0]);
	crearNuevoArco(arrayElementos[0], arrayElementos[n-2]);
	crearNuevoArco(arrayElementos[n-2], arrayElementos[n-1]);
	crearNuevoArco(arrayElementos[n-1], arrayElementos[n-2]);
}
bool GrafoMatriz::adyacente(int inda,int indb)
{
	if(inda>=0 && indb>=0 && inda<numVerts && indb<numVerts)
	    return getCasilla(indb,inda)>0;
	return false;
}
bool GrafoMatriz::adyacente(string a,string b)
{
	int inda=buscarNumVertice(a);
	int indb=buscarNumVertice(b);
	if(inda!=-1 && indb!=-1)
	    return getCasilla(indb,inda)>0;
	return false;
}
int GrafoMatriz::obtenerValor(string a,string b)
{
	int inda=buscarNumVertice(a);
	int indb=buscarNumVertice(b);
	if(inda!=-1 && indb!=-1)
	    return matAd[inda][indb];
	return -1;
}
void GrafoMatriz::pesoValor(string a,string b,int peso)
{
	int inda=buscarNumVertice(a);
	int indb=buscarNumVertice(b);
	if(inda!=-1 && indb!=-1 && peso>=0)
	    matAd[inda][indb]=peso;
	return;
}
Vertice GrafoMatriz::obtenerVertice(string nom)
{
	int ind;
	ind=buscarNumVertice(nom);
	return obtenerVertice(ind);
}
Vertice GrafoMatriz::obtenerVertice(int i)
{
	if (i>=0)
		return verts[i];
	/* Las 2 lineas siguientes son para evitar error */
	Vertice v=Vertice();
	return v;
}
void GrafoMatriz::reemplazarVertice(int ind,Vertice nuevo)
{
	if (ind>=0 && ind<numVerts)
	{
		nuevo.setNumVertice(ind);
		verts[ind]=nuevo;
	}
}

int main()
{
	GrafoMatriz miGrafo(10);
	miGrafo.completarGrafo();
	miGrafo.completarArcos();
	miGrafo.mostrarMatriz();
	return 0;
}