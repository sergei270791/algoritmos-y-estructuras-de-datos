//Lista simplemente enlazada
//Clase Nodo
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;



class Nodo
{
	private:
	float dato; 
	int grado;     // Dato del nodo
	Nodo *enlace; // Direccion a otro Nodo
	public:
	Nodo(float d,int e)
	{
		dato=d; //Asigna el dato=d a este Nodo
		grado=e;
		enlace=NULL; //Este nodo apunta a NULL
	}
	Nodo(float d,int e,Nodo *n)
	{
		dato=d;
		grado=e;
		enlace=n;
	}
	float getDato() 
	{
		return dato;
	}
	float setDato(float nuevoDato) 
	{
		dato=nuevoDato;
        return 0;
	}
	int getGrado() 
	{
		return grado;
	}
	int setGrado(int nuevoGrado) 
	{
		grado=nuevoGrado;
        return 0;
	}
	Nodo *getEnlace() //Devuelve la dirección a donde apunta
	{
		return enlace;
	}
	void setEnlace(Nodo *sgte) //Fija un nuevo enlace
	{
		enlace=sgte;
	}
};
//La clase Lista
class Lista
{
	private:
	Nodo *primero;
	public:
	Lista() //Constructor
	{
		primero = NULL;
	}
	Nodo *getPrimero() //Devuelve la dirección a donde apunta
	{
		return primero;
	}
	void setPrimero(Nodo *nodo) //Fija un nuevo enlace
	{
		primero=nodo;
	}
	void crearLista();
	void visualizarLista();
	void OrdenarLista();
	void SimplificarLista();
	Nodo *buscarAntesNodo(float,int);
	Lista Derivada();
	Lista Multiplicacion(Lista,Lista);
	Lista DerivadaProducto(Lista,Lista);
	Lista Suma(Lista,Lista);
};
//Crear una lista
void Lista::crearLista()
{
	primero = new Nodo(2,4,primero);
	primero = new Nodo(-2,6,primero);
	primero = new Nodo(3,2,primero);
	primero = new Nodo(1,4,primero);
	primero = new Nodo(-5,1,primero);
	primero = new Nodo(8,0,primero);
}

//Visualizar una lista
void Lista::visualizarLista()
{
	Nodo *indice;
	cout<<"Direccion del nodo \t coeficiente \t exponente \t a donde apunta\n";
	for (indice=primero;indice!=NULL;indice=indice->getEnlace())
		cout<<indice<<"\t\t"<<indice->getDato()<<"\t\t"<<indice->getGrado()<<"\t"<<indice->getEnlace()<<endl;
}

void Lista::OrdenarLista(){
    int aux1,aux2,i=0;
	Nodo* inicio = primero;
	Nodo* indice;
	while (inicio!= NULL && i<100) {
		for (indice = inicio; indice->getEnlace() != NULL ; indice = indice->getEnlace()) {
			if (indice->getGrado() < indice->getEnlace()->getGrado()) {
				aux1 = indice->getDato();
				aux2 = indice->getGrado();
                indice->setDato(indice->getEnlace()->getDato());
                indice->setGrado(indice->getEnlace()->getGrado());
                indice->getEnlace()->setDato(aux1);
                indice->getEnlace()->setGrado(aux2);
			}
		}
		i++;
	}
}
Nodo *Lista::buscarAntesNodo(float dato,int grado)
{
	Nodo *anterior;
	for (anterior=primero;anterior!=NULL;anterior=anterior->getEnlace())
	{
	    if(anterior->getEnlace()==NULL)
			return NULL;
		if (anterior->getEnlace()->getDato()== dato && primero->getEnlace()->getGrado() == grado)
			return anterior;
	}
	return NULL;
}

void Lista::SimplificarLista()
{
	Nodo *indice;
	Nodo *anterior;
	
	bool Cambio=true;
	while(Cambio){
		Cambio=false;
		for (indice=primero;indice->getEnlace()->getEnlace()!=NULL;indice=indice->getEnlace()){
			if(indice->getGrado()==indice->getEnlace()->getGrado()){
				indice->getEnlace()->setDato(indice->getDato()+indice->getEnlace()->getDato());
				if(indice==primero){
					primero=indice->getEnlace();
				}else{
					Nodo *auxiliar=NULL;
					anterior=buscarAntesNodo(indice->getDato(),indice->getGrado());
					anterior->setEnlace(indice->getEnlace());
					auxiliar=indice;
					indice=anterior;
					delete auxiliar;
				}
			}
		}
	}
}

Lista Lista::Derivada(){
	Nodo *indice;
	Lista derivada;
	float c;
	int e;
	for (indice=primero;indice!=NULL;indice=indice->getEnlace()){
		if(indice->getGrado()==0){
			break;
		}
		c=(indice->getDato())*(indice->getGrado());
		e=indice->getGrado()-1;
		derivada.setPrimero(new Nodo(c,e,derivada.getPrimero()));
	}
	
	return derivada;
}

Lista Lista::DerivadaProducto(Lista lista1,Lista lista2){
	Lista operacion;
	Lista aux;
	aux=operacion.Suma(operacion.Multiplicacion(lista1.Derivada(),lista2),operacion.Multiplicacion(lista2.Derivada(),lista1));
	return aux;
}

Lista Lista::Multiplicacion(Lista lista1,Lista lista2){
	Lista producto;	
	float c;
	int e;
	Nodo *indice1;
	Nodo *indice2;
	for (indice1=lista1.getPrimero();indice1!=NULL;indice1=indice1->getEnlace()){
		for (indice2=lista2.getPrimero();indice2!=NULL;indice2=indice2->getEnlace()){
			c=indice1->getDato()*indice2->getDato();
			e=indice1->getGrado()+indice2->getGrado();
			producto.setPrimero(new Nodo(c,e,producto.getPrimero()));
		}
	}
	return producto;
}

Lista Lista::Suma(Lista lista1,Lista lista2){
	Lista suma;
	bool bandera=true;
	float c;
	int e;
	Nodo *indice1;
	Nodo *indice2;
	for (indice1=lista1.getPrimero();indice1!=NULL;indice1=indice1->getEnlace()){
		bandera=false;
		for (indice2=lista2.getPrimero();indice2!=NULL;indice2=indice2->getEnlace()){
			if(indice1->getGrado()==indice2->getGrado()){
				e=indice1->getGrado();
				c=indice1->getDato()+indice2->getDato();
				suma.setPrimero(new Nodo(c,e,suma.getPrimero()));
				bandera=true;
				continue;
			}
		}
		if(bandera==false){
			e=indice1->getGrado();
			c=indice1->getDato();
			suma.setPrimero(new Nodo(c,e,suma.getPrimero()));
		}
		
	}
	return suma;
}

int main()
{
	Lista operacion,polinomio1,polinomio2,resultado;
	polinomio1.crearLista();
	polinomio1.OrdenarLista();
	polinomio1.SimplificarLista();
	polinomio1.visualizarLista();
	polinomio2.crearLista();
	polinomio2.OrdenarLista();
	polinomio2.SimplificarLista();
	polinomio2.visualizarLista();
	resultado=operacion.Suma(polinomio1,polinomio2);
	resultado.OrdenarLista();
	resultado.visualizarLista();
	resultado.SimplificarLista();
	resultado.visualizarLista();
	return 0;
}
