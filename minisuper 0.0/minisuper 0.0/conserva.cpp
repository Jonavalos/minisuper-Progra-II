#include "conserva.h"

conserva::conserva() 
	:producto(), _envasado(true){}

conserva::conserva(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, bool envasado)
	:producto(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite), _envasado(envasado){}

conserva::conserva(const conserva& obj)
	:producto(obj), _envasado(obj._envasado){}

conserva::~conserva()
{
}

string conserva::toString() const
{
	stringstream s;
	s << producto::toString();
	s << "Envasado: ";
	if (_envasado) {
		s << " si" << endl;
	}
	else {
		s << " no" << endl;
	}
	s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
	return s.str();
}

