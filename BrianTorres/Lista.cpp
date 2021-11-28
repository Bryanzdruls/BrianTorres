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
	Nodo* x = new Nodo();

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
	int aux;
	Nodo* p = head, *q;

	do
	{	
		q = p->Getld();
		while (q!= head)
		{
			if (p->GetDato() > q->GetDato())
			{
				aux = q->GetDato();
				q->SetDato(p->GetDato());
				p->SetDato(aux);
			}
			q=q->Getld();
		}
		p = p->Getld();
		q = q->Getld();
	} while (p!= head);
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
		cout << "|" << p->GetDato() << "|";
		p = p->Getld();
	}
	while (p != head);
}

void Lista::Validacion(Lista* Lista1, Lista* Lista2, Lista* Lista3)
{
	
	if (Lista1->head ==nullptr )
	{
		cout << "Lista 1 vacia." << endl;
		if (Lista2->head == nullptr)
		{
			cout << "Lista 2 vacia." << endl;

			if (Lista3->head == nullptr)
			{
				cout << "Lista 3 vacia." << endl;
			}
		}
	}			
	if (Lista1->head != nullptr)
	{
		cout<<"Lista 1:" << endl;
		Lista1->Mostrar();
		cout << endl;

		if (Lista2->head != nullptr)
		{
			cout << "Lista 2:" << endl;
			Lista2->Mostrar();
			cout << endl;
			if (Lista3->head != nullptr)
			{
				cout << "Lista 3:" << endl;
				Lista3->Mostrar();
				cout << endl;
			}
		}
	}
}
