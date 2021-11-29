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
	Nodo* x = new Nodo(), *p=head, *q;
	x->SetDato(d);
	p->Setld(x);
	do
	{
		q = p;
		p = p->Getld();
	} while ((p!= head )&& p->GetDato() <d);
	if (head==p)
	{
		head = x;
	}
	else
	{
		q->Setld(x);
	}
	x->Setld(p);
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

void Lista::Buscar(int d)
{
	Nodo* p = head, * q = head->Getld();
	string dec;
	int noencontrado= 0;
	do
	{
		if (p->GetDato() == d)
		{
			noencontrado = 1;
			cout << "\tEl dato ha sido encontrado." << endl;
			cout << "Desea eliminar el dato (Si, No)" << endl;
			cin >> dec;
			if (dec == "Si" || dec == "si" || dec == "SI" || dec == "sI")
			{				
				q->Setli(p->Getli());
				p = p->Getli();
				p->Setld(q);
				p = p->Getld();	
				if (p == head)
				{
					cout << "SOLO HAY UN NODO." << endl;
					p = nullptr;
					head = nullptr;
				}
			}
			else
			{
				q = q->Getld();
				p = p->Getld();
			}
		}
		else
		{
			q = q->Getld();
			p = p->Getld();
		}
	} while (p!=head);
	if (noencontrado == 0)
	{
		cout << "El dato no fue encontrado." << endl;
	}
}

void Lista::Reemplazar(int d)
{
	int reemplazo = 0, i=0;
	Nodo* p = head;
	Mostrar();
	do
	{	
		if (p->GetDato() == d)
		{
			i++;
			cout << "\tEl dato numero "<< i<<" ha sido encontrado." << endl;
			cout << "Por cual dato lo desea reemplazar: " << endl;
			cin >> reemplazo;
			p->SetDato(reemplazo);
			cout << "El dato ha sido Reemplazado correctamente" << endl;
		}
		p = p->Getld();
	} while (p != head );
}

void Lista::Eliminar()
{
	Nodo* p=head;
	do
	{
		p->SetDato(NULL);
		p = p->Getld();
	} while (p!=head);
	head = nullptr;
	cout << "Los datos de la lista se eliminaron correctamente." << endl;
}

void Lista::SumarListas(Lista *lista1, Lista *lista2, Lista *lista3)
{
	Nodo* p, * q;
	p = lista1->head;
	q = lista2->head;
	bool sumarHead = true;
	ValidacionSuma(lista1, lista2, lista3);
	if (p != nullptr && q != nullptr) 
	{
		do
		{
			if (sumarHead == true || (p != lista1->head && q != lista2->head))
			{
				lista3->InsertarFinal(p->GetDato() + q->GetDato());
				p = p->Getld();
				q = q->Getld();
				sumarHead = false;
			}
			else
			{
				if (p != lista1->head)
				{
					lista3->InsertarFinal(p->GetDato());
					p = p->Getld();
				}
				if (q != lista2->head)
				{
					lista3->InsertarFinal(q->GetDato());
					q = q->Getld();
				}
			}
		} while (p != lista1->head || q != lista2->head);
		cout << "Las listas han sido sumadas y almacenadas en la Lista 3." << endl;
	}
	else
	{
		cout << "No se pueden sumar listas vacias." << endl;
	}
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

void Lista::Validacion(Lista* Lista1, Lista* Lista2, Lista* Lista3, int dec)
{
	
	switch (dec)
	{
	case 1:
		if(Lista1->head == nullptr)
		{
			cout << "Lista 1 vacia." << endl;
		}
		else
		{
			cout << "Lista 1:" << endl;
			Lista1->Mostrar();
			cout << endl;
		}	
		break;
	case 2:
		if (Lista2->head == nullptr)
		{
			cout << "Lista 2 vacia." << endl;
		}
		else
		{
			cout << "Lista 2:" << endl;
			Lista2->Mostrar();
			cout << endl;
		}

		break;
	case 3:
		if (Lista3->head != nullptr)
		{
			cout << "Lista 3:" << endl;
			Lista3->Mostrar();
			cout << endl;
		}
		else
		{
			cout << "Lista 3 vacia." << endl;
			
		}
	case 4:
		if(Lista1->head != nullptr && Lista2->head != nullptr && Lista3->head != nullptr)
		{
			cout << "Lista 1:" << endl;
			Lista1->Mostrar();
			cout << endl;
			cout << "Lista 2:" << endl;
			Lista2->Mostrar();
			cout << endl;
			cout << "Lista 3:" << endl;
			Lista3->Mostrar();
			cout << endl;
		}
		else
		{
			if (Lista1->head == nullptr)
			{
				cout << "Lista 1 vacia." << endl;
			}
			else
			{
				cout << "Lista 1:" << endl;
				Lista1->Mostrar();
				cout << endl;
			}
			if (Lista2->head == nullptr)
			{
				cout << "Lista 2 vacia." << endl;
			}
			else
			{
				cout << "Lista 2:" << endl;
				Lista2->Mostrar();
				cout << endl;
			}
			if (Lista3->head == nullptr)
			{
				cout << "Lista 3 vacia." << endl;
			}
			else
			{
				cout << "Lista 3:" << endl;
				Lista3->Mostrar();
				cout << endl;
			}
		}
	default:
		break;
	}

}


void Lista::ValidacionSuma(Lista* Lista1, Lista* Lista2, Lista* Lista3)
{
	if(Lista1->head == nullptr || Lista2->head == nullptr || Lista3->head == nullptr)
	{
		if (Lista1->head == nullptr)
		{
			cout << "Lista 1 vacia." << endl;
		}
		if (Lista2->head == nullptr)
		{
			cout << "Lista 2 vacia." << endl;
		}
		if (Lista3->head == nullptr)
		{
		
		}
	}
	else
	{
		if (Lista1->head != nullptr)
		{
			cout << "Lista 1:" << endl;
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
}