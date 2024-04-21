#ifndef DECORADORPRODUCTO_H
#define DECORADORPRODUCTO_H
#include "decoradorAbs.h"
#include "producto.h"

class decoradorProducto :public decoradorAbs	//HACER .CPP
{												//ver que tan necesario es hacer un decorador para cada subclase producto
												//depende si se va a trabajar solo con producto*
public:
	decoradorProducto();
	decoradorProducto(compraProducto* compraPtr, producto* productoPtr);
	virtual ~decoradorProducto();
	virtual string getNombre();
	virtual string getCodigo();
	virtual double getPrecioAcumulado();
	virtual double getPrecio();
	virtual void setCompraPtr(compraProducto* c);
	virtual void setProducto(producto* prod);
	virtual void setPrecioAcumulado();

	virtual string toString();

private:
	producto* _productoPtr;

};

#endif // !DECORADORPRODUCTO_H



