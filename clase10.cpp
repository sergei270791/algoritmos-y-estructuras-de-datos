//Arbol Parte 1
#include <iostream>
using namespace std;
class Nodo
{
	private:
	string dato;
	Nodo* izq;
	Nodo* der;
	public:
	Nodo(Nodo* nodoIzq, string valor, Nodo* nodoDer) //Constructor a un subarbol
	{
		dato = valor;
		izq = nodoIzq;
		der = nodoDer;
	}
	// operaciones de acceso
	string getDato() { return dato; } //Devuelve el valor almacenado en el nodo
	Nodo* getIzq() { return izq; } //Devuelve el nodo de la izquierda
	Nodo* getDer() { return der; } //Devuelve el nodo de la derecha
	// operaciones de modificación
	void setDato(string d) { dato = d; } //Asigna un valor al dato del nodo
	void setIzq(Nodo* n) { izq = n; } //Asigna un nodo a la izquierda
	void setDer(Nodo* n) { der = n; } //Asigna un nodo a la derecha
};
class ArbolB
{
	private:
	Nodo* raiz;
	public:
	ArbolB() //Inicializa la raiz a un NULL, arbol vacio
	{
		raiz = NULL;
	}
	bool esVacio(); // Devuelve verdadero si el arbol esta vacio
	void setRaiz(Nodo*); //Fija el atributo raiz a un nodo
	Nodo* getRaiz(); //Devuelve el puntero al nodo raiz
	Nodo* getHijoIzq(); // Devuelve el nodo izquierdo
	Nodo* getHijoDer(); // Devuelve el nodo derecho
	//Crea y Retorna un nuevo nodo
	Nodo* nuevoArbol(Nodo*, string, Nodo*); 
};
bool ArbolB::esVacio()
{
	return raiz==NULL;
}
void ArbolB::setRaiz(Nodo* r)
{
	raiz=r;
}
Nodo* ArbolB::getRaiz()
{
	return raiz;
}
Nodo* ArbolB::getHijoIzq()
{
	return raiz->getIzq();
}
Nodo* ArbolB::getHijoDer()
{
	return raiz->getDer();
}
Nodo* ArbolB::nuevoArbol(Nodo* NodoIzq,string dato,Nodo* NodoDer)
{
	return new Nodo(NodoIzq,dato,NodoDer);
}
int main()
{
	ArbolB a[15],ar;
	Nodo* n[15];
	//Nivel 3
	n[0]=a[0].nuevoArbol(NULL,"Benito",NULL);
	n[1]=a[1].nuevoArbol(NULL,"Federico",NULL);
	n[2]=a[2].nuevoArbol(NULL,"Rosa",NULL);
	n[3]=a[3].nuevoArbol(NULL,"Luis",NULL);
	n[4]=a[4].nuevoArbol(NULL,"Pedro",NULL);
	n[5]=a[5].nuevoArbol(NULL,"Ramon",NULL);
	n[6]=a[6].nuevoArbol(NULL,"Zulema",NULL);
	n[7]=a[7].nuevoArbol(NULL,"Pamela",NULL);
	//Nivel 2
	n[8]=a[8].nuevoArbol(n[0],"Maria",n[1]);
	n[9]=a[9].nuevoArbol(n[2],"Rodrigo",n[3]);
	n[10]=a[10].nuevoArbol(n[4],"Anyora",n[5]);
	n[11]=a[11].nuevoArbol(n[6],"Abel",n[7]);
	//Nivel 1
	n[12]=a[12].nuevoArbol(n[8],"Isabel",n[9]);
	n[13]=a[13].nuevoArbol(n[10],"Jesus",n[11]);
	//Nivel 0
	n[14]=a[14].nuevoArbol(n[12],"Esperanza",n[13]);
	ar.setRaiz(n[14]);
	//Mostrando el Arbol
	//Mostrar arbol
	cout<<"Nivel 0"<<endl;
	cout<<ar.getRaiz()->getDato()<<endl;
	cout<<"Nivel 1"<<endl;
	cout<<ar.getRaiz()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getDato()<<endl;
	cout<<"Nivel 2"<<endl;
	cout<<ar.getRaiz()->getIzq()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getIzq()->getDer()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getDer()->getDato()<<endl;
	cout<<"Nivel 3"<<endl;
	cout<<ar.getRaiz()->getIzq()->getIzq()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getIzq()->getIzq()->getDer()->getDato()<<"  ";
	cout<<ar.getRaiz()->getIzq()->getDer()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getIzq()->getDer()->getDer()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getIzq()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getIzq()->getDer()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getDer()->getIzq()->getDato()<<"  ";
	cout<<ar.getRaiz()->getDer()->getDer()->getDer()->getDato()<<endl;
	return 0;	
}