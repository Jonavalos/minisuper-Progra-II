#include "venta.h"

venta::venta() : _cliente(nullptr), _fecha(nullptr), _decProducto(nullptr){}

venta::venta(cliente* client, compraProducto* decProd): _cliente(client), _decProducto(decProd){}


venta::~venta()
{
}

string venta::toString() const
{
	stringstream s;

	s << _cliente->toString();
	s << "Fecha de compra:" << _fecha->toString();
	s << "Info compra:" << endl;
	s << _decProducto->toString();
	s << "Precio Final" << endl;
	s << _decProducto->getPrecioAcumulado() << endl;
	return s.str();
}
