#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
using namespace std;

class interfaz {
public:

	static int menu();
	//menu->
		static int mantenimiento();
			//mantenimiento->
			static int mantFacturas();
				//facturas->
				static void eliminarFact();
				static void actualizarFact();
			static int mantProductos();
				//productos->
				static int ingresarProducto();
					//ingreso->
					static void tipoConserva();
					static void tipoAbarrote();
					static void tipoEmbutido();
				static void eliminarProducto();
				static void modificarProducto();

		static int ventas();
			//ventas->
			static void crearFact();

		static int reporte();
			//reporte->
			static void todosLosProd();
			static void prodDeDeterminadaCat();
			static void prodBajosExist();
			static void factDeterminadoCliente();
			static void mejoresClientes();

};

#endif // !INTERFAZ_H