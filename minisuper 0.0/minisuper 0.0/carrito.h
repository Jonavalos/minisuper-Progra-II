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
	virtual double getPrecioCosto();
	virtual double getCategoria();

	virtual void setCompraPtr(compraProducto* c);
	virtual void setProducto(producto* prod);
	virtual void setPrecioAcumulado();
	virtual void setCantidad(int);
	virtual void setExistencia(int);

	virtual void aumentarCantidad();
private:


};

#endif // !CARRITO_H



