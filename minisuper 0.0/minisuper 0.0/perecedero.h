#ifndef PERECEDERO_H
#define PERECEDERO_H
#include "fecha.h"
class perecedero //preguntar acerca de los atributos (no tiene segun el DRC)
{
public:
	perecedero();
	perecedero(int dia, int mes, int anio);
	perecedero(fecha* fechaCaducidad);
	perecedero(const perecedero& obj);
	~perecedero();
	fecha* getFechaCaducidad() const;
	string fechaCaducidadToString() const;

private:
	fecha* _fechaCaducidad;

};


#endif // !PERECEDERO_H


