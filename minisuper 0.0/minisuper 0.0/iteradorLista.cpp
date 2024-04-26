#include "iteradorLista.h"

iteradorLista::iteradorLista(NodoVenta* primero)
	: _actual(primero) {}

iteradorLista::~iteradorLista()
{
}

bool iteradorLista::masElementos()
{
	return _actual != nullptr; //deja de iterar cuando actual ve a nullptr
}
venta* iteradorLista::proximoElemento()
{
	venta* obj = nullptr; //aux parecido a pex
	if (masElementos()) {
		obj = _actual->getObj();
		_actual = _actual->getSigNodo();
	}
	return obj;
}

string iteradorLista::toString() const
{
	return "";
}
