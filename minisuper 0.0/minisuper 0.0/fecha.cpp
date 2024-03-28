#include "fecha.h"

fecha::fecha(): _dia(0), _mes(0), _anio(0){}

fecha::fecha(int dia, int mes, int anio):_dia(dia), _mes(mes), _anio(anio){}

fecha::fecha(const fecha& obj) :_dia(obj._dia), _mes(obj._mes), _anio(obj._anio) {}

fecha::~fecha()
{
}

string fecha::toString() const
{
	stringstream s; // " ( 1 / 2 / 3 ) "
	s << " ( " << _dia << " / " << _mes << " / " << _anio << " ) ";
	return s.str();
}
