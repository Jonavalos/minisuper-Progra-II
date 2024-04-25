#include "interfaz.h"
#include "bibliotecas.h"
#include "conserva.h"
#include "prodPerecedero.h"
#include "abarrote.h"
#include "embutido.h"
#include "listaG.h"
#include "excepciones.h"

int interfaz::menu() {
	int op;

	cout << "Menu de Opciones" << endl;
	cout << "1. Mantenimiento" << endl;
	cout << "2. Ventas" << endl;
	cout << "3. Reporte" << endl;
	cout << "4. SALIR" << endl;
	try {
		cout << "Ingrese una opcion: "; cin >> op; //excp
		if (op < 1 && op>4) {
			throw excepcionRango();
		}
	}
	catch (excepcionRango& ex) {
		cerr << ex.what();
	}

	return op;
}

int interfaz::mantenimiento() {
	int opc;

	cout << "Menu de Ventas" << endl;
	cout << "1. Ingreso productos" << endl;
	cout << "2. Eliminar productos" << endl;
	cout << "3. Modificar productos" << endl;
	cout << "4. Retornar" << endl;
	try {
		cout << "Ingrese una opcion: "; cin >> opc; //excpMantProd
		if (opc < 1 && opc > 4) {
			throw excepcionRango();
		}
	}
	catch (excepcionRango& ex) {
		cerr << ex.what();
	}

	return opc;
}

int interfaz::ingresarProducto() {
	int opc;

	cout << "Menu de Ventas" << endl;
	cout << "1. Tipo conserva" << endl;
	cout << "2. Tipo abarrote" << endl;
	cout << "3. Tipo embutido" << endl;
	cout << "4. Retornar" << endl;
	try {
		cout << "Ingrese una opcion: "; cin >> opc; //excpIngresar
		if (opc < 1 && opc > 4) {
			throw excepcionRango();
		}
	}
	catch (excepcionRango& ex) {
		cerr << ex.what();
	}

	return opc;
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
	try {
		cout << "Ingrese una opcion: "; cin >> opc; //excpReporte
		if (opc < 1 && opc > 6) {
			throw excepcionRango();
		}
	}
	catch (excepcionRango& ex) {
		cerr << ex.what();
	}

	return opc;
}

void interfaz::factDeterminadoCliente(ContenedorLista& listaVenta) {
	string cedula;

	cout << "Reporte de Clientes por su Cedula" << endl;
	try {
		cout << "Digite la cedula del cliente: "; cin >> cedula;
		if (caracteresValidos(cedula)) {
			throw excepcionCaracteres();
		}
	}
	catch (excepcionCaracteres& ex) {
		cerr << ex.what();
	}

	listaVenta.reportarFacturasPorCliente(cedula);
}

void interfaz::mejoresClientes(ContenedorLista& listaVenta) {
	cout << "Lista de los 5 Mejores Clientes" << endl << endl;

	cout << listaVenta.top5();
}

bool interfaz::caracteresValidos(string s) {
	regex e("^([A-Za-z_])*$");
	return regex_match(s, e);
}