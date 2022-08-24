//Clase 02
//Interchange Sort
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

void ordIntercambio(int vector[], int n){
	for(int i = 0;i<n-1;i++){
		for(int j = i+1; j<n;j++){
			if(vector[i] > vector[j]){
				intercambiar(vector[i], vector[j]);
			}
		}
	}
}

void ordIntercambio(string vector[],int n)
{
    for(int i = 0;i<n-1;i++){
		for(int j = i+1; j<n;j++){
			if(vector[i] > vector[j]){
				intercambiar(vector[i], vector[j]);
			}
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
	    ordIntercambio(vector,n);
	    imprimir(vector,n);
	}
	else
	{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordIntercambio(vector,n);
	    imprimir(vector,n);
	}
    return 0;
}
