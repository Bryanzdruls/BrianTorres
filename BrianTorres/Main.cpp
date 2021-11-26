#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include"Lista.h"
//LISTA DOBLEMENTE LIGADA CIRCULAR.

using namespace std;
void menuListas();
int main()
{
	//Instancia.
	Lista* L1 = new Lista();
	Lista* L2 = new Lista();
	Lista* L3 = new Lista();
	int opc, dec, dato;
	opc = 0;
	dec = 0;
	dato = 0;
	do
	{
		menuListas();
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Desea ingresar un dato para cual lista: " << endl;
			cout << "1. Lista 1." << endl;
			cout << "2. Lista 2." << endl;
			cin >> dec;
			if (dec == 1)
			{
				cout << "Ingrese un dato: " << endl;
				cin >> dato;
				L1->InsertarInicio(dato);
			}
			else
			{
				if (dec == 2)
				{
					cout << "Ingrese un dato: " << endl;
					cin >> dato;
					L2->InsertarInicio(dato);
				}
			}
			break;
		case 2:
			cout << "Desea ingresar un dato para cual lista: " << endl;
			cout << "1. Lista 1." << endl;
			cout << "2. Lista 2." << endl;
			cin >> dec;
			if (dec == 1)
			{
				cout << "Ingrese un dato: " << endl;
				cin >> dato;
				L1->InsertarFinal(dato);
			}
			else
			{
				if (dec == 2)
				{
					cout << "Ingrese un dato: " << endl;
					cin >> dato;
					L2->InsertarFinal(dato);
				}
			}
			break;
		case 3:
			cout << "Desea ingresar un dato para cual lista: " << endl;
			cout << "1. Lista 1." << endl;
			cout << "2. Lista 2." << endl;
			cin >> dec;
			if (dec == 1)
			{
				cout << "Ingrese un dato: " << endl;
				cin >> dato;
				L1->InsertarOrdenado(dato);
			}
			else
			{
				if (dec == 2)
				{
					cout << "Ingrese un dato: " << endl;
					cin >> dato;
					L2->InsertarOrdenado(dato);
				}
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6://Validar cuando la lista este vacia. con switch.
			L1->Mostrar();
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			break;
		}
	} while (opc != 9);

	cin.get();
	system("cls");
	return 0;
}

void menuListas()
{
	cout << "\n \t Bienvenidos\n\n";
	cout << "\n \t Lista Doble Circular\n\n";
	cout << "1. Insertar al Inicio. " << endl;
	cout << "2. Insertar al Final. " << endl;
	cout << "3. Insertar al Ordenado. " << endl;
	cout << "4. Ordenar lista. " << endl;
	cout << "5. Buscar dato. " << endl;
	cout << "6. Mostrar Listas. " << endl;
	cout << "7. Sumar listas. " << endl;
	cout << "8. Eliminar. " << endl;
	cout << "9. Salir." << endl;
	cout << "\t ¿Que desea hacer?\n";
}