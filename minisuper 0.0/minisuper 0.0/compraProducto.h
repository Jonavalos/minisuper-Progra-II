#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H
#include "bibliotecas.h"
#include "producto.h"
class compraProducto
{
public:
	compraProducto(double precioAcumulado, int cantidad);
	virtual ~compraProducto();
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual double getPrecio() = 0;
	virtual string toString() = 0;
	virtual double getPrecioAcumulado() = 0;
	virtual double getPrecioCosto() = 0;
	virtual double getCategoria() = 0;
	virtual int getLimite() = 0;
	virtual int getExistencia() = 0;

	virtual void setCompraPtr(compraProducto* c) = 0;
	virtual void setProducto(producto* prod) = 0;
	virtual void setPrecioAcumulado() = 0;
	virtual void setCantidad(int) = 0;
	virtual void setExistencia(int) = 0;

	virtual void aumentarCantidad() = 0;

	//
	virtual void guardar(fstream& strm) = 0;

protected:
	double _precioAcumulado;
	int _cantidad;
};


#endif // !COMPRAPRODUCTO_H


