#include "venta.h"

venta::venta() : _cliente(nullptr), _decProducto(nullptr), _total(0), _IVATotal(0.0) {}

venta::venta(cliente* client, compraProducto* decProd, double total, double iva): _cliente(client), _decProducto(decProd), _total(total), _IVATotal(iva) {}

venta::~venta()
{
	if (_cliente) {
		delete _cliente;
	}
	if (_decProducto) {
		delete _decProducto;
	}
	
}

string venta::toString() const
{
	stringstream s;

	//fecha y hora
	auto now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);

	s << "Fecha y hora actual: " << ctime(&now_c);
	if (_cliente) {
		s << _cliente->toString() << endl << endl;
	}	
	s << "Cant" << setw(10) << "Concepto" << setw(20) << "Precio" << setw(11) << "Importe" << endl;
	if (_decProducto) {
		s << _decProducto->toString() << endl;
		s << "Subtotal: " << setw(5) << _decProducto->getPrecioAcumulado() << endl;
	}	
	s << "IVA: " << setw(10) << _IVATotal << endl;
	s << "TOTAL: " << setw(8) << _total << endl;

	return s.str();
}

double venta::getTotal()
{
	return _total;
}

cliente* venta::getCliente()
{
	return _cliente;
}
