#ifndef LISTAGENVENTA_H
#define LISTAGENVENTA_H
#include "nodoVenta.h"

class ContenedorLista {
private:
	NodoVenta* _ppio;

	struct ventaCliente
	{
		string _id;
		double _total;
		ventaCliente();
		ventaCliente(string id, double total);
		
	};

	struct vecVentaCliente {

		int can = 0;
		ventaCliente* vec[50];
		
		bool existe(string id);

		bool ingresar(ventaCliente* obj);

		string toString();

		void ordenar();

	};
	


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
	void reportarFacturasPorCliente(string);
	string toString() const;

	bool existe(string id);
	double sumaTotalCliente(string id);
	string top5();
};


#endif // !LISTAGENVENTA_H