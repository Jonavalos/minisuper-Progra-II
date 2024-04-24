#include "nodoVenta.h"

NodoVenta::NodoVenta() {
	_ventaPtr = NULL;
	_ptrNod = NULL;
}

NodoVenta::NodoVenta(venta& venta, NodoVenta* ptr) {
	_ventaPtr = &venta;
	_ptrNod = ptr;
}

NodoVenta::~NodoVenta() {
	if (_ventaPtr != nullptr) {
		delete _ventaPtr;
	}
}

void NodoVenta::setObj(venta& venta) {
	if (_ventaPtr != NULL) delete _ventaPtr;
	_ventaPtr = &venta;
}

void NodoVenta::setSigNodo(NodoVenta* ptr) {
	_ptrNod = ptr;
}

venta* NodoVenta::getObj() {
	return _ventaPtr;
}

NodoVenta* NodoVenta::getSigNodo() {
	return _ptrNod;
}
