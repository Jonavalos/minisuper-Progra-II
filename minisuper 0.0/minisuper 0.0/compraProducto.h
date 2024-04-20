#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H
#include "bibliotecas.h"

class compraProducto
{
public:
	compraProducto(double precioAcumulado) : _precioAcumulado(precioAcumulado){}
	virtual ~compraProducto(){}
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual double getPrecio() = 0;
	virtual string toString() = 0;
	virtual double getPrecioAcumulado() = 0;

protected:
	double _precioAcumulado;

};


#endif // !COMPRAPRODUCTO_H


