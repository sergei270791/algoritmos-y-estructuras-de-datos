//Lista simplemente enlazada
//Clase Nodo
#include<iostream>
using namespace std;
class Nodo
{
	private:
	int dato;      // Dato del nodo
	Nodo *enlace; // Direccion a otro Nodo,
    int day,month,year;
	public:
	Nodo(int d)
	{
		dato=d; //Asigna el dato=d a este Nodo
		enlace=NULL; //Este nodo apunta a NULL
	}
	Nodo(int d,Nodo *n)
	{
		dato=d;
		enlace=n;
	}
	int getDato() //Devuelve el dato
	{
		return dato;
	}
	int setDato(int nuevoDato) //Fija un nuevo dato
	{
		dato=nuevoDato;
        return 0;
	}
    int getDay() //Devuelve el day
	{
		return day;
	}
    int getMonth() //Devuelve el Month
	{
		return month;
	}
    int getYear() //Devuelve el Year
	{
		return year;
	}
	Nodo *getEnlace() //Devuelve la dirección a donde apunta
	{
		return enlace;
	}
	void setEnlace(Nodo *sgte) //Fija un nuevo enlace
	{
		enlace=sgte;
	}
    void setDatos(int nuevoDay,int nuevoMonth,int nuevoYear) 
	{
		day=nuevoDay;
        month=nuevoMonth;
        year=nuevoYear;
	}
};
//La Clase Producto
class Producto : public Nodo {
    private:
	int day,month,year;
    public:
    
	void setDato(int nuevoDay,int nuevoMonth,int nuevoYear) 
	{
		day=nuevoDay;
        month=nuevoMonth;
        year=nuevoYear;
	}

};



//La clase Lista
class ListaProducto
{
	private:
	Producto *primero;
	public:
	ListaProducto() //Constructor
	{
		primero = NULL;
	}
	void CrearLista();
	void VisualizarLista();
    void OrdenarLista();

};
//Crear la lista
void ListaProducto::CrearLista()
{
	for(int i=0;i<300;i++){
        int d,m,y,p;
        p=10+rand()%191;
        y=2015+rand()%6;
        m=1+rand()%3;
        if(m==1 || m==3){
            d=1+rand()%31;
        }
        else{
            if(y==2016 || y==2020){
                d=1+rand()%29;
            }
            else{
                d=1+rand()%28;
            }
        }
		primero = (Producto*)new Nodo(p,primero);
        primero->setDatos(d,m,y);
    }
    return;
};
//Visualizar la lista
void ListaProducto::VisualizarLista()
{
	Producto *indice;
	cout<<"Direccion del producto \t Peso \t Day \t Month \t Year \t Direccion a donde apunta\n";
	for (indice=primero;indice!=NULL;indice=(Producto*)indice->getEnlace())
		cout<<indice<<"\t\t  "<<indice->getDato()<<"\t  "<<indice->getDay()<<"\t  "<<indice->getMonth()<<"\t "<<indice->getYear()<<"\t\t"<<indice->getEnlace()<<endl;
}
// Ordenar la lista
void ListaProducto::OrdenarLista(){
    int aux1,aux2,aux3,aux4,i=0;
	Producto* inicio = primero;
	Nodo* indice;
	while (inicio != NULL && i<300) {
		for (indice = inicio; indice->getEnlace() != NULL ; indice = indice->getEnlace()) {
			if (indice->getDay() > indice->getEnlace()->getDay()) {
				aux1 = indice->getDato();
                aux2 = indice->getDay();
                aux3 = indice->getMonth();
                aux4 = indice->getYear();
                indice->setDato(indice->getEnlace()->getDato());
                indice->setDatos(indice->getEnlace()->getDay(),indice->getEnlace()->getMonth(),              indice->getEnlace()->getYear());
                indice->getEnlace()->setDato(aux1);
                indice->getEnlace()->setDatos(aux2,aux3,aux4);
			}
		}
        i++;
	}
    i=0;
    while (inicio != NULL && i<300) {
		for (indice = inicio; indice->getEnlace() != NULL ; indice = indice->getEnlace()) {
			if (indice->getMonth() > indice->getEnlace()->getMonth()) {
				aux1 = indice->getDato();
                aux2 = indice->getDay();
                aux3 = indice->getMonth();
                aux4 = indice->getYear();
                indice->setDato(indice->getEnlace()->getDato());
                indice->setDatos(indice->getEnlace()->getDay(),indice->getEnlace()->getMonth(),              indice->getEnlace()->getYear());
                indice->getEnlace()->setDato(aux1);
                indice->getEnlace()->setDatos(aux2,aux3,aux4);
			}
		}
        i++;
	}
    i=0;
    while (inicio != NULL && i<300) {
		for (indice = inicio; indice->getEnlace() != NULL ; indice = indice->getEnlace()) {
			if (indice->getYear() > indice->getEnlace()->getYear()) {
				aux1 = indice->getDato();
                aux2 = indice->getDay();
                aux3 = indice->getMonth();
                aux4 = indice->getYear();
                indice->setDato(indice->getEnlace()->getDato());
                indice->setDatos(indice->getEnlace()->getDay(),indice->getEnlace()->getMonth(),              indice->getEnlace()->getYear());
                indice->getEnlace()->setDato(aux1);
                indice->getEnlace()->setDatos(aux2,aux3,aux4);
			}
		}
        i++;
	}
}

int main()
{
	int opcion;
    ListaProducto miLista;
	do
	{
		cout<<"Que desea hacer\n";
		cout<<"1. Crear lista\n";
		cout<<"2. Visualizar lista\n";
		cout<<"3. Ordenar lista\n";
		cout<<"4. Salir\n";
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				miLista.CrearLista();
				break;
			case 2:
				miLista.VisualizarLista();
				break;
			case 3:
				miLista.OrdenarLista();
				break;
			case 4:
				cout<<"Fin del programa\n";
				break;
			default:
				cout<<"Opcion equivocada\n";
		}
	}while(opcion!=4);
	return 0;
}