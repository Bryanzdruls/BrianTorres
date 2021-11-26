#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista()
{
	head = nullptr;
	end = nullptr;
}

void Lista::InsertarInicio(int d)
{
	Nodo* x = new Nodo();

	x->SetDato(d);

	if(head ==nullptr)
	{
		head = x;
		end = x;
		x->Setld(head);
		x->Setli(head);
	}
	else
	{
		x->Setld(head);
		head->Setli(x);
		head = x;
		//
		end->Setld(head);
		head->Setli(end);
	}
 }

void Lista::InsertarFinal(int d)
{
	Nodo* x = new Nodo(), * p;

	x->SetDato(d);

	if (head == nullptr)
	{
		head = x;
		end = x;
		x->Setld(head);
		x->Setli(head);
	}
	else
	{
		end->Setld(x);
		x->Setli(end);
		end = x;
		end->Setld(head);
		head->Setli(end);

	}
}


void Lista::InsertarOrdenado(int d)
{

}

void Lista::Ordenar()
{
}

void Lista::Buscar()
{
}

void Lista::Reemplazar()
{
}

void Lista::Eliminar()
{
}

void Lista::SumarListas()
{
}
// Excluido.
void Lista::Mostrar()
{
	Nodo* p= head;
	do
	{
		cout<<"|" <<p->GetDato() <<"|";
		p = p->Getld();
	}
	while (p != head);
}
