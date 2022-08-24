#include <iostream>
using namespace std;
/* Aqui crear no es recursivo */
class Nodo
{
	public:
	int dato;
	Nodo *izq, *der;
	Nodo(){
		izq=der=NULL;
	}
};

class arbolBB
{
	public:
	Nodo *raiz;
	arbolBB()
	{
		raiz=NULL;
	}
	void crear(int);
	void completarArbol();
	void preOrden(Nodo*);
	void inOrden(Nodo*);
	void postOrden(Nodo*);
};
void arbolBB::crear(int nuevoDato)
{
	//Crea la raíz del arbol
	if(raiz==NULL)
	{
		raiz=new Nodo;
		raiz->dato=nuevoDato;
		raiz->izq=raiz->der=NULL;
		return;
	}
	//Crea un nodo y le asigna el nuevo dato, en el caso que ya exista raíz.
	Nodo *nuevoNodo,*r;
	nuevoNodo =new Nodo;
	nuevoNodo ->dato=nuevoDato;
	nuevoNodo ->izq= nuevoNodo ->der=NULL;
	//Inicializa r con la raiz
	r=raiz;
	while(r!=NULL) //Continua mientras la raíz no sea una hoja
	{
		// Si el nuevoDato es menor que el dato raíz entonces se mueve a la izquierda
		if(nuevoDato < r->dato)
		{
			// Si izq is NULL coloca el nuevoNodo a la izquierda.
			if(r->izq==NULL)
			{
				r->izq=nuevoNodo;
				break;
			}
			r=r->izq; // Si no mueve la raíz al nodo de la izquierda
		}
		// Si el nuevoDato es mayor que el dato raíz entonces se mueve a la derecha
		else if(nuevoDato > r->dato)
		{
		// Si der is NULL coloca el nuevoNodo a la derecha.
		if(r->der==NULL)
		{
			r->der=nuevoNodo;
			break;
		}
			r=r->der; // Si no mueve la raíz al nodo de la derecha
		}
	}	
}

void arbolBB::completarArbol()
{
	int n,dato;
	cout<<"Cuantos nodos desea insertar: ";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"Dato "<<i<<": ";
		cin>>dato;
		crear(dato);
	}
}

void arbolBB::preOrden(Nodo* raiz)
{
	if (raiz!=NULL)
	{
		cout<<raiz->dato<<"-";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}	
}
void arbolBB::postOrden(Nodo* raiz)
{
	if (raiz != NULL)
	{
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout << raiz->dato << "-";
	}
}
void arbolBB::inOrden(Nodo* raiz)
{
	if (raiz != NULL)
	{
		inOrden(raiz->izq);
		cout << raiz->dato << "-";
		inOrden(raiz->der);
	}
}

int main()
{
	arbolBB ar;
	ar.completarArbol();
	cout<<"Preorden\n";
	ar.preOrden(ar.raiz);
	return 0;
}