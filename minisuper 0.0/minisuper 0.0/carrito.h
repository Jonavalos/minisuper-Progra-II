#ifndef CARRITO_H
#define CARRITO_H
#include "compraProducto.h"


class carrito: public compraProducto
{
public:
	carrito();
	virtual ~carrito();//(0.0, 0)
	virtual string getNombre();
	virtual string getCodigo();
	virtual double getPrecio();
	virtual string toString();
	virtual double getPrecioAcumulado();
	virtual double getPrecioCosto();
	virtual double getCategoria();
	virtual int getLimite();
	virtual int getExistencia();

	virtual void setCompraPtr(compraProducto* c);
	virtual void setProducto(producto* prod);
	virtual void setPrecioAcumulado();
	virtual void setCantidad(int);
	virtual void setExistencia(int);

	virtual void aumentarCantidad();

	virtual void guardar(fstream& strm) {
		strm << "carrito" << SEPARA_REGISTRO;
	}


private:


};

#endif // !CARRITO_H



