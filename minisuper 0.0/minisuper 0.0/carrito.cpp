#include "carrito.h"

carrito::carrito(): compraProducto(0.0, 0){}

carrito::~carrito()
{
}

string carrito::getNombre()
{
	return "carrito";
}

string carrito::getCodigo()
{
	return "";
}

double carrito::getPrecio()
{
	return 0.0;
}

string carrito::toString()
{
	stringstream s;
	s << "Fin Compra (carrito)" << endl;
	return s.str();
}

double carrito::getPrecioAcumulado()
{
	return _precioAcumulado;
}

double carrito::getPrecioCosto() {
	return 0.0;
}

double carrito::getCategoria() {
	return 0.0;
}

void carrito::setCompraPtr(compraProducto* c)
{
}

void carrito::setProducto(producto* prod)
{
}

void carrito::setPrecioAcumulado()
{
}

void carrito::setCantidad(int)
{
}

void carrito::aumentarCantidad()
{
}
