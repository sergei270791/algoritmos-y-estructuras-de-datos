#include <iostream>
using namespace std;

class NodoCola
{
    public:
    int dato;
    NodoCola* siguiente;
    NodoCola(int d)
    {
        dato = d;
        siguiente = NULL;
    }
};

class Bicola
{
    private:
    NodoCola* frente;
    NodoCola* final;
    public:
    Bicola()
    {
        frente = final = NULL;
    }
    NodoCola* getFrente();
    NodoCola* getFinal();
    void ponerFinal(int); //Equivalente a insertar
    void ponerFrente(int); //Nuevo
    int quitarFrente(); // Equivalente a quitar
    int quitarFinal(); //Nuevo
    int getDatoFrente();
    int getDatoFinal();
    bool bicolaVacia(); // Equivalente a colaVacia
    int numElemsBicola(); //Nuevo
    void visualizarBicola();
    void complementarBicola();
    };

bool Bicola::bicolaVacia()
{
	return frente == NULL && final==NULL; 
}	
void Bicola::ponerFinal(int elemento)
{
	NodoCola* nuevo = new NodoCola(elemento);
	if (bicolaVacia())
		frente = final = nuevo;
	else {
		final->siguiente = nuevo;
		final = nuevo;
	}
}
int Bicola::quitarFrente()
{
	if(bicolaVacia()){
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

int Bicola::getDatoFrente()
{
	if (bicolaVacia())
	{
		//cout<<"Bicola vacia: ";
		return 0;
	}
	else
		return frente -> dato;
}
NodoCola* Bicola::getFrente()
{
	if (bicolaVacia())
	{
		//cout<<"Bicola vacia: ";
		return 0;
	}
		return frente;
}
int Bicola::getDatoFinal()
{
	if (bicolaVacia())
	{
		//cout<<"Bicola vacia: ";
		return 0;
	}
	else
		return final -> dato;
}
NodoCola* Bicola::getFinal()
{
	if (bicolaVacia())
	{
		//cout<<"Bicola vacia: ";
		return 0;
	}
	else
		return final;
}
