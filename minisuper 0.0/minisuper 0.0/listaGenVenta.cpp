#include "listaGenVenta.h"

ContenedorLista::ContenedorLista() {
	_ppio = nullptr;
}

void ContenedorLista::ingresaDePrimero(venta& venta) {
	_ppio = new NodoGenVenta(venta, _ppio);
}

void ContenedorLista::ingresaDeUltimo(venta& venta) {
	NodoGenVenta* PEx = _ppio;
	NodoGenVenta* nuevoN = NULL;

	if (_ppio == NULL) {
		ingresaDePrimero(venta);
	}
	else {
		while (PEx->getSigNodo() != NULL) {
			PEx = PEx->getSigNodo();
		}
		nuevoN = new NodoGenVenta(venta, NULL);
		PEx->setSigNodo(nuevoN);
	}
}

bool ContenedorLista::eliminarLugar(int lugar) {
	NodoGenVenta* pex = _ppio;
	NodoGenVenta* victima = nullptr;
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
	NodoGenVenta* pex = _ppio;
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