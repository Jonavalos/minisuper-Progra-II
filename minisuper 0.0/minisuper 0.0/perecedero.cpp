#include "perecedero.h"

perecedero::perecedero()
{
	_fechaCaducidad = new fecha();
}

perecedero::perecedero(fecha* fechaCaducidad)
{
	_fechaCaducidad = new fecha(*fechaCaducidad);
}

perecedero::perecedero(const fecha& obj)
{
	_fechaCaducidad = new fecha(obj);
}

perecedero::~perecedero()
{
	delete _fechaCaducidad;
}

fecha* perecedero::getFechaCaducidad() const
{
	return _fechaCaducidad;
}

string perecedero::FechaCaducidadToString() const
{
	return _fechaCaducidad->toString();
}
