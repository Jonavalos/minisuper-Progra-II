#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H
#include "bibliotecas.h"

class excepcion : public exception {
public:

	const char* what() const = 0;

};

class excepcionCategoria : public excepcion {
public:
	const char* what() const;
};

class excepcionFecha : public excepcion {
public:
	const char* what() const;
};

class excepcionRango : public excepcion {
public:
	const char* what() const;
};

class excepcionCantidad : public excepcion {
public:
	const char* what() const;
};

#endif // !EXCEPCIONES_H