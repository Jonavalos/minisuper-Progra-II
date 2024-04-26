#include "contenedorLista.h"

ContenedorLista::ContenedorLista() {
	_ppio = nullptr;
}

ContenedorLista::~ContenedorLista()
{
	NodoVenta* PEx = _ppio;
	while (PEx != nullptr) {
		_ppio = _ppio->getSigNodo();
		delete PEx;
		PEx = _ppio;
	}
}

void ContenedorLista::ingresaDePrimero(venta& venta) {
	_ppio = new NodoVenta(venta, _ppio);
}

void ContenedorLista::ingresaDeUltimo(venta& venta) {
	NodoVenta* PEx = _ppio;
	NodoVenta* nuevoN = NULL;

	if (_ppio == NULL) {
		ingresaDePrimero(venta);
	}
	else {
		while (PEx->getSigNodo() != NULL) {
			PEx = PEx->getSigNodo();
		}
		nuevoN = new NodoVenta(venta, NULL);
		PEx->setSigNodo(nuevoN);
	}
}

bool ContenedorLista::eliminarLugar(int lugar) {
	NodoVenta* pex = _ppio;
	NodoVenta* victima = nullptr;
	int n = 1;

	if (lugar == 1) {
		victima = _ppio;
		_ppio = _ppio->getSigNodo();
		delete victima;
		return true;
	}
	else {
		while (pex->getSigNodo() != nullptr) {
			if (n + 1 == lugar) {
				victima = pex->getSigNodo();
				pex->setSigNodo(victima->getSigNodo());
				delete victima;
				return true;
			}
			n++;
			pex = pex->getSigNodo();
		}
	}
	return false;
}

string ContenedorLista::cedulasTop5Clientes()
{
	stringstream s;
	ordenar();

	/*for (int i = 1; i < 6;i++) {
		if (getVenta(i) != nullptr) {
			s << "Top "<<i<<" ->" << getVenta(i)->getCliente()->toString() << endl;
		}
	}*/

	
	if (getVenta(1) != nullptr) {
		s << "Top 1 ->" << getVenta(1)->getCliente()->toString() << endl;
	}
	if (getVenta(2) != nullptr) {
		s << "Top 2 ->" << getVenta(2)->getCliente()->toString() << endl;
	}
	if (getVenta(3) != nullptr) {
		s << "Top 3 ->" << getVenta(3)->getCliente()->toString() << endl;
	}
	if (getVenta(4) != nullptr) {
		s << "Top 4 ->" << getVenta(4)->getCliente()->toString() << endl;
	}
	if (getVenta(5) != nullptr) {
		s << "Top 5 ->" << getVenta(5)->getCliente()->toString() << endl;
	}
	
	return s.str();

}

void ContenedorLista::ordenar()
{
	for (int i = 1; i <= cantidadNodos(); i++) {
		for (int j = i + 1; j <= cantidadNodos(); j++) {
			if (getVenta(i)->getTotal() < getVenta(j)->getTotal()) {
				intercambiarNodos(getNodo(i), getNodo(j));
			}
		}
	}
}

bool ContenedorLista::intercambiarNodos(NodoVenta* n1, NodoVenta* n2)
{
	if (n1 == n2 || !n1 || !n2) { return false; }
	NodoVenta* nodoPrevio1 = nullptr;
	NodoVenta* pex1 = _ppio;
	NodoVenta* nodoPrevio2 = nullptr;
	NodoVenta* pex2 = _ppio;

	while (pex1 && pex1 != n1) {
		nodoPrevio1 = pex1;
		pex1 = pex1->getSigNodo();
	}
	while (pex2 && pex2 != n2) {
		nodoPrevio2 = pex2;
		pex2 = pex2->getSigNodo();
	}


	if (!pex1 || !pex2) { return false; }


	if (nodoPrevio1)
		nodoPrevio1->setSigNodo(n2);
	else
		_ppio = n2;

	if (nodoPrevio2)
		nodoPrevio2->setSigNodo(n1);
	else
		_ppio = n1;

	NodoVenta* auxiliar = n1->getSigNodo();
	n1->setSigNodo(n2->getSigNodo());
	n2->setSigNodo(auxiliar);

	return true;
}

int ContenedorLista::cantidadNodos()
{
	NodoVenta* pex = _ppio;
	int cantidad = 0;
	while (pex != nullptr) {
		cantidad++;
		pex = pex->getSigNodo();
	}
	return cantidad;
}

venta* ContenedorLista::getVenta(int lugar)
{
	//return getNodo(lugar)->getObj();
	int cont = 0;
	NodoVenta* pex = _ppio;
	if (lugar == 1) {
		return pex->getObj();
	}
	else {
		while (pex != nullptr && cont + 1 < lugar) {
			pex = pex->getSigNodo();
			cont++;
		}
		if (cont + 1 == lugar && pex != nullptr) {
			return pex->getObj();
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}

NodoVenta* ContenedorLista::getNodo(int lugar)
{
	int cont = 0;
	NodoVenta* pex = _ppio;
	if (lugar == 1) {
		return pex;
	}
	else {
		while (pex != nullptr && cont + 1 < lugar) {
			pex = pex->getSigNodo();
			cont++;
		}
		if (cont + 1 == lugar && pex!=nullptr) {
			return pex;
		}
		if (pex == nullptr) {
			return nullptr;
		}
	}
	return nullptr;
}

void ContenedorLista::reportarFacturasPorCliente(string cedula) {
	NodoVenta* pex = _ppio;

	while (pex != nullptr) {
		if (cedula == pex->getObj()->getCliente()->getCedula()) {
			cout << pex->getObj()->toString() << endl;
		}
		pex = pex->getSigNodo();
	}
}

string ContenedorLista::toString() const {
	stringstream s;
	NodoVenta* pex = _ppio;
	int n = 1;
	s << " ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ LISTA ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ " << endl;
	while (pex != nullptr) {
		s << n << " -> " << endl;
		s << pex->getObj()->toString() << endl;
		pex = pex->getSigNodo();
		n++;
	}
	s << " ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ " << endl;
	return s.str();
}

bool ContenedorLista::existe(string id)
{
	NodoVenta* pex = _ppio;
	while (pex != nullptr) {
		if (pex->getObj()->getCliente()->getCedula() == id) {
			return true;
		}
		pex = pex->getSigNodo();
	}
	return false;
}

double ContenedorLista::sumaTotalCliente(string id)
{
	double total=0.0;
	NodoVenta* pex = _ppio;
	while (pex != nullptr) {
		if (pex->getObj()->getCliente()->getCedula() == id) {
			total = total + pex->getObj()->getTotal();
		}
		pex = pex->getSigNodo();
	}
	return total;
}

string ContenedorLista::top5()
{
	string uno = "", dos = "", tres = "", cuatro = "", cinco = "";

	vecVentaCliente vec;

	NodoVenta* pex = _ppio;
	while (pex != nullptr) {
		
		ventaCliente* obj = new ventaCliente(pex->getObj()->getCliente()->getCedula(), sumaTotalCliente(pex->getObj()->getCliente()->getCedula()));
		vec.ingresar(obj);

		pex = pex->getSigNodo();
	}
	vec.ordenar();
	return vec.toString();
}

bool ContenedorLista::vecVentaCliente::existe(string id) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->_id == id)
			return true;
	}
	return false;
}

bool ContenedorLista::vecVentaCliente::ingresar(ventaCliente* obj) {
	if (can < 50) {
		if (!existe(obj->_id)) {
			vec[can++] = obj;
			return true;
		}
	}
	return false;
}

string ContenedorLista::vecVentaCliente::toString() {
	stringstream s;
	for (int i = 0; i < 5; i++) {
		s << i + 1 << " - " << vec[i]->_id << endl;
	}
	return s.str();
}

void ContenedorLista::vecVentaCliente::ordenar() {
	for (int i = 0; i < can; i++) {
		for (int j = i + 1; j < can; j++) {
			if (vec[i]->_total <= vec[j]->_total) {
				ventaCliente* aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

ContenedorLista::ventaCliente::ventaCliente() : _id(""), _total(0.0) {}

ContenedorLista::ventaCliente::ventaCliente(string id, double total) : _id(id), _total(total) {}