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
//Recorrer árbol por anchura (por nivel)
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
void arbolBB::borrarNodo(int dato)
{
	Nodo *r,*padre,*Mizq;
	padre=NULL;
	r=raiz;
	//Localizar al nodo del dato y al padre
	if (r==NULL)
	{
		cout<<"El arbol esta vacio\n";
		return;
	}
	else
	{
		while(r!=NULL)
		{
			if (r->dato==dato)
				break;
			padre=r;
			if (dato<r->dato)
				r=r->izq;
			else
				r=r->der;	
		}
	}
	//Eliminar el nodo del dato
	if (r==NULL)
	{
		cout<<"No se encontro el dato\n";
		return;
	}else if(r->izq!=NULL && r->der!=NULL){
        padre=r;
        Mizq=r->der;
        while(Mizq->izq!=NULL){
            padre=Mizq;
            Mizq=Mizq->izq;
        }
        r->dato=Mizq->dato;
        if(r==padre){
            padre->der=Mizq->der;
        }
        else {
            if(Mizq->der!=NULL){
                padre->izq=Mizq->der;
            }else{
                padre->izq=NULL;
            }
        }
        delete Mizq;
    }
	else
    {
        if (r==padre->der){//El dato esta a la derecha del padre
            if (r->izq==NULL && r->der==NULL) 
            {
                padre->der=NULL;
                delete r;
            }else{
                if(r->izq!=NULL){
                    padre->der=r->izq;
                }else{
                    padre->der=r->der;
                }
                delete r;
            }
        } 
            
	    else //El dato esta a la izquierda del padre
            if (r->izq==NULL && r->der==NULL) 
            {
                padre->izq=NULL;
                delete r;
            }else{
                if(r->izq!=NULL){
                    padre->izq=r->izq;
                }else{
                    padre->izq=r->der;
                }
                delete r;
            }		
    } 
}
int main()
{
	arbolBB ar;
	cout<<"Cantidad de nodos\n";
	cout<<ar.contarNodos(ar.raiz)<<endl;
	/////////////////////////
    int A[] = {340,151,346,79,268,345,384,17,137,180,
			306,354,474,4,34,104,153,188,292,331,356,457,
			497,77,278,308,416,467,273,322};
    int n = sizeof(A) / sizeof(int);
    cout << "Datos: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << "  ";
    ar.completarArbol(A, n);
	////////////////////////
	cout << "\nPreorden\n";
	ar.preOrden(ar.raiz);
	cout << "\nInorden\n";
	ar.inOrden(ar.raiz);
	cout << "\nPostorden\n";
	ar.postOrden(ar.raiz);
	cout<<"\nPor anchura\n";
	ar.porAnchura();
	cout<<"\nCantidad de nodos\n";
	cout<<ar.contarNodos(ar.raiz);
	////////////////////////
	ar.borrarNodo(137);
	cout << "\nPreorden\n";
	ar.preOrden(ar.raiz);
	cout << "\nInorden\n";
	ar.inOrden(ar.raiz);
	cout << "\nPostorden\n";
	ar.postOrden(ar.raiz);
	cout<<"\nPor anchura\n";
	ar.porAnchura();
	cout<<"\nCantidad de nodos\n";
	cout<<ar.contarNodos(ar.raiz);
	return(0);
}