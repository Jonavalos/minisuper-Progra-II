#ifndef VENTA_H
#define VENTA_H
#include "fecha.h"
#include "cliente.h"
#include "decoradorAbs.h"
#include "decoradorProducto.h"

class venta
{
public:
	venta();
	venta(cliente* client, fecha* fech, compraProducto* decProd);
	virtual ~venta();

	string toString() const;

private:
	cliente* _cliente;
	fecha* _fecha;
	compraProducto* _decProducto;

};

#endif // !VENTA_H



