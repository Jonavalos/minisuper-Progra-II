#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "bibliotecas.h"
#include "conserva.h"
#include "prodPerecedero.h"
#include "abarrote.h"
#include "embutido.h"
#include "listaG.h"

class interfaz {
public:
	
	static int menu();
	//menu->
		static int mantenimiento();
			//mantenimiento->
			static int mantFacturas();
				//facturas->
				/*static void eliminarFact();
				static void actualizarFact();*/
			static int mantProductos();
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

		static int ventas();
			//ventas->
			/*static void crearFact();*/

		static int reporte();
			//reporte->
			template<class T>
			static void todosLosProd(listaG<T>&);
			template<class T>
			static void prodDeDeterminadaCat(listaG<T>&);
			template<class T>
			static void prodBajosExist(listaG<T>&);
			/*template<class T>
			static void factDeterminadoCliente(listaG<T>&);
			template<class T>
			static void mejoresClientes(listaG<T>&);*/

};


//////////////////////////////////////////////////////////////


template<class T>
void interfaz::tipoConserva(listaG<T>& lista) {
	string codigo, nombreComercial, descripcion, categoria;
	double precioCosto;
	int existencia, limite, intEnvasado;
	bool envasado;

	cout << "Ingresar Producto Tipo Conserva" << endl << endl;
	cout << "Ingrese los siguientes datos: " << endl;
	cout << "Codigo: "; cin >> codigo;
	cout << "Nombre comercial: "; cin >> nombreComercial;
	cout << "Descripcion: "; cin >> descripcion;
	cout << "Precio costo: "; cin >> precioCosto;
	cout << "Categoria: "; cin >> categoria;
	cout << "Existencia: "; cin >> existencia;
	cout << "Limite: "; cin >> limite;
	cout << "Envasado: (1. Si, 0. No): "; cin >> intEnvasado; if (intEnvasado == 1) { envasado = true; }
	else { envasado = false; }

	producto* prod = new conserva(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, envasado);
	lista.ingresarUltimo(prod);
}

template<class T>
void interfaz::tipoAbarrote(listaG<T>& lista) {
	string codigo, nombreComercial, descripcion, categoria, empresaNombre;
	double precioCosto, peso;
	int existencia, limite, intNacional, dia, mes, anio;
	bool nacional;

	cout << "Ingresar Producto Tipo Abarrote" << endl << endl;
	cout << "Ingrese los siguientes datos: " << endl;
	cout << "Codigo: "; cin >> codigo;
	cout << "Nombre comercial: "; cin >> nombreComercial;
	cout << "Descripcion: "; cin >> descripcion;
	cout << "Precio costo: "; cin >> precioCosto;
	cout << "Categoria: "; cin >> categoria;
	cout << "Existencia: "; cin >> existencia;
	cout << "Limite: "; cin >> limite;
	cout << "Fecha(dia, mes, año): "; cin >> dia; cin >> mes; cin >> anio;
	cout << "Nacional: (1. Si, 0. No): "; cin >> intNacional; if (intNacional == 1) { nacional = true; }
	else { nacional = false; }
	cout << "Peso: "; cin >> peso;
	cout << "Nombre de la empresa: "; cin >> empresaNombre;


	producto* prod = new abarrote(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso, empresaNombre);
	lista.ingresarUltimo(prod);
}

template<class T>
void interfaz::tipoEmbutido(listaG<T>& lista) {
	string codigo, nombreComercial, descripcion, categoria, nombreAnimal, marca, parteDelAnimal;
	double precioCosto, peso;
	int existencia, limite, intNacional, dia, mes, anio, intTripa;
	bool nacional, tripa;

	cout << "Ingresar Producto Tipo Embutido" << endl << endl;
	cout << "Ingrese los siguientes datos: " << endl;
	cout << "Codigo: "; cin >> codigo;
	cout << "Nombre comercial: "; cin >> nombreComercial;
	cout << "Descripcion: "; cin >> descripcion;
	cout << "Precio costo: "; cin >> precioCosto;
	cout << "Categoria: "; cin >> categoria;
	cout << "Existencia: "; cin >> existencia;
	cout << "Limite: "; cin >> limite;
	cout << "Fecha(dia, mes, año): "; cin >> dia; cin >> mes; cin >> anio;
	cout << "Nacional: (1. Si, 0. No): "; cin >> intNacional; if (intNacional == 1) { nacional = true; }
	else { nacional = false; }
	cout << "Peso: "; cin >> peso;
	cout << "Nombre del animal: "; cin >> nombreAnimal;
	cout << "Parte del animal: "; cin >> parteDelAnimal;
	cout << "Tiene tripa: (1. Si, 0. No): "; cin >> intTripa; if (intTripa == 1) { tripa = true; }
	else { tripa = false; }
	cout << "Marca: "; cin >> marca;

	producto* prod = new embutido(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso, nombreAnimal, parteDelAnimal, tripa, marca);
	lista.ingresarUltimo(prod);
}

template<class T>
void interfaz::eliminarProducto(listaG<T>& lista) {
	int lugar = 0;

	cout << "Eliminar Producto" << endl;
	cout << lista;
	cout << "Ingrese el lugar del producto que desea eliminar: "; cin >> lugar;
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
	int opc, nuevaExist, lugar;
	double nuevoPrecio;

	cout << "Modificacion de Productos" << endl;
	cout << "1. Modificar precio costo" << endl;
	cout << "2. Modificar existencia" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpModProduct

	cout << "Ingrese el lugar que desea modificar: "; cin >> lugar;
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
	cout << *lista;
}

template<class T>
void interfaz::prodDeDeterminadaCat(listaG<T>& lista) {
	string cate;
	int lugar = 1;

	cout << "Reporte de Productos de Determinada Categoria" << endl;
	cout << "Digite la categoria que desea mostrar(01, 02, 03): "; cin >> cate;

	while (lugar <= lista.getCant() && lista.getNodoLugar(lugar) != nullptr) {
		if (lista.getObjLugar(lugar)->getCategoria() == cate) {
			cout << lista.getObjLugar(lugar)->toString();
		}
		//else {
			lugar++;
		//}
	}
}

template<class T>
void interfaz::prodBajosExist(listaG<T>& lista) {
	cout << "Reporte de Productos Bajos en Existencia" << endl;

	cout << lista.reportarBajosExistencia();
}


#endif // !INTERFAZ_H