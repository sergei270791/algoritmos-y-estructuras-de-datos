//Arbol Binario de busqueda
#include <iostream>
using namespace std;
class Nodo
{
public:
	int dato;
	Nodo* izq, * der;
	Nodo() {
		izq = der = NULL;
	}
};
class arbolBB
{
public:
	Nodo* raiz;
	arbolBB()
	{
		raiz = NULL;
	}
	void crear(int);
	void crear(Nodo*, int);
	void completarArbol();
	void completarArbol(int [],int);
	void preOrden(Nodo*);
	arbolBB preOrdenPar(Nodo*,arbolBB);
	arbolBB preOrdenImpar(Nodo*,arbolBB);
	void par();
	void impar();
	void inOrden(Nodo*);
	void postOrden(Nodo*);
	int contarNodos(Nodo*);
	int encontrarAltura(Nodo*);
	void porAnchura();
	void verNivel(Nodo*,int n);
	Nodo* busqueda(int);
	void borrarNodo(int);
	
};
// Funcion para la llamada recursiva
void arbolBB::crear(int nuevoDato)
{
	if (raiz==NULL) //Si no tiene raíz, crea el nodo raiz
	{
		raiz=new Nodo;
		raiz->dato=nuevoDato;
		return;
	}
	Nodo *r=raiz;
	crear(r, nuevoDato); //Llamada a la función recursiva
}
// Funcion recursiva
void arbolBB::crear(Nodo *r, int nuevoDato)
{	
	if (nuevoDato < r->dato) // Si el nuevoDato es menor que el dato raíz entonces se mueve a la izquierda
	{
		if(r->izq==NULL) // Si izq is NULL coloca el nuevoNodo a la izquierda.
		{
			Nodo *nuevoNodo;
			nuevoNodo=new Nodo;
			nuevoNodo->dato=nuevoDato;
			r->izq=nuevoNodo;
			return;
		}
		crear(r->izq, nuevoDato); // Si no mueve la raíz al nodo de la izquierda
	}
	else 
	{
		if (nuevoDato> r->dato) // Si el nuevoDato es mayor que el dato raíz entonces se mueve a la derecha
		{
			if(r->der==NULL) // Si der is NULL coloca el nuevoNodo a la derecha.
			{
				Nodo *nuevoNodo=new Nodo;
				nuevoNodo->dato=nuevoDato;
				r->der=nuevoNodo;
				return;
			}
			crear(r->der, nuevoDato); // Si no mueve la raíz al nodo de la derecha
		}
	}
}

void arbolBB::completarArbol()
{
	int n, dato;
	cout << "Cuantos nodos desea insertar: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Dato " << i << ": ";
		cin >> dato;
		crear(dato);
	}
}
////Sobrecarga de completarArco()
void arbolBB::completarArbol(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
	crear(a[i]);
	}
}
////
void arbolBB::preOrden(Nodo* raiz)
{
	if (raiz != NULL)
	{
		cout << raiz->dato << "-";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
arbolBB arbolBB::preOrdenPar(Nodo* raiz,arbolBB arbolPar){
	if (raiz != NULL)
	{	
		if(raiz->dato%2==0){
			arbolPar.crear(raiz->dato);
		}
		preOrdenPar(raiz->izq,arbolPar);
		preOrdenPar(raiz->der,arbolPar);
	}
	return arbolPar;
}

arbolBB arbolBB::preOrdenImpar(Nodo* raiz,arbolBB arbolImpar){
	if (raiz != NULL)
	{	
		if(raiz->dato%2==1){
			arbolImpar.crear(raiz->dato);
		}
		preOrdenImpar(raiz->izq,arbolImpar);
		preOrdenImpar(raiz->der,arbolImpar);
	}
	return arbolImpar;
}
//Recorrer árbol por anchura (por nivel)
int arbolBB::encontrarAltura(Nodo* r)
{
	if (r == NULL)
		return 0;
	else
	{
		if (r->izq == NULL && r->der == NULL)
			return 1;
		else if (r->izq == NULL)
			return 1 + encontrarAltura(r->der);
		else if (r->der == NULL)
			return 1 + encontrarAltura(r->izq);
		else
			return 1 + max(encontrarAltura(r->izq),encontrarAltura(r->der));
	}
}
void arbolBB::porAnchura() 
{
	int nivel=0,niveles;
	niveles=encontrarAltura(raiz)-1;
	while(nivel<=niveles)
	{
		verNivel(raiz,nivel);
		nivel++;
		cout<<endl;
	}
}
void arbolBB::verNivel(Nodo* r, int n) 
{
	if (n > 0) {
		if(r->izq != NULL)
			verNivel(r->izq, n - 1);
		if(r->der != NULL)
			verNivel(r->der, n - 1);
	}
	else {
		cout << r->dato << "-";
	}
}

void arbolBB::par(){
	arbolBB arbolPar;
	arbolPar=preOrdenPar(raiz,arbolPar);
	cout<<"\nPor anchura\n";
	arbolPar.porAnchura();
	cout << "\nPreorden\n";
	arbolPar.preOrden(arbolPar.raiz);
}


void arbolBB::impar(){
	arbolBB arbolImpar;
	arbolImpar=preOrdenImpar(raiz,arbolImpar);
	cout<<"\nPor anchura\n";
	arbolImpar.porAnchura();
	cout << "\nPreorden\n";
	arbolImpar.preOrden(arbolImpar.raiz);
}


int main()
{
	arbolBB ar;
	/////////////////////////
    int A[] = {340,151,346,79,268,345,384,17,137,180,
			306,354,474,4,34,104,153,188,292,331,356,457,
			497,77,278,308,416,467,273,322};
    int n = sizeof(A) / sizeof(int);
    cout << "Datos: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << "  ";
    ar.completarArbol(A, n);
	///////////////////////
	cout<<"\nPor anchura\n";
	ar.porAnchura();
	cout << "\nPreorden\n";
	ar.preOrden(ar.raiz);
	cout<<"\nPara el arbol Par:\n";
	ar.par();
	cout<<"\nPara el arbol Impar:\n";
	ar.impar();
	return 0;
}