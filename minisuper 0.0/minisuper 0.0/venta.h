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
	venta(cliente* client, compraProducto* decProd, double total, double iva);
	virtual ~venta();

	string toString() const;

private:
	cliente* _cliente;
	compraProducto* _decProducto;
	double _total;
	double _IVATotal;
};

#endif // !VENTA_H



