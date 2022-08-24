//Ordenamiento burbuja mejorado
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
void imprimir(int vector[],int n)
{
	for (int i=0;i<n;i++)
		cout<<vector[i]<<" ";
	cout<<endl;
}
void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
///Burbuja
void ordBurbuja(int vector[], int n){
	bool cambio;	
	for(int i = 0; i<n-1;i++)
	{
		cambio=false; // Asume que esta ordenado
		for (int j=0 ;j<n-1-i; j++)
			if (vector[j]>vector[j+1])
			{
				intercambiar(vector[j],vector[j+1]);
				cambio=true;
			}
		if (!cambio)
			return;
	}	
}
int main()
{
    int n;
    cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
	int* vector=new int[n];
    lectura(vector,n);
    ordBurbuja(vector,n);
    imprimir(vector,n);
	return 0;
}
//////////////////////////////////////////////////////
//Ordenamiento burbuja Bidireccional
///Burbuja Bidireccional
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

//Ordenacion Shell
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
		for (int i = 0; i < n - s; i++) 
			if (vector[i] > vector[i + s]) 
			{
				intercambiar(vector[i], vector[i + s]);
				cambio = true;
			}
		}	
		s /= 2;
	}
}

//Ordenacion Quick Sort
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



//Mezclar Listas ordenadas
#include <iostream>
using namespace std;
void lectura(int vector[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"Ingrese un dato ("<<i<<"): ";
        cin>>vector[i];
    }
}
void imprimir(int vector[],int n)
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
void mezclaLista(int vector[], int izq, int cen, int der)
{
	int* temporal= new int[der+1];
	int i,j,k;
	i=k=izq;
	j=cen+1;
	while(i<=cen && j<=der) 
	{
		if (vector[i]<vector[j])
		{
			temporal[k]=vector[i];
			i++;
			k++;
		}
		else
		{
			temporal[k]=vector[j];
			j++;
			k++;
		}
	}
	while(i<=cen)
			temporal[k++]=vector[i++];
	while(j<=der)
			temporal[k++]=vector[j++];
	//Copiando el temporal al vector
	for (int k=izq;k<=der;k++)
		vector[k]=temporal[k];
}
int main()
{
	int n,ind,opc,cen;
	cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
	int* vector=new int[n];
    lectura(vector,n);
    cout<<"Ingrese el indice central: ";
    cin>>cen;
    mezclaLista(vector,0,cen,n-1);
    imprimir(vector,n);
    return 0;
}