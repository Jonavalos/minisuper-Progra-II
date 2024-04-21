#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H
#include "bibliotecas.h"
#include "producto.h"
class compraProducto
{
public:
	compraProducto(double precioAcumulado);
	virtual ~compraProducto();
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual double getPrecio() = 0;
	virtual string toString() = 0;
	virtual double getPrecioAcumulado() = 0;

	virtual void setCompraPtr(compraProducto* c) = 0;
	virtual void setProducto(producto* prod) = 0;
	virtual void setPrecioAcumulado() = 0;

protected:
	double _precioAcumulado;

};


#endif // !COMPRAPRODUCTO_H


