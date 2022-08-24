//Cola
#include <iostream>
using namespace std;
class NodoCola
{
	public:
	int dato;
	NodoCola* siguiente;
	NodoCola (int d)
	{
		dato = d;
		siguiente = NULL; 
	}
};
class Cola
{
	private:
	NodoCola* frente;
	NodoCola* final;
	public:
	Cola() //Constructor que crea la cola vacía
	{
		frente = final = NULL;
	}
	void insertar(int); //Inserta un nodo al final de la cola
	int quitar(); //Retira un nodo del frente de la cola
	int getDatoFrente(); //Devuelve el dato del frente de la cola
	int getDatoFinal(); //Devuelve el dato del final de la cola
	bool colaVacia(); //Verdadero si la cola esta vacía
	NodoCola* getFrente(); //Devuelve el nodo frente
	NodoCola* getFinal(); //Devuelve el nodo final
	void visualizarCola();
	void completarCola();
};
bool Cola::colaVacia()
{
	return frente == NULL && final==NULL; 
}	
void Cola::insertar(int elemento)
{
	NodoCola* nuevo = new NodoCola(elemento);
	if (colaVacia())
		frente = final = nuevo;
	else {
		final->siguiente = nuevo;
		final = nuevo;
	}
}
int Cola::quitar()
{
	if(colaVacia()){
		cout<<"La cola esta vacia\n";
		return 0;
	}else{
		NodoCola* nodoBorrar = frente;
		int datoFrente=frente->dato;
		frente=frente->siguiente;
		if (frente==NULL)
				final=NULL;
		delete nodoBorrar;
		return datoFrente;
	}
}
int Cola::getDatoFrente()
{
	if (colaVacia())
	{
		//cout<<"Cola vacia: ";
		return 0;
	}
	else
		return frente -> dato;
}
NodoCola* Cola::getFrente()
{
	if (colaVacia())
	{
		//cout<<"Cola vacia: ";
		return 0;
	}
		return frente;
}
int Cola::getDatoFinal()
{
	if (colaVacia())
	{
		//cout<<"Cola vacia: ";
		return 0;
	}
	else
		return final -> dato;
}
NodoCola* Cola::getFinal()
{
	if (colaVacia())
	{
		//cout<<"Cola vacia: ";
		return 0;
	}
	else
		return final;
}
void Cola::visualizarCola()
{
	cout<<"Elementos de la cola\n";
	cout << "Elementos de la Cola:\n";
	while (!colaVacia()) {
		cout << "Direccion frente: " << frente << " . Elemento del frente: ";
		cout << frente->dato << "\nDireccion final: " << final;
		cout << " . Elemento del final: " << final->dato << endl;
		cout << "Se elimino " << getFrente() << " con el dato: ";
		cout << quitar() << endl;
	}
	cout<<"\nAl terminar queda:\n";
	cout << "Direccion frente: " << getFrente() << " . Elemento del frente: ";
	cout << getDatoFrente() << "\nDireccion final: " << getFinal();
	cout << " . Elemento del final: " << getDatoFinal() << endl;
}
void Cola::completarCola()
{
	int n,i,dato;
	cout<<"Cuantos elementos desea ingresar: ";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout <<"Direccion frente: "<<getFrente()<<" . Elemento del frente: "<< getDatoFrente();
		cout <<"\nDireccion final: "<<getFinal()<<" . Elemento del final: "<< getDatoFinal() << endl;
		cout<<"Ingrese el dato "<<i<<": ";
		cin>>dato;
		insertar(dato);
	}
	cout <<"Direccion frente: "<<getFrente()<<" . Elemento del frente: "<< getDatoFrente();
	cout <<"\nDireccion final: "<<getFinal()<<" . Elemento del final: "<< getDatoFinal() << endl;
}
int main()
{
	Cola cola;
	/*cola.insertar(5);
	cola.insertar(6);
	cola.insertar(7);
	cola.insertar(8);
	cola.insertar(9);*/
	/*cout<<"Quitando\n";
	cout<<cola.quitar()<<endl;
	cout<<cola.quitar()<<endl;
	cout<<cola.quitar()<<endl;
	cout<<cola.quitar()<<endl;
	cout<<cola.quitar()<<endl;
	cout<<cola.quitar()<<endl;*/
	cola.completarCola();
	cola.visualizarCola();
	return 0;
}