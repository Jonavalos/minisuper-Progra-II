#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include "interfaz.h"

class controladora {
public:
	//inhabilitar constructores de copia buscar ejemplo con deletes, no se ocuparia crear mas de una controladora
	controladora();
	//template<class T>
	controladora(listaG<producto>*, ContenedorLista*);
	virtual ~controladora();

	int controlMenu();

	void control0();
	int control1();
		int control1_1();
			void control1_1_1();
			void control1_1_2();
			void control1_1_3();
		void control1_2();
		void control1_3();
	void control2();
	int control3();
		void control3_1();
		void control3_2();
		void control3_3();
		void control3_4();
		void control3_5();
	

private:

	listaG<producto>* lista;
	ContenedorLista* listaVentas;

};

//template<class producto> //borrar para la version final
inline controladora::controladora(listaG<producto>* nuevaLista, ContenedorLista* nuevaListaVentas) {
	lista = nuevaLista;
	listaVentas = nuevaListaVentas;
}

#endif // !CONTROLADORA_H