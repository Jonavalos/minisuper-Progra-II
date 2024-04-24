#include "controladora.h"

controladora::controladora() {
	lista = new listaG<producto>;
}
controladora::~controladora() {
	if (lista != nullptr) {
		delete lista;
	}
}

int controladora::controlMenu() {
	return interfaz::menu();
}

void controladora::control0() {
	int op, op1, op2, op3;

	do {
		op = controlMenu();
		switch (op) {
		case 1: 
			do {
				op1 = control1(); 

				switch (op1) {
				case 1: 
					do {
						op2 = control1_1();

						switch (op2) {
						case 1: control1_1_1(); break;
						case 2: control1_1_2(); break;
						case 3: control1_1_3(); break;
						default: break;
						}

					} while (op2 != 4);
					break;
				case 2: control1_2(); break;
				case 3: control1_3(); break;
				default: break;
				}
			} while (op1 != 4);
			break;
		case 2: control2(); break;
		case 3: 
			do {
				op3 = control3();
				switch (op3) {
				case 1: control3_1(); break;
				case 2: control3_2(); break;
				case 3: control3_3(); break;
				case 4: control3_4(); break;
				case 5: control3_5(); break;
				default: break;
				}
				break;
			} while (op3 != 6);
		default: break;
		};
	} while (op != 4);
}

int controladora::control1() {
	return interfaz::mantenimiento();
}

void controladora::control2() {
	interfaz::crearFact(*lista, listaVentas);
}

int controladora::control3() {
	return interfaz::reporte();
}

void controladora::control3_1() {
	interfaz::todosLosProd(*lista);
}

void controladora::control3_2() {
	interfaz::prodDeDeterminadaCat(*lista);
}

void controladora::control3_3() {
	interfaz::prodBajosExist(*lista);
}

void controladora::control3_4() {
	interfaz::factDeterminadoCliente(*lista);
}

void controladora::control3_5() {
	interfaz::mejoresClientes(*lista);
}

void controladora::control1_1_1() {
	interfaz::tipoConserva(*lista);
}

void controladora::control1_1_2() {
	interfaz::tipoAbarrote(*lista);
}

void controladora::control1_1_3() {
	interfaz::tipoEmbutido(*lista);
}

int controladora::control1_1() {
	return interfaz::ingresarProducto();
}

void controladora::control1_2() {
	interfaz::eliminarProducto(*lista);
}

void controladora::control1_3() {
	interfaz::modificarProducto(*lista);
}