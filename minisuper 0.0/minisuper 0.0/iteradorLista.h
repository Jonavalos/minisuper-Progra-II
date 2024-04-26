#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H

#include "nodoVenta.h"

class iteradorLista //itereador para contenedorLista (lista de ventas)
{
public:
	iteradorLista(NodoVenta* primero);
	virtual ~iteradorLista();
	virtual bool masElementos();
	virtual venta* proximoElemento();
	virtual string toString() const;

private:
	NodoVenta* _actual;
	//el iterador apunta a la lista con _actual, itera sobre la lista, y luego se destruye
};

#endif // !ITERADORLISTA_H

