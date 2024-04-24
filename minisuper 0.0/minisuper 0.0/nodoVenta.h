#ifndef NODOGENVENTA_H
#define NODOGENVENTA_H
#include "bibliotecas.h"
#include "venta.h"

class NodoGenVenta {
private:
	venta* _ventaPtr;
	NodoGenVenta* _ptrNod;
public:
	NodoGenVenta();
	NodoGenVenta(venta& per, NodoGenVenta* ptr);
	virtual ~NodoGenVenta();

	void setObj(venta& per);
	void setSigNodo(NodoGenVenta* ptr);

	venta* getObj();
	NodoGenVenta* getSigNodo();

};

#endif // !NODOGENVENTA_H