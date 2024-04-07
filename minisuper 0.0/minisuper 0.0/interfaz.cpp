#include "interfaz.h"

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

void interfaz::eliminarFact() {
	//...
}

void interfaz::actualizarFact() {
	//...
}

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

void interfaz::tipoConserva() {
	//...
}

void interfaz::tipoAbarrote() {
	//...
}

void interfaz::tipoEmbutido() {
	//...
}

void interfaz::eliminarProducto() {
	//...
}

void interfaz::modificarProducto() {
	//...
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

void interfaz::todosLosProd() {

}

void interfaz::prodDeDeterminadaCat() {

}

void interfaz::prodBajosExist() {

}

void interfaz::factDeterminadoCliente() {

}

void interfaz::mejoresClientes() {

}
