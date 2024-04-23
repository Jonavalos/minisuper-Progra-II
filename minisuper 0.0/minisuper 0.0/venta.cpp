#include "venta.h"

venta::venta() : _cliente(nullptr), _decProducto(nullptr), _total(0), _IVATotal(0.0) {}

venta::venta(cliente* client, compraProducto* decProd, double total, double iva): _cliente(client), _decProducto(decProd), _total(total), _IVATotal(iva) {}

venta::~venta()
{
}

string venta::toString() const
{
	stringstream s;

	//fecha y hora
	auto now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);

	s << "Factura N: " << endl;		//sacar número de factura mediante el contenedor de fact
	s << "Fecha y hora actual: " << ctime(&now_c);
	s << _cliente->toString() << endl << endl;
	s << "Cant" << setw(10) << "Concepto" << setw(20) << "Precio" << setw(11) << "Importe" << endl;
	s << _decProducto->toString() << endl;
	s << "Subtotal: " << setw(5) << _decProducto->getPrecioAcumulado() << endl;
	s << "IVA: " << setw(10) << _IVATotal << endl;
	s << "TOTAL: " << setw(8) << _total << endl;

	return s.str();
}
