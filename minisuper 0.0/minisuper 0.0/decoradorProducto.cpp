#include "decoradorProducto.h"

decoradorProducto::decoradorProducto()
	: decoradorAbs(0.0, nullptr), _productoPtr(nullptr) {}

decoradorProducto::decoradorProducto(compraProducto* compraPtr, producto* productoPtr)
	: decoradorAbs(productoPtr->getPrecioCosto(), compraPtr), _productoPtr(productoPtr) {}

decoradorProducto::~decoradorProducto() {}

string decoradorProducto::getNombre() {
	return _productoPtr->getNombre();
}

string decoradorProducto::getCodigo() {
	return _productoPtr->getCodigo();
}

double decoradorProducto::getPrecioAcumulado() {
	return this->_precioAcumulado + _compraPtr->getPrecioAcumulado();
}

double decoradorProducto::getPrecio() { //verificar impuestos y cosas
	return _productoPtr->getPrecioCosto();
}

void decoradorProducto::setCompraPtr(compraProducto* c) {
	this->_compraPtr = c;
}

void decoradorProducto::setProducto(producto* prod) {
	_productoPtr = prod;
}

void decoradorProducto::setPrecioAcumulado() {
	if (_productoPtr != nullptr)
		_precioAcumulado = _productoPtr->getPrecioCosto();
}

string decoradorProducto::toString() {
	stringstream s;
	s << this->getNombre() << " [ " << this->getCodigo() << " ]	- >" << "	Precio: " << this->getPrecio() << endl;
	s << _compraPtr->toString() << endl;
	return s.str();
}