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
		ventaCliente() : _id(""), _total(0.0) {}
		ventaCliente(string id, double total) : _id(id), _total(total){}
		
	};

	struct vecVentaCliente {

		int can = 0;
		ventaCliente* vec[50];
		
		bool existe(string id) {
			for (int i = 0;i < can;i++) {
				if (vec[i]->_id == id)
					return true;
			}
			return false;
		}

		bool ingresar(ventaCliente* obj) {
			if (can < 50) {
				if (!existe(obj->_id)) {
					vec[can++] = obj;
					return true;
				}		
			}
			return false;
		}

		string toString() {
			stringstream s;
			for (int i = 0;i < 5;i++) {
				s<<i+1<<" - " << vec[i]->_id << endl;
			}
			return s.str();
		}

		void ordenar() {

			for (int i = 0;i < can;i++) {
				for (int j = i + 1; j < can;j++) {
					if (vec[i]->_total <= vec[j]->_total) {
						ventaCliente* aux = vec[i];
						vec[i] = vec[j];
						vec[j] = aux;
					}
				}
			}

		}

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