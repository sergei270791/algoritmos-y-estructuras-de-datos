//Clase 03
//Shell sort
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

void ordShell(int vector[], int n) {
	bool cambio;
	int s = n / 2,rec=0;
	cout<<"Recorrido \t Salto \t Intercambios \t\t Lista\n";
	while (s>=1) 
	{
		cambio = true; //Hubo cambios
		while (cambio)
		{
			cambio=false;
			cout<<++rec<<"\t\t"<<s<<"\t";
			for (int i = 0; i < n - s; i++) 
				if (vector[i] > vector[i + s]) 
				{
					intercambiar(vector[i], vector[i + s]);
					cout<<"("<<vector[i]<<","<<vector[i+s]<<") ";
					cambio = true;
				}
			cout<<"\t\t\t";
			imprimir(vector,n);
		}	
		s /= 2;
	}
}

void ordShell(string vector[], int n) {
	bool cambio;
	int s = n / 2,rec=0;
	cout<<"Recorrido \t Salto \t Intercambios \t\t Lista\n";
	while (s>=1) 
	{
		cambio = true; //Hubo cambios
		while (cambio)
		{
			cambio=false;
			cout<<++rec<<"\t\t"<<s<<"\t";
			for (int i = 0; i < n - s; i++) 
				if (vector[i] > vector[i + s]) 
				{
					intercambiar(vector[i], vector[i + s]);
					cout<<"("<<vector[i]<<","<<vector[i+s]<<") ";
					cambio = true;
				}
			cout<<"\t\t\t";
			imprimir(vector,n);
		}	
		s /= 2;
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
	    ordShell(vector,n);
	    imprimir(vector,n);
	}
	else
	{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordShell(vector,n);
	    imprimir(vector,n);
	}
    return 0;
}