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

	double getTotal();
	cliente* getCliente();

	friend ostream& operator << (ostream& COUT, venta& obj) {
		COUT << obj.toString() << endl;
		return COUT;
	}

	virtual void guardar(fstream& strm) {

		strm << _cliente->getCedula() << SEPARA_VALOR;
		strm << _total << SEPARA_VALOR;
		strm << _IVATotal << SEPARA_VALOR;
		_decProducto->guardar(strm);

	}

	static venta* recuperar(fstream& strm) {

		string cedStr = "", totalStr = "", ivaStr = "";

		getline(strm, cedStr, SEPARA_VALOR);
		getline(strm, totalStr, SEPARA_VALOR);
		getline(strm, ivaStr, SEPARA_VALOR);

		if (totalStr == "" || ivaStr == "")
			return nullptr;

		double total = convertirDouble(totalStr);
		double iva = convertirDouble(ivaStr);

		cliente* c = new cliente(cedStr);


		return new venta(c, decoradorProducto::recuperar1(strm), total, iva);
	}


private:
	cliente* _cliente;
	compraProducto* _decProducto;
	double _total;
	double _IVATotal;
};

#endif // !VENTA_H



