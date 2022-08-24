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
	int contarNodos(Nodo*);
	int encontrarAltura(Nodo*);
	void borrarNodo(int);
};

bool compararElementosNodo(Nodo *r1,Nodo *r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }
    if(r2!=NULL && r1==NULL){
        return false;
    }
    if(r1->dato==r2->dato){
        if(!compararElementosNodo(r1->der,r2->der)){
            return false;
        }
        if(!compararElementosNodo(r1->izq,r2->izq)){
            return false;
        }
        return true;
    }else{
        return false;
    }
    

}

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

int arbolBB::contarNodos(Nodo* r)
{
	if (r==NULL)
		return 0;
	else
	{
		return 1+contarNodos(r->izq)+contarNodos(r->der);
	}
}
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

string compararArbol(arbolBB a,arbolBB b){
    string respuesta="NO";
    if (a.raiz==NULL && b.raiz == NULL) {  /* si los arboles son vacios */
        respuesta="SI";
        return respuesta;
    }
    if(a.raiz->dato!=b.raiz->dato || a.contarNodos(a.raiz)!=b.contarNodos(b.raiz) || a.encontrarAltura(a.raiz)!=b.encontrarAltura(b.raiz)){   
        return respuesta;
    }
    Nodo *nodoA=a.raiz;
    Nodo *nodoB=b.raiz;
    bool res=compararElementosNodo(nodoA,nodoB);
    if(res){
        respuesta="SI";
    }else{
        respuesta="NO";
    }
    return respuesta;
}

int main()
{
    arbolBB a;
    arbolBB b;
    a.completarArbol();
    b.completarArbol();
    cout<<"\nComparando el arbol a y b"<<endl;
    cout<<"\nSon iguales: "<< compararArbol(a,b) <<endl; //La respuesta es SI o NO
    return 0;
}