//Clase 02
//Selection Sort
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

int minimo(int vector[],int k, int n){
	int min = vector[k];
	int pos = k;
	for(int i = k; i<n; i++){
		if(vector[i]<min){
			min = vector[i];
			pos = i;
		}
	}
	return pos;
}

int minimo(string vector[],int k, int n){
	string min = vector[k];
	int pos = k;
	for(int i = k; i<n; i++){
		if(vector[i]<min){
			min = vector[i];
			pos = i;
		}
	}
	return pos;
}

void ordSeleccion(int vector[], int n){
	for(int i = 0; i<n-1;i++){
		if(vector[i] > vector[minimo(vector, i, n)]){
			intercambiar(vector[i],vector[minimo(vector, i, n)]);
		}
	}
}

void ordSeleccion(string vector[], int n)
{
	for(int i = 0; i<n-1;i++){
		if(vector[i] > vector[minimo(vector, i, n)]){
			intercambiar(vector[i],vector[minimo(vector, i, n)]);
		}
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
	    ordSeleccion(vector,n);
	    imprimir(vector,n);
	}
	else
	{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordSeleccion(vector,n);
	    imprimir(vector,n);
	}
    return 0;
}
