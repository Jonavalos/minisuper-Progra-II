#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include "interfaz.h"

class controladora {
public:

	controladora();
	template<class T>
	controladora(listaG<T>&);
	virtual ~controladora();

	int controlMenu();

	void control0();
	void control1();

private:

	listaG<producto>* lista;

};

template<class T>
inline controladora::controladora(listaG<T>& nuevaLista) {
	lista = nuevaLista;
}

#endif // !CONTROLADORA_H