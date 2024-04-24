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