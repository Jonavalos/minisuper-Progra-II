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
				static void eliminarFact();
				static void actualizarFact();
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
				template<class T>
				static void modificarProducto(listaG<T>&);

		static int ventas();
			//ventas->
			static void crearFact();

		static int reporte();
			//reporte->
			template<class T>
			static void todosLosProd(listaG<T>&);
			template<class T>
			static void prodDeDeterminadaCat(listaG<T>&);
			template<class T>
			static void prodBajosExist(listaG<T>&);
			template<class T>
			static void factDeterminadoCliente(listaG<T>&);
			template<class T>
			static void mejoresClientes(listaG<T>&);

};

#endif // !INTERFAZ_H