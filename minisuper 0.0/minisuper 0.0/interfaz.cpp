#include "interfaz.h"
#include "bibliotecas.h"
#include "conserva.h"
#include "prodPerecedero.h"
#include "abarrote.h"
#include "embutido.h"
#include "listaG.h"

int interfaz::menu() {
	int op;

	cout << "Menu de Opciones" << endl;
	cout << "1. Mantenimiento" << endl;
	cout << "2. Ventas" << endl;
	cout << "3. Reporte" << endl;
	cout << "4. SALIR" << endl;
	cout << "Ingrese una opcion: "; cin >> op; //excp

	return op;
}

int interfaz::mantenimiento() {
	int opc;

	cout << "Menu de Mantenimiento" << endl;
	cout << "1. Facturas" << endl;
	cout << "2. Productos" << endl;
	cout << "3. Retornar" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpMant

	return opc;
}

int interfaz::mantFacturas() {
	int opc;

	cout << "Menu de Facturas" << endl;
	cout << "1. Eliminar factura" << endl;
	cout << "2. Actualizar factura" << endl;
	cout << "3. Retornar" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpMantFact

	return opc;
}

//void interfaz::eliminarFact() {
//	//...
//}
//
//void interfaz::actualizarFact() {
//	//...
//}

int interfaz::mantProductos() {
	int opc;

	cout << "Menu de Ventas" << endl;
	cout << "1. Ingreso productos" << endl;
	cout << "2. Eliminar productos" << endl;
	cout << "3. Modificar productos" << endl;
	cout << "4. Retornar" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpMantProd

	return opc;
}

int interfaz::ingresarProducto() {
	int opc;

	cout << "Menu de Ventas" << endl;
	cout << "1. Tipo conserva" << endl;
	cout << "2. Tipo abarrote" << endl;
	cout << "3. Tipo embutido" << endl;
	cout << "4. Retornar" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpIngresar

	return opc;
}

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
	cout << "Envasado: (1. Si, 0. No): "; cin >> intEnvasado; if (intEnvasado == 1) { envasado = true; } else { envasado = false; }

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

template<class producto>
void interfaz::modificarProducto(listaG<producto>& lista) {
	int opc, nuevaExist, lugar;
	double nuevoPrecio;

	cout << "Modificacion de Productos" << endl;
	cout << "1. Modificar precio costo" << endl;
	cout << "2. Modificar existencia" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpModProduct

	cout << "Ingrese el lugar que desea modificar: "; cin >> lugar;
	if (opc == 1) {
		cout << "Ingrese el nuevo precio costo: "; cin >> nuevoPrecio;
		(lista.getObjLugar(lugar)).setPrecioCosto(nuevoPrecio);
	}
	else {
		cout << "Ingrese la nueva existencia: "; cin >> nuevaExist;
		(lista.getObjLugar(lugar)).setExistencia(nuevoPrecio);
	}
}

int interfaz::ventas() {
	int opc;

	cout << "Menu de Ventas" << endl;
	cout << "1. Crear nactura nueva" << endl;
	cout << "2. Retornar" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpVentas

	return opc;
}

void interfaz::crearFact() {
	cout << "Crear facturas" << endl;
	//...
}

int interfaz::reporte() {
	int opc;

	cout << "Menu de Reporte" << endl;
	cout << "1. Todos los productos" << endl;
	cout << "2. Productos de una determinada categoria" << endl;
	cout << "3. Productos por debajo del minimo de existencia" << endl;
	cout << "4. Facturas de un determinado cliente por su cedula" << endl;
	cout << "5. Cedulas de los 5 mejores clientes" << endl;
	cout << "6. Retornar" << endl;
	cout << "Ingrese una opcion: "; cin >> opc; //excpReporte

	return opc;
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
		if (lista.getObjLugar(lugar).getCategoria() == cate) {
			cout << lista.getObjLugar(lugar).toString();
		}
		else {
			lugar++;
		}
	}
}

template<class T>
void interfaz::prodBajosExist(listaG<T>& lista) {
	cout << "Reporte de Productos Bajos en Existencia" << endl;

	cout << lista.reportarBajosExistencia();
}

//template<class T>
//void interfaz::factDeterminadoCliente(listaG<T>& lista) {
//
//}
//
//template<class T>
//void interfaz::mejoresClientes(listaG<T>& lista) {
//
//}
