#ifndef DECORADORPRODUCTO_H
#define DECORADORPRODUCTO_H
#include "decoradorAbs.h"
#include "producto.h"

class decoradorProducto :public decoradorAbs	//HACER .CPP
{												//ver que tan necesario es hacer un decorador para cada subclase producto
												//depende si se va a trabajar solo con producto*
public:
	decoradorProducto(compraProducto* compraPtr, producto* productoPtr)
		: decoradorAbs(productoPtr->getPrecioCosto(), compraPtr), _productoPtr(productoPtr) {}
	virtual ~decoradorProducto(){}
	virtual string getNombre() {
		return _productoPtr->getNombre();
	}
	virtual string getCodigo() {
		return _productoPtr->getCodigo();
	}
	virtual double getPrecioAcumulado() {
		return this->_precioAcumulado + _compraPtr->getPrecioAcumulado();
	}
	virtual double getPrecio() { //verificar impuestos y cosas
		return _productoPtr->getPrecioCosto();
	}
	virtual string toString() {
		stringstream s;
		s << this->getNombre()<<" [ " << this->getCodigo()<<" ]	- >" << "	Precio: " << this->getPrecio() << endl;
		s << _compraPtr->toString() << endl;
		return s.str();
	}

private:
	producto* _productoPtr;

};

#endif // !DECORADORPRODUCTO_H



