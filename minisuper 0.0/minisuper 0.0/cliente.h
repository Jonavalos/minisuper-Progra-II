#ifndef CLIENTE_H
#define CLIENTE_H
#include "bibliotecas.h"

class cliente {
public:

	cliente(string);
	cliente(const cliente&);
	virtual ~cliente();

private:

	string _cedula;

};

#endif // !CLIENTE_H