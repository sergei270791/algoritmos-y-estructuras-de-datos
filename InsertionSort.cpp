//Clase 02
//Insertion Sort
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

void ordInsercion(int vector[], int n){
	int comp;
	for(int i = 0; i<n-1;i++){
		comp=vector[i+1];
		for(int j = i; j>=0;j--){
			if (vector[j] > comp)
				intercambiar(vector[j],vector[j+1]);
			else
				break;
		}
	}
}
void ordInsercion(string vector[], int n){
	string comp;
	for(int i = 0; i<n-1;i++){
		comp=vector[i+1];
		for(int j = i; j>=0;j--){
			if (vector[j] > comp)
				intercambiar(vector[j],vector[j+1]);
			else
				break;
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
	    ordInsercion(vector,n);
	    imprimir(vector,n);
	}
	else
	{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordInsercion(vector,n);
	    imprimir(vector,n);
	}
    return 0;
}