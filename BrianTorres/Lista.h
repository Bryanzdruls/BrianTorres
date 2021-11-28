#pragma once
#include"Nodo.h"
class Lista
{	//Atributos.
private: Nodo* head, *end;
	//Metodos.
public:
	Lista();
	void InsertarInicio(int d);
	void InsertarFinal(int d);
	void InsertarOrdenado(int d);
	void Ordenar();
	void Buscar();
	void Reemplazar();
	void Eliminar();
	void SumarListas();
	//No requerido.
	void Mostrar();
	
	//Validacion.
	void Validacion(Lista* Lista1, Lista* Lista2, Lista* Lista3);
};

