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

class excepcionLimite : public excepcion {
public:
	const char* what() const;
};

class excepcionExistencia : public excepcion {
public:
	const char* what() const;
};

class excepcionRango : public excepcion {
public:
	const char* what() const;
};

class excepcionCaracteres : public excepcion {
public:
	const char* what() const;
};

#endif // !EXCEPCIONES_H