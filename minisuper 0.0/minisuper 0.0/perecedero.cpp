#include "perecedero.h"

perecedero::perecedero()
{
	_fechaCaducidad = new fecha();
}

perecedero::~perecedero()
{
	if (_fechaCaducidad != nullptr) {
		delete _fechaCaducidad;
	}
}

perecedero::perecedero(int dia, int mes, int anio)
{
	_fechaCaducidad = new fecha(dia, mes, anio);
}

perecedero::perecedero(fecha* fechaCaducidad)
{
	_fechaCaducidad = new fecha(*fechaCaducidad);
}

perecedero::perecedero(const perecedero& obj)
{
	_fechaCaducidad = new fecha(*obj._fechaCaducidad);
}

fecha* perecedero::getFechaCaducidad() const
{
	return _fechaCaducidad;
}

string perecedero::fechaCaducidadToString() const
{
	return _fechaCaducidad->toString();
}
