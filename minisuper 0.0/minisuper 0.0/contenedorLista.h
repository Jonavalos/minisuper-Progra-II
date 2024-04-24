#ifndef LISTAGENVENTA_H
#define LISTAGENVENTA_H
#include "nodoVenta.h"

class ContenedorLista {
private:
	NodoVenta* _ppio;
public:
	ContenedorLista();
	virtual ~ContenedorLista();
	void ingresaDePrimero(venta& venta);
	void ingresaDeUltimo(venta& venta);
	bool eliminarLugar(int);

	string toString() const;
};


#endif // !LISTAGENVENTA_H