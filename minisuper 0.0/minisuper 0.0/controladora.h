#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include "interfaz.h"

class controladora {
public:

	controladora();
	virtual ~controladora();

	int controlMenu();

	void control0();
	void control1();

private:

	listaG<producto>* lista;

};

#endif // !CONTROLADORA_H