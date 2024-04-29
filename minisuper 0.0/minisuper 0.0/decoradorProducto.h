#ifndef DECORADORPRODUCTO_H
#define DECORADORPRODUCTO_H
#include "decoradorAbs.h"
#include "producto.h"


class decoradorProducto :public decoradorAbs	
{												
												
public:
	decoradorProducto();
	decoradorProducto(compraProducto* compraPtr, producto* productoPtr);
	virtual ~decoradorProducto();
	virtual string getNombre();
	virtual string getCodigo();
	virtual double getPrecioAcumulado();
	virtual double getPrecio();
	virtual double getPrecioCosto();
	virtual int getLimite();
	virtual int getExistencia();
	virtual void setCompraPtr(compraProducto* c);
	virtual void setProducto(producto* prod);
	virtual void setPrecioAcumulado();
	virtual double getCategoria();
	virtual void aumentarCantidad();
	virtual void setCantidad(int);
	virtual void setExistencia(int);

	virtual string toString();

	virtual void guardar(fstream& strm) {
		setPrecioAcumulado();
		strm << _precioAcumulado << SEPARA_VALOR;
		_productoPtr->guardar(strm);

		_compraPtr->guardar(strm);
	}

	static compraProducto* recuperar1(fstream& strm);

private:
	producto* _productoPtr;

};

#endif // !DECORADORPRODUCTO_H



