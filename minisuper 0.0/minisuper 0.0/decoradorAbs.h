#ifndef DECORADORABS_H
#define DECORADORABS_H
#include "compraProducto.h"

class decoradorAbs: public compraProducto
{
public:
	decoradorAbs(double precioAcumulado, compraProducto* compraPtr): compraProducto(precioAcumulado), _compraPtr(compraPtr) {}
	virtual ~decoradorAbs(){}

	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual double getPrecioAcumulado() = 0;
	virtual double getPrecio() = 0;
	virtual string toString() = 0;

protected:
	compraProducto* _compraPtr;

};

#endif // !DECORADORABS_H



