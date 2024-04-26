#include "decoradorProducto.h"

decoradorProducto::decoradorProducto()
	: decoradorAbs(0.0, 1, nullptr), _productoPtr(nullptr) {}

decoradorProducto::decoradorProducto(compraProducto* compraPtr, producto* productoPtr)
	: decoradorAbs(productoPtr->getPrecioCosto(), _cantidad, compraPtr), _productoPtr(productoPtr) {}

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
	return _productoPtr->getPrecioCosto() * 1.13 * getCategoria();
}

double decoradorProducto::getPrecioCosto() {
	return _productoPtr->getPrecioCosto();
}

int decoradorProducto::getLimite() {
	return _productoPtr->getLimite();
}

int decoradorProducto::getExistencia() {
	return _productoPtr->getExistencia();
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

double decoradorProducto::getCategoria() {
	if (_productoPtr->getCategoria() == "01") {
		return 1.15;
	}
	else if (_productoPtr->getCategoria() == "02") {
		return 1.2;
	}
	else if (_productoPtr->getCategoria() == "03") {
		return 1.3;
	}
	else {
		return 0;
	}
}

void decoradorProducto::aumentarCantidad() {
	_cantidad++;
}

void decoradorProducto::setCantidad(int cant) {
	_cantidad = cant;
}

void decoradorProducto::setExistencia(int exist) {
	_productoPtr->setExistencia(_productoPtr->getExistencia() - exist);
}

string decoradorProducto::toString() {
	stringstream s;
	s << _cantidad << setw(10) << this->getNombre() << " [ " << this->getCodigo() << " ]" << setw(13) << this->getPrecioCosto() << setw(13) <<  this->getPrecio() << endl;
	s << _compraPtr->toString();
	return s.str();
}