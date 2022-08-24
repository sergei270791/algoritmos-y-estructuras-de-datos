//Clase 03
//Bubble Sort bidireccional
#include <iostream>
#include <string>
using namespace std;

void lectura(int vector[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"Ingrese un dato ("<<i<<"): ";
        cin>>vector[i];
    }
}

void lectura(string vector[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"Ingrese un dato ("<<i<<"): ";
        getline(cin,vector[i]);
    }

}

void imprimir(int vector[],int n)
{
	for (int i=0;i<n;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}

void imprimir(string vector[],int n)
{
	for (int i=0;i<n;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}

void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void intercambiar(string& x, string& y) {
	string temp = x;
	x = y;
	y = temp;
}

void ordBurbuja(int vector[], int n){
	bool cambio;	
	int inicio=0;
	int final=n-1;
	while(inicio<final)
	{
		cambio=false; // Asume que esta ordenado
		//Bucle de izquierda a derecha aplicando Burbuja
		for (int j=inicio ;j<final; j++)
			if (vector[j]>vector[j+1])
			{
				intercambiar(vector[j],vector[j+1]);
				cambio=true;
			}
		if (!cambio) //Sin cambio entonces termina
			return;
		//Bucle de derecha a izquierda aplicando Burbuja
		for (int j=final-1 ;j>inicio; j--)
			if (vector[j-1]>vector[j])
			{
				intercambiar(vector[j-1],vector[j]);
				cambio=true;
			}
		if (!cambio) //Sin cambio entonces termina
			return;
		final--;
		inicio++;
	}	
}

void ordBurbuja(string vector[], int n){
	bool cambio;	
	int inicio=0;
	int final=n-1;
	while(inicio<final)
	{
		cambio=false; // Asume que esta ordenado
		//Bucle de izquierda a derecha aplicando Burbuja
		for (int j=inicio ;j<final; j++)
			if (vector[j]>vector[j+1])
			{
				intercambiar(vector[j],vector[j+1]);
				cambio=true;
			}
		if (!cambio) //Sin cambio entonces termina
			return;
		//Bucle de derecha a izquierda aplicando Burbuja
		for (int j=final-1 ;j>inicio; j--)
			if (vector[j-1]>vector[j])
			{
				intercambiar(vector[j-1],vector[j]);
				cambio=true;
			}
		if (!cambio) //Sin cambio entonces termina
			return;
		final--;
		inicio++;
	}	
}

int main()
{
    int n,ind,opc;
    cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
    cout<<"Ingresara enteros (1) o cadenas (2): ";
    cin>>opc;
    if (opc==1)
    {
		int* vector=new int[n];
	    lectura(vector,n);
	    ordBurbuja(vector,n);
	    imprimir(vector,n);
	}
	else
	{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordBurbuja(vector,n);
	    imprimir(vector,n);
	}
    return 0;
}