#ifndef NODOGENVENTA_H
#define NODOGENVENTA_H
#include "bibliotecas.h"
#include "venta.h"

class NodoVenta {
private:
	venta* _ventaPtr;
	NodoVenta* _ptrNod;
public:
	NodoVenta();
	NodoVenta(venta& per, NodoVenta* ptr);
	virtual ~NodoVenta();

	void setObj(venta& per);
	void setSigNodo(NodoVenta* ptr);

	venta* getObj();
	NodoVenta* getSigNodo();

};

#endif // !NODOGENVENTA_H