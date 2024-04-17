#include "controladora.h"

controladora::controladora() {
	lista = new listaG<producto>;
}
controladora::~controladora() {
	if (lista != NULL) {
		delete lista;
	}
}

int controladora::controlMenu() {
	return interfaz::menu();
}

void controladora::control0() {
	int op;

	do {
		op = controlMenu();
		switch (op) {
		case 1: control1(); break;
		default: break;
		};
		system("pause");
	} while (op != 8);
}

void controladora::control1() {
	interfaz::prodDeDeterminadaCat(*lista);
}

