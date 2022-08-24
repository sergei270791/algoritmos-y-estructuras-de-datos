#include<iostream>
using namespace std;

//La clase NodoCircular
class NodoCircular
{
private:
int dato;
NodoCircular* enlace; // puntero al siguiente Nodo
public:
NodoCircular (int t)
{
dato = t;
enlace = this; // al principio se apunta a sí mismo
}
int getDato() // devuelve el dato
{
return dato;
}
void setDato(int a) // fija el dato
{
dato=a;
}
NodoCircular* getEnlace() // devuelve nodo al que apunta
{
return enlace;
}
void setEnlace(NodoCircular* sgte)
{
enlace = sgte; // enlaza con el nodo sgte
}
};


//La clase ListaCircular
class ListaCircular
{
private:
NodoCircular* acceso; // Por donde se accede a la lista
public:
ListaCircular() // Constructor
{
acceso=NULL; // Al principio la lista esta vacia
}
void crearLista();
void visualizar();
void insertarAcceso(int);
void insertarDespues(int,int);
void insertarAntes(int,int);
void eliminar(int);
void modificar(int,int);
};

//Inserta un dato
void ListaCircular::insertarAcceso(int dato)
{
NodoCircular* nuevo;
nuevo = new NodoCircular (dato);
if (acceso != NULL )
{
nuevo -> setEnlace(acceso -> getEnlace());
acceso -> setEnlace(nuevo); //Cierra el circulo
}
acceso = nuevo; //Ahora nuevo es el acceso
};

//Visualiza la lista
void ListaCircular:: visualizar()
{
NodoCircular* indice;
if (acceso != NULL)
{
indice = acceso; // siguiente nodo al de acceso
cout<<"DirDelDato"<<"\t"<<"Dato"<<"\t"<<"Siguiente"<<endl;
do {
cout <<indice<< "\t" <<indice->getDato()<<"\t"<<indice->getEnlace()<<endl;
indice = indice -> getEnlace();
}while(indice != acceso);
}
};