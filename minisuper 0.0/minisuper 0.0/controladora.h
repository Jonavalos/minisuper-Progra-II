#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include "interfaz.h"

class controladora {
public:
	//inhabilitar constructores de copia buscar ejemplo con deletes, no se ocuparia crear mas de una controladora
	controladora();
	//template<class T>
	controladora(listaG<producto>*);
	virtual ~controladora();

	int controlMenu();

	void control0();
	void control1();

private:

	listaG<producto>* lista;

};

//template<class producto> //borrar para la version final
inline controladora::controladora(listaG<producto>* nuevaLista) {
	lista = nuevaLista;
}

#endif // !CONTROLADORA_H