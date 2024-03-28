#ifndef PERECEDERO_H
#define PERECEDERO_H
#include "fecha.h"
class perecedero //preguntar acerca de los atributos (no tiene segun el DRC)
{
public:
	perecedero();
	perecedero(fecha* fechaCaducidad);
	perecedero(const fecha& obj);
	~perecedero();
	fecha* getFechaCaducidad() const;
	string FechaCaducidadToString() const;

private:
	fecha* _fechaCaducidad;

};


#endif // !PERECEDERO_H


