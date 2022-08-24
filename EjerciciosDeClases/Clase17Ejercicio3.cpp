//Lista de adyacencia
#include<iostream>
#include<string>
using namespace std;
class nodo //Nodo de la lista de directorio
{
public:
	class arco;
	string nombre; //nombre del nodo
	nodo* sgte; //puntero al siguiente nodo del directorio
	arco* ady; //puntero hacia el primer arco del nodo
	nodo* cabeza; //el primer nodo del directorio (la cabeza de la lista directorio)
	nodo()
	{ //Constructor
		sgte = cabeza = NULL;
		ady = NULL;
	}
	void insertarNodo(); //Inserta un nodo al directorio
	void mostrarGrafo(); //Muestra el grafo
    void mostrarGrafo2();
	void insertarArco(); //Solicita nombres y encuentra los nodos e inserta el arco
    void insertarArco(string ini,string fin,float peso);
	void completarNodos();
	void completarArcos();
	void mostrarArcos();
	void eliminarArco();
};
class nodo::arco
{
public:
	nodo* destino; //puntero al nodo de llegada
	arco* sgte; //puntero al siguiente arco
    float peso;
	arco() //constructor
	{
		destino = NULL;
		sgte = NULL;
        peso=0;
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
	/*cout<<"direccion\tnombre\tsiguiente\tady\tcabeza\n";
	while(ind!=NULL)
	{
		cout<<ind<<"\t"<<ind->nombre<<"\t"<<ind->sgte<<"\t"<<ind->ady<<"\t"<<ind->cabeza<<endl;
		ind=ind->sgte;
	}*/
	cout<<"Nodo\t\t\t|\tLista de adyacencia\n";
	while(ind!=NULL)
	{
		cout<<ind<<"("<<ind->nombre<<")->"<<ind->ady<<"\t|";
		//Muestra la lista de los arcos
		arco* inda; //Indice que recorrera la lista de arcos
		inda=ind->ady;
		while(inda!=NULL)
		{
			cout<<inda<<"("<<inda->destino<<"-"<<inda->destino->nombre<<"-"<<inda->peso<<")->"<<inda->sgte<<"   ";
			inda=inda->sgte;
		}	
		//////
		cout<<endl;
		ind=ind->sgte;
	}	
}

void nodo::mostrarGrafo2()
{
	nodo* ind=cabeza;//Indice que recorre el directorio
	cout<<"Nodo\t|\tLista de adyacencia\n";
	while(ind!=NULL)
	{
		cout<<ind->nombre<<"\t|";
		//Muestra la lista de los arcos
		arco* inda; //Indice que recorrera la lista de arcos
		inda=ind->ady;
		while(inda!=NULL)
		{
			cout<<inda->destino->nombre<<"("<<inda->peso<<")"<<"\t\t";
			inda=inda->sgte;
		}	
		//////
		cout<<endl;
		ind=ind->sgte;
	}	
}

void nodo::insertarArco()
{
	string ini,fin; //Son los nombres del nodo inicio y fin
	nodo* indi; //Indice que recorre el directorio hasta encontra el ini
	nodo* indf; //Indice que recorre el directorio hasta encontra el fin
    float peso;
	cout<<"Ingrese en nombre del nodo inicio: ";
	cin>>ini;
	cout<<"Ingrese en nombre del nodo final: ";
	cin>>fin;
    cout<<"Ingrese el peso del arco: ";
	cin>>peso;
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
    nuevo->peso=peso;
	if (indi->ady==NULL)//Significa que el nodo no tiene arcos
	{
		indi->ady=nuevo;
		nuevo->destino=indf;
		cout<<"1er arco del nodo"<<indi->nombre<<endl;
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
	cout<<"Arco agregado\n";
}

void nodo::insertarArco(string ini,string fin,float peso)
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
    nuevo->peso=peso;
	if (indi->ady==NULL)//Significa que el nodo no tiene arcos
	{
		indi->ady=nuevo;
		nuevo->destino=indf;
		cout<<"1er arco del nodo"<<indi->nombre<<endl;
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
	cout<<"Arco agregado\n";
}


void nodo::completarNodos()
{
	int i,n;
	cout<<"Digite el numero de nodos: ";
	cin>>n;
	for (i=0;i<n;i++)
		insertarNodo();
}
void nodo::completarArcos()
{
	int i,n,opcion=0;
    do
	{
		cout<<"¿El grafo es dirigido? \n";
        cout<<"1.Si\n";
        cout<<"2.No\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            case 1:
                cout<<"Digite el numero de arcos: ";
                cin>>n;
                for (i=0;i<n;i++)
                    insertarArco();
                break;
            case 2:
                cout<<"Digite el numero de arcos: ";
                cin>>n;
                for (i=0;i<n;i++){
                    string ini,fin;
                    float peso;
                    cout<<"Ingrese en nombre del nodo inicio: ";
                    cin>>ini;
                    cout<<"Ingrese en nombre del nodo final: ";
                    cin>>fin;
                    cout<<"Ingrese el peso del arco: ";
                    cin>>peso;
                    insertarArco(ini,fin,peso);
                    insertarArco(fin,ini,peso);
                }
                break;
            default:
                cout<<"Opcion equivocada\n";
            }
    }while(opcion!=2 && opcion!=1);
}
void nodo::mostrarArcos()
{
	string nom;
	cout << "Ingrese el nombre del nodo: ";
	cin >> nom;
	nodo* ind = cabeza;
	nodo* nodoBuscar = NULL;
	while (ind != NULL) {
		if (ind->nombre == nom) {
			nodoBuscar = ind;
		}
		ind = ind->sgte;
	}
	if (nodoBuscar == NULL)
		cout << "El nodo no existe\n";
	else {
		cout << "Nodo\t|\tLista de adyacencia\n";
		cout << nodoBuscar->nombre << "\t|";
		arco* inda = nodoBuscar->ady;
		if (inda == NULL)
		{
			cout << "El nodo no tiene arcos\n";
			return;
		}
		while (inda != NULL) {
			cout << inda->destino->nombre<< "(" << inda->peso<< ")"<< "\t\t";
			inda = inda->sgte;
		}
	}
}
void nodo::eliminarArco()
{
	string ini,fin; //Nombres del nodo inicial y final en el directorio
	nodo* indi; //Indice que buscara al nombre ini
	nodo* indf; //Indice que buscara al nombre fin
	arco* inda; //Indice que buscara al arco que apunte al nodo de nombre fin (indf)
	arco* indaAnt; //Arco anterior a inda
	if (cabeza==NULL)
	{
		cout<<"Grafo vacio\n";
		return;
	}
	cout<<"Ingrese el nombre del nodo inicio: ";
	cin>>ini;
	cout<<"Ingrese el nombre del nodo final: ";
	cin>>fin;
	indi=cabeza;
	indf=cabeza;
	while (indf!=NULL) //Busca el nodo final
	{
		if(indf->nombre==fin)
			break;
		indf=indf->sgte;
	}
	if (indf==NULL)
	{
		cout<<"No existe el nodo final\n";
		return;
	}
	while (indi!=NULL) //Busca el nodo inicial
	{
		if(indi->nombre==ini)
		{
			////Buscando el arco////
			indaAnt=NULL;
			inda=indi->ady;
			if (inda==NULL)
			{
				cout<<"El nodo no tiene arcos\n";
				return;
			}
			while(inda!=NULL)
			{
				if(inda->destino==indf)
				{	
					if(inda==indi->ady)
						indi->ady=indi->ady->sgte;
					else
						indaAnt->sgte=inda->sgte;
					delete(inda);
					cout<<"Arco "<<ini<<"----->"<<fin<<" Eliminado\n";
					return;
				}
				indaAnt=inda;
				inda=inda->sgte;
			}
			if (inda==NULL)
			{
				cout<<"No hay arco al nodo final\n";
				return;
			}
			////////////////////////
		}
		indi=indi->sgte;
	}
	if (indi==NULL)
	{
		cout<<"No existe el nodo inicial\n";
		return;
	}
}
int main()
{
	nodo* p=new nodo();
	p->completarNodos();
	p->completarArcos();
	cout<<"Mostrando grafo:\n";
	p->mostrarGrafo();
	cout<<"Visualizar arcos:\n";
	p->mostrarArcos();
	cout<<"\nMostrando grafo:\n";
	p->mostrarGrafo2();
	return 0;
}