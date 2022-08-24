//Pilas con Listas
#include <iostream>
using namespace std;
class NodoPila
{
public:
	int elemento;
	NodoPila* siguiente;
	NodoPila(int elem) //Constructor
	{
		elemento = elem;
		siguiente = NULL;
	}
};
class PilaDina
{
public:
	NodoPila* cima;
	PilaDina() //Constructor
	{
		cima = NULL; //Nodo que esta en la cima de la pila
	}
	void insertar(int);
	int quitar();
	int getCima();
	bool pilaVacia();
	void limpiarPila();
	void visualizar();
	void completarPila();
};
void PilaDina::insertar(int elemento)
{
	NodoPila* nuevo=new NodoPila(elemento);
	nuevo->siguiente=cima;
	cima=nuevo;
}
bool PilaDina::pilaVacia()
{
	return cima==NULL;
}
int PilaDina::quitar()
{
	if (!pilaVacia()) {
		int datoCima = cima->elemento;
		NodoPila* nodoBorrar = cima;
		cima = cima->siguiente;
		delete nodoBorrar;
		return datoCima;
	}
	else
		cout<<"La pila esta vacia.\n";
}
int PilaDina::getCima()
{
	if (pilaVacia())
	{
		cout<<"Pila vacia\n";
		return 0;
	}
	else
		return cima->elemento;
}
void PilaDina::visualizar()
{
	cout<<"Elementos de la pila:\n";
	while(!pilaVacia())
	{
		cout<<"Direccion cima: "<<cima<<" . Elemento en la cima: "<<cima->elemento<<endl;
		cout<<quitar()<<endl;
	}
	cout<<"Al terminar queda:\n";
	cout<<"Direccion cima: "<<cima<<" . Elemento en la cima: "<<getCima()<<endl;
}
void PilaDina::completarPila()
{
	int i,n,dato;
	cout<<"Cuantos elementos ingresara a la pila: ";
	cin>>n;
	cout<<"Direccion cima: "<<cima<<" . Elemento en la cima: "<<getCima()<<endl;
	for (i=0;i<n;i++)
	{
		cout<<"Indice ("<<i<<"): ";
		cin>>dato;
		insertar(dato);
		cout<<"Direccion cima: "<<cima<<" . Elemento en la cima: "<<cima->elemento<<endl;
	}
}
void PilaDina::limpiarPila()
{
	while(!pilaVacia())
		{
				cout<<"Direccion cima: "<<cima<<" . Elemento en la cima: "<<cima->elemento<<endl;
				NodoPila* NodoBorrar=cima;
				cima=cima->siguiente;
				delete NodoBorrar;
		}
}
int main()
{
	PilaDina pila;	
	/*pila.insertar(7);
	pila.insertar(6);
	pila.insertar(5);
	pila.insertar(4);
	pila.insertar(3);*/
	pila.completarPila();
	cout<<"Limpiando la pila\n";
	pila.limpiarPila();
	pila.visualizar();
	return 0;	
}