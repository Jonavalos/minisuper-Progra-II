#ifndef DECORADORABS_H
#define DECORADORABS_H
#include "compraProducto.h"

class decoradorAbs: public compraProducto
{
public:
	decoradorAbs(double precioAcumulado, int cantidad, compraProducto* compraPtr);
	virtual ~decoradorAbs();

	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual double getPrecioAcumulado() = 0;
	virtual double getPrecio() = 0;
	virtual string toString() = 0;
	virtual double getPrecioCosto() = 0;
	virtual double getCategoria() = 0;
	
	virtual void setCompraPtr(compraProducto* c) = 0;
	virtual void setProducto(producto* prod) = 0;
	virtual void setPrecioAcumulado() = 0;
	virtual void setCantidad(int) = 0;

	virtual void aumentarCantidad() = 0;

protected:
	compraProducto* _compraPtr;

};

#endif // !DECORADORABS_H



