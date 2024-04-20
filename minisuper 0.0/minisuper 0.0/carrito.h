#ifndef CARRITO_H
#define CARRITO_H
#include "compraProducto.h"

class carrito: public compraProducto
{
public:
	carrito();
	virtual ~carrito();
	virtual string getNombre();
	virtual string getCodigo();
	virtual double getPrecio();
	virtual string toString();
	virtual double getPrecioAcumulado();

private:


};

#endif // !CARRITO_H



