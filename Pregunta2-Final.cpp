#include<iostream>
#include<string>
using namespace std;
using std::string;

void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void ordBurbuja(int vector[], int n){
	bool flag=true;	
	for(int i = 0; i<n-1;i++)
	{
		flag=false;
		for (int j=0 ;j<n-1-i; j++)
			if (vector[j]>vector[j+1])
			{
				intercambiar(vector[j],vector[j+1]);
				flag=true;
			}
		if (!flag)
			return;
	}	
}

class nodo //Nodo de la lista de directorio
{
public:
	class arco;
	string nombre; //nombre del nodo
	nodo* sgte; //puntero al siguiente nodo del directorio
	arco* ady; //puntero hacia el primer arco del nodo
	nodo* cabeza; //el primer nodo del directorio (la cabeza de la lista directorio)
    int cantNodos=0;
	nodo()
	{ //Constructor
		sgte = cabeza = NULL;
		ady = NULL;
	}
	void insertarNodo(); //Inserta un nodo al directorio
	void mostrarGrafo(); //Muestra el grafo
	void completarNodos();
	void completarArcos();
    void insertarArco(string ini,string fin);
};
class nodo::arco
{
public:
	nodo* destino; //puntero al nodo de llegada
	arco* sgte; //puntero al siguiente arco
	arco() //constructor
	{
		destino = NULL;
		sgte = NULL;
	}
};
void nodo::insertarNodo()
{
	nodo* nuevo=new nodo();
	nodo* ind;//Indice que recorre el directorio
	string nom;
	cout<<"Ingrese un nombre: ";
	cin>>nom;
	nuevo->nombre=nom;
	if (cabeza==NULL)
	{
		cabeza=nuevo;
		cout<<"Primer nodo del directorio\n";
		return;
	}
	ind=cabeza;
	while(ind->sgte!=NULL)
	{
		ind=ind->sgte;
	}
	ind->sgte=nuevo;
	ind->cabeza=this->cabeza;
	cout<<"Nodo ingresado\n";
}
void nodo::mostrarGrafo()
{
	nodo* ind=cabeza;//Indice que recorre el directorio
	cout<<"Nodo\t\t\t|\tLista de adyacencia\n";
	while(ind!=NULL)
	{
		cout<<ind<<"("<<ind->nombre<<")->"<<ind->ady<<"\t|";
		//Muestra la lista de los arcos
		arco* inda; //Indice que recorrera la lista de arcos
		inda=ind->ady;
		while(inda!=NULL)
		{
			cout<<inda<<"("<<inda->destino<<"-"<<inda->destino->nombre<<")->"<<inda->sgte<<"   ";
			inda=inda->sgte;
		}	
		//////
		cout<<endl;
		ind=ind->sgte;
	}	
}

void nodo::insertarArco(string ini,string fin)
{
	nodo* indi; //Indice que recorre el directorio hasta encontra el ini
	nodo* indf; //Indice que recorre el directorio hasta encontra el fin
	indi=cabeza;
	while (indi!=NULL)
	{
		if (indi->nombre==ini)
			break;
		indi=indi->sgte;
	}
	if (indi==NULL)
	{
		cout<<"No se encontro el nodo inicial\n";
		return;
	}
	indf=cabeza;
	while (indf!=NULL)
	{
		if (indf->nombre==fin)
			break;
		indf=indf->sgte;
	}
	if (indf==NULL)
	{
		cout<<"No se encontro el nodo final\n";
		return;
	}
	///////////////////////
	///Insertar el arco///
	/////////////////////
	arco* nuevo=new arco();//destino=NULL y sgte=NULL
	if (indi->ady==NULL)//Significa que el nodo no tiene arcos
	{
		indi->ady=nuevo;
		nuevo->destino=indf;
		return;
	}
	//Recorre la lista de arcos
	arco* inda; //Indice que recorrera la lista de arcos
	inda=indi->ady;
	while(inda->sgte!=NULL)
	{
		inda=inda->sgte;
	}
	inda->sgte=nuevo;
	nuevo->destino=indf;
}

void nodo::completarNodos()
{
	int i,n;
	cout<<"Digite el numero de nodos: ";
	cin>>n;
    cantNodos=n;
	for (i=0;i<n;i++)
		insertarNodo();
}
void nodo::completarArcos()
{
	int i;
    int arrayElementos[cantNodos];
    nodo* indNodo;
	indNodo=cabeza;
    i=0;
	while (indNodo!=NULL)
	{
		arrayElementos[i]=stoi(indNodo->nombre);
        i++;
		indNodo=indNodo->sgte;
	}
    ordBurbuja(arrayElementos,cantNodos);
    string ini,fin;
    ini=to_string(arrayElementos[0]);
	for(i=1;i<cantNodos;i++){
        fin=to_string(arrayElementos[i]);
        insertarArco(ini,fin);
    }
    for(i=1;i<cantNodos-1;i++){
        ini=to_string(arrayElementos[i]);
        fin=to_string(arrayElementos[i+1]);
        insertarArco(ini,fin);
    }
    ini=to_string(arrayElementos[cantNodos-1]);
    fin=to_string(arrayElementos[1]);
    insertarArco(ini,fin); 
}

int main()
{
	nodo* p=new nodo();
	p->completarNodos();
    p->completarArcos();
	cout<<"Mostrando grafo:\n";
	p->mostrarGrafo();
	return 0;
}