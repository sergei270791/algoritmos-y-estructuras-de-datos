//Clase 03
//Quick sort
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

void ordQuick(int vector[], int inicio, int fin) {
	int i,j,central; //indices
	int pivote;
	central=(inicio+fin)/2;
	pivote=vector[central];
	i=inicio;
	j=fin;
	while(i<=j)
	{
		while(vector[i]<pivote) i++;
		while(vector[j]>pivote) j--;
		if (i<=j)
		{
			intercambiar(vector[i],vector[j]);
			i++;
			j--;
		}
	}
	if (inicio<j)
		ordQuick(vector,inicio,j);
	if (i<fin)
		ordQuick(vector,i,fin);
}

void ordQuick(string vector[], int inicio, int fin) {
	int i,j,central; //indices
	string pivote;
	central=(inicio+fin)/2;
	pivote=vector[central];
	i=inicio;
	j=fin;
	while(i<=j)
	{
		while(vector[i]<pivote) i++;
		while(vector[j]>pivote) j--;
		if (i<=j)
		{
			intercambiar(vector[i],vector[j]);
			i++;
			j--;
		}
	}
	if (inicio<j)
		ordQuick(vector,inicio,j);
	if (i<fin)
		ordQuick(vector,i,fin);
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
	    ordQuick(vector,0,n-1);
	    imprimir(vector,n);
	}
	else
	{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordQuick(vector,0,n-1);
	    imprimir(vector,n);
	}
    return 0;
}