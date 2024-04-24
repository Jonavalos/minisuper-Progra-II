#ifndef LISTAGENVENTA_H
#define LISTAGENVENTA_H
#include "nodoVenta.h"

class ContenedorLista {
private:
	NodoVenta* _ppio;
public:
	ContenedorLista();
	virtual ~ContenedorLista();
	void ingresaDePrimero(venta& venta);
	void ingresaDeUltimo(venta& venta);
	bool eliminarLugar(int);
	string cedulasTop5Clientes();
	void ordenar();
	bool intercambiarNodos(NodoVenta* n1, NodoVenta* n2);
	int cantidadNodos();
	venta* getVenta(int lugar);
	NodoVenta* getNodo(int lugar);
	string toString() const;
};


#endif // !LISTAGENVENTA_H