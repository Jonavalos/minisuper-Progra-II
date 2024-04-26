#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "bibliotecas.h"
#include "conserva.h"
#include "prodPerecedero.h"
#include "abarrote.h"
#include "embutido.h"
#include "listaG.h"
#include "decoradorProducto.h"
#include "carrito.h"
#include "cliente.h"
#include "venta.h"
#include "contenedorLista.h"
#include "excepciones.h"

class interfaz {
public:
	
	static int menu();
	//menu->
		static int mantenimiento();
				//productos->
				static int ingresarProducto();
					//ingreso->
					template<class T>
					static void tipoConserva(listaG<T>&);
					template<class T>
					static void tipoAbarrote(listaG<T>&);
					template<class T>
					static void tipoEmbutido(listaG<T>&);
				template<class T>
				static void eliminarProducto(listaG<T>&);
				template<class producto>
				static void modificarProducto(listaG<producto>&);

		/*ventas->*/
		template<class T>
		static void crearFact(listaG<T>& lista, ContenedorLista* listaVenta);

		static int reporte();
			//reporte->
			template<class T>
			static void todosLosProd(listaG<T>&);
			template<class T>
			static void prodDeDeterminadaCat(listaG<T>&);
			template<class T>
			static void prodBajosExist(listaG<T>&);
			static void factDeterminadoCliente(ContenedorLista&);
			static void mejoresClientes(ContenedorLista&);


	static bool caracteresValidos(string s);
	static int ingresarCantidad(compraProducto*);
};


//////////////////////////////////////////////////////////////


template<class T>
void interfaz::tipoConserva(listaG<T>& lista) {
	string codigo, nombreComercial, descripcion, categoria;
	double precioCosto;
	int existencia, limite, intEnvasado;
	bool envasado;

	do {
		cout << "Ingresar Producto Tipo Conserva" << endl << endl;
		cout << "Ingrese los siguientes datos: " << endl;
		cout << "Codigo: "; cin >> codigo;
		cout << "Nombre comercial: "; cin >> nombreComercial;
		cout << "Descripcion: "; cin >> descripcion;
		cout << "Precio costo: "; cin >> precioCosto;
		cout << "Existencia: "; cin >> existencia;
		cout << "Limite: "; cin >> limite;
		try {
			cout << "Categoria: "; cin >> categoria;
			if ((categoria != "01") && (categoria != "02") && (categoria != "03")) {
				throw excepcionCategoria();
			}
			cout << "Envasado: (1. Si, 0. No): "; cin >> intEnvasado;
			if (intEnvasado == 1) {
				envasado = true;
			}
			else if (intEnvasado == 0) {
				envasado = false;
			}
			else {
				throw excepcionRango();
			}
		}
		catch (excepcionCategoria& ex) {
			cerr << ex.what();
		}
		catch (excepcionRango& ex) {
			cerr << ex.what();
		}
	} while ((categoria != "01" && categoria != "02" && categoria != "03") || (intEnvasado != 0 && intEnvasado != 1));

	producto* prod = new conserva(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, envasado);
	lista.ingresarUltimo(*prod);
}

template<class T>
void interfaz::tipoAbarrote(listaG<T>& lista) {
	string codigo, nombreComercial, descripcion, categoria, empresaNombre;
	double precioCosto, peso;
	int existencia, limite, intNacional, dia, mes, anio;
	bool nacional;

	do {
		cout << "Ingresar Producto Tipo Abarrote" << endl << endl;
		cout << "Ingrese los siguientes datos: " << endl;
		cout << "Codigo: "; cin >> codigo;
		cout << "Nombre comercial: "; cin >> nombreComercial;
		cout << "Descripcion: "; cin >> descripcion;
		cout << "Precio costo: "; cin >> precioCosto;
		cout << "Existencia: "; cin >> existencia;
		cout << "Limite: "; cin >> limite;
		cout << "Peso: "; cin >> peso;
		cout << "Nombre de la empresa: "; cin >> empresaNombre;
		try {
			cout << "Categoria: "; cin >> categoria;
			if ((categoria != "01") && (categoria != "02") && (categoria != "03")) {
				throw excepcionCategoria();
			}
			cout << "Fecha(dia, mes, año): "; cin >> dia; cin >> mes; cin >> anio;
			if (dia > 31 || mes > 12) {
				throw excepcionFecha();
			}
			cout << "Nacional: (1. Si, 0. No): "; cin >> intNacional;
			if (intNacional == 1) {
				nacional = true;
			}
			else if (intNacional == 0) {
				nacional = false;
			}
			else {
				throw excepcionRango();
			}
		}
		catch (excepcionCategoria& ex) {
			cerr << ex.what();
		}
		catch (excepcionRango& ex) {
			cerr << ex.what();
		}
		catch (excepcionFecha& ex) {
			cerr << ex.what();
		}
	} while ((categoria != "01" && categoria != "02" && categoria != "03") || (dia > 31 || mes > 12) || (intNacional != 0 && intNacional != 1));

	producto* prod = new abarrote(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso, empresaNombre);
	lista.ingresarUltimo(*prod);
}

template<class T>
void interfaz::tipoEmbutido(listaG<T>& lista) {
	string codigo, nombreComercial, descripcion, categoria, nombreAnimal, marca, parteDelAnimal;
	double precioCosto, peso;
	int existencia, limite, intNacional, dia, mes, anio, intTripa;
	bool nacional, tripa;

	do {
		cout << "Ingresar Producto Tipo Embutido" << endl << endl;
		cout << "Ingrese los siguientes datos: " << endl;
		cout << "Codigo: "; cin >> codigo;
		cout << "Nombre comercial: "; cin >> nombreComercial;
		cout << "Descripcion: "; cin >> descripcion;
		cout << "Precio costo: "; cin >> precioCosto;
		cout << "Existencia: "; cin >> existencia;
		cout << "Limite: "; cin >> limite;
		cout << "Peso: "; cin >> peso;
		cout << "Nombre del animal: "; cin >> nombreAnimal;
		cout << "Parte del animal: "; cin >> parteDelAnimal;
		cout << "Marca: "; cin >> marca;
		try {
			cout << "Categoria: "; cin >> categoria;
			if ((categoria != "01") && (categoria != "02") && (categoria != "03")) {
				throw excepcionCategoria();
			}
			cout << "Fecha(dia, mes, año): "; cin >> dia; cin >> mes; cin >> anio;
			if (dia > 31 || mes > 12) {
				throw excepcionFecha();
			}
			cout << "Nacional: (1. Si, 0. No): "; cin >> intNacional;
			if (intNacional == 1) {
				nacional = true;
			}
			else if (intNacional == 0) {
				nacional = false;
			}
			else {
				throw excepcionRango();
			}
			cout << "Tiene tripa: (1. Si, 0. No): "; cin >> intTripa;
			if (intTripa == 1) {
				tripa = true;
			}
			else if (intNacional == 0) {
				tripa = false;
			}
			else {
				throw excepcionRango();
			}
		}
		catch (excepcionCategoria& ex) {
			cerr << ex.what();
		}
		catch (excepcionRango& ex) {
			cerr << ex.what();
		}
		catch (excepcionFecha& ex) {
			cerr << ex.what();
		}
	} while ((categoria != "01" && categoria != "02" && categoria != "03") || (dia > 31 || mes > 12) || (intNacional != 0 && intNacional != 1) || (intTripa != 0 && intTripa != 1));

	producto* prod = new embutido(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso, nombreAnimal, parteDelAnimal, tripa, marca);
	lista.ingresarUltimo(*prod);
}

template<class T>
void interfaz::eliminarProducto(listaG<T>& lista) {
	int lugar = 0;

	cout << "Eliminar Producto" << endl;
	cout << lista;
	do {
		try {
			cout << "Ingrese el lugar del producto que desea eliminar: "; cin >> lugar;
			if (lugar > lista.getCant()) {
				throw excepcionRango();
			}
		}
		catch (excepcionRango& ex) {
			cerr << ex.what();
		}
	} while (lugar > lista.getCant());
	if (lista.eliminarLugar(lugar)) {
		cout << "Eliminado con exito. " << endl << endl;
		cout << lista;
	}
	else {
		cout << "Hubo un error al elimiar el producto. " << endl;
	}
}

template<class T>
void interfaz::modificarProducto(listaG<T>& lista) {
	int opc=0, nuevaExist=0, lugar = 0;;
	double nuevoPrecio;

	cout << "Modificacion de Productos" << endl;
	cout << "1. Modificar precio costo" << endl;
	cout << "2. Modificar existencia" << endl;
	do {
		try {
			cout << "Ingrese la opcion: "; cin >> opc;
			if (lugar > lista.getCant()) {
				throw excepcionRango();
			}
		}
		catch (excepcionRango& ex) {
			cerr << ex.what();
		}
	} while (opc > 2);

	do {
		try {
			cout << "Ingrese el lugar del producto que desea modificar: "; cin >> lugar;
			if (lugar > lista.getCant()) {
				throw excepcionRango();
			}
		}
		catch (excepcionRango& ex) {
			cerr << ex.what();
		}
	} while (lugar > lista.getCant());
	if (opc == 1) {
		cout << "Ingrese el nuevo precio costo: "; cin >> nuevoPrecio;
		(lista.getObjLugar(lugar))->setPrecioCosto(nuevoPrecio);
	}
	else {
		cout << "Ingrese la nueva existencia: "; cin >> nuevaExist;
		(lista.getObjLugar(lugar))->setExistencia(nuevaExist);
	}
}

template<class T>
void interfaz::todosLosProd(listaG<T>& lista) {
	cout << lista.toString();
}

template<class T>
void interfaz::prodDeDeterminadaCat(listaG<T>& lista) {
	string cate;
	int lugar = 1;

	cout << "Reporte de Productos de Determinada Categoria" << endl;
	do {
		try {
			cout << "Digite la categoria que desea mostrar(01, 02, 03): "; cin >> cate;
			if (lugar > lista.getCant()) {
				throw excepcionRango();
			}
		}
		catch (excepcionCategoria& ex) {
			cerr << ex.what();
		}
	} while (cate != "01" && cate != "02" && cate != "03");

	while (lugar <= lista.getCant() && lista.getNodoLugar(lugar) != nullptr) {
		if (lista.getObjLugar(lugar)->getCategoria() == cate) {
			cout << lista.getObjLugar(lugar)->toString();
		}
		lugar++;
	}
}

template<class T>
void interfaz::prodBajosExist(listaG<T>& lista) {
	int lugar = 1;

	cout << "Reporte de Productos Bajos en Existencia" << endl;

	while (lugar <= lista.getCant() && lista.getNodoLugar(lugar) != nullptr) {
		if (lista.getObjLugar(lugar)->getExistencia() <= 1) {
			cout << lista.getObjLugar(lugar)->toString();
		}
		lugar++;
	}
}

template<class T>
void interfaz::crearFact(listaG<T>& lista, ContenedorLista* listaVentas) {
	compraProducto* carrito1 = new carrito;

	string cedula;
	int lugar, cant;
	double total = 0, iva = 0;

	cout << "Ventas" << endl;
	cout << "Ingrese su cedula: "; cin >> cedula;
	cliente* cliente1 = new cliente(cedula);

	compraProducto* prod = nullptr;
	do {
		cout << lista.toString() << endl;
		do {
			try {
				cout << "Digite el lugar del producto que desea comprar (0 para salir): "; cin >> lugar;
				if (lugar > lista.getCant() || lugar<0) {
					throw excepcionRango();
				}
			}
			catch (excepcionRango& ex) {
				cerr << ex.what() << endl;
			}
		} while (lugar > lista.getCant() || lugar < 0);
		if (lugar != 0) {
			if (prod == nullptr) {
				prod = new decoradorProducto(carrito1, lista.getObjLugar(lugar));
				cant = ingresarCantidad(prod);
				total += ((cant * lista.getObjLugar(lugar)->getPrecioCosto()) * 1.13 * prod->getCategoria());
				iva += ((cant * lista.getObjLugar(lugar)->getPrecioCosto()) * 0.13);
				prod->setExistencia(cant);
			}
			else {
				prod = new decoradorProducto(prod, lista.getObjLugar(lugar));
				cant = ingresarCantidad(prod);
				total += ((cant * lista.getObjLugar(lugar)->getPrecioCosto()) * 1.13 * prod->getCategoria());
				iva += ((cant * lista.getObjLugar(lugar)->getPrecioCosto()) * 0.13);
				prod->setExistencia(cant);
			}
		}
	} while (lugar != 0);

	venta* venta1 = new venta(cliente1, prod, total, iva);

	cout << venta1->toString();

	listaVentas->ingresaDeUltimo(*venta1);
}

#endif // !INTERFAZ_H