#include "nodoVenta.h"

NodoGenVenta::NodoGenVenta() {
	_ventaPtr = NULL;
	_ptrNod = NULL;
}

NodoGenVenta::NodoGenVenta(venta& venta, NodoGenVenta* ptr) {
	_ventaPtr = &venta;
	_ptrNod = ptr;
}

NodoGenVenta::~NodoGenVenta() {}

void NodoGenVenta::setObj(venta& venta) {
	if (_ventaPtr != NULL) delete _ventaPtr;
	_ventaPtr = &venta;
}

void NodoGenVenta::setSigNodo(NodoGenVenta* ptr) {
	_ptrNod = ptr;
}

venta* NodoGenVenta::getObj() {
	return _ventaPtr;
}

NodoGenVenta* NodoGenVenta::getSigNodo() {
	return _ptrNod;
}
