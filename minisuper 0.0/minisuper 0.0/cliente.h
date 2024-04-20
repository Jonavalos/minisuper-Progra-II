#ifndef CLIENTE_H
#define CLIENTE_H
#include "bibliotecas.h"

class cliente {
public:

	cliente(string);
	cliente(const cliente&);
	virtual ~cliente();
	string toString() const;
private:

	string _cedula;

};

#endif // !CLIENTE_H