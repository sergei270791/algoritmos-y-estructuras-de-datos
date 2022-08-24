//Pilas con Array
#include <iostream>
using namespace std;
const int TAMPILA = 3; 
class Pila
	{
	private:
		int pCima; //Es el índice del último elemento ingresado en la pila, o sea la cima
		int listaPila[TAMPILA]; //El tamaño de la lista esta definido al inicio
	public:
		Pila() //Constructor que crea la pila
		{
			pCima = -1; // Condición de pila vacía
		}
		void insertar(int); //push
		int quitar(); //pop
		bool pilaVacia(); //Comprueba si la pila esta vacía
		bool pilaLlena(); //Comprueba si la pila esta llena
		void registrarEntrada(int);
		void registrarSalida();
		void mostrar();
};
bool Pila::pilaLlena()
{
	return pCima==TAMPILA-1;	
}
bool Pila::pilaVacia()
{
	return pCima==-1;	
}
void Pila::insertar(int dato)
{
	if (!pilaLlena())
	{
		pCima++;
		listaPila[pCima]=dato;
	}
	else
		cout<<"Desbordamiento (overflow)";
}
int Pila::quitar()
{
	int dato;
	if (!pilaVacia())
	{
		dato=listaPila[pCima];
		pCima--;
		return dato;
	}
	else {
		cout << "Desbordamiento negativo (undeflow)\n";
		return -1;
	}
}

void Pila::registrarEntrada(int cont)
{	
	this->insertar(cont);
	mostrar();
}

void Pila::registrarSalida()
{	
	this->quitar();
	mostrar();
}

void Pila::mostrar()
{
	int aux=pCima;
	while(aux>0){
		cout<<&listaPila[aux]<<" "<<"X"<<" "<<&listaPila[aux-1]<<"		";
		aux--;
	}
	cout<<&listaPila[aux]<<" "<<"X"<<" "<<NULL<<endl;
}

int main()
{
	Pila pila1,pila2,pila3; //Crea una pila vacía
	int opcion,cont=1;
	do
	{
		cout<<"Que desea hacer\n";
		cout<<"1. Registrar Entrada de avión\n";
		cout<<"2. Registrar Salida de avión\n";
		cout<<"3. Fin del programa\n";
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				if(pila1.pilaLlena()){
					if(pila2.pilaLlena()){
						if(pila3.pilaLlena()){
							cout<<"Carril1: ";
							pila1.mostrar();
							cout<<"Carril2: ";
							pila2.mostrar();
							cout<<"Carril3: ";
							pila3.mostrar();
							cout<<"Estan llenos los carriles, no se pudo registrar entrada"<<endl;
						}else{
							cout<<"Carril1: ";
							pila1.mostrar();
							cout<<"Carril2: ";
							pila2.mostrar();
							cout<<"Carril3: ";
							pila3.registrarEntrada(cont);
							cont++;
						}
					}else{
						cout<<"Carril1: ";
						pila1.mostrar();
						cout<<"Carril2: ";
						pila2.registrarEntrada(cont);
						cout<<"Carril3: "<<endl;
						cont++;
					}
				}else{
					cout<<"Carril1: ";
					pila1.registrarEntrada(cont);
					cout<<"Carril2: "<<endl;
					cout<<"Carril3: "<<endl;
					cont++;
				}
				break;
			case 2:
				if(pila3.pilaVacia()){
					if(pila2.pilaVacia()){
						if(pila1.pilaVacia()){
							cout<<"Carril1: "<<endl;
							cout<<"Carril2: "<<endl;
							cout<<"Carril3: "<<endl;
							cout<<"Estan vacios los carriles, no se pudo registrar salida"<<endl;
						}else{
							cout<<"Carril1: ";
							pila1.registrarSalida();
							cout<<"Carril2: "<<endl;
							cout<<"Carril3: "<<endl;
							cont--;
						}
					}else{
						cout<<"Carril1: ";
						pila1.mostrar();
						cout<<"Carril2: ";
						pila2.registrarSalida();
						cout<<"Carril3: "<<endl;
						cont--;
					}
				}else{
					cout<<"Carril1: ";
					pila1.mostrar();
					cout<<"Carril2: ";
					pila2.mostrar();
					cout<<"Carril3: ";
					pila3.registrarSalida();
					cont--;
				}
				break;
			case 3:
				cout<<"Fin del programa\n";
				break;
			default:
				cout<<"Opcion equivocada\n";
		}
	}while(opcion!=3);
	return 0;
}