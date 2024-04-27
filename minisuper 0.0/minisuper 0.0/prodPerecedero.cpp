#include "prodPerecedero.h"

prodPerecedero::prodPerecedero() :producto(), _nacional(true), _peso(0.0) {
	_fechaPtr = new fecha();
}

prodPerecedero::~prodPerecedero(){
	if (_fechaPtr != nullptr) {
		delete _fechaPtr;
	}
}

prodPerecedero::prodPerecedero(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso)
	:producto(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite), _nacional(nacional), _peso(peso) {
	_fechaPtr = new fecha(dia, mes, anio);
}

prodPerecedero::prodPerecedero(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso)
	:producto(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite), _nacional(nacional), _peso(peso) {
	_fechaPtr = new fecha(*fechaP);
}


prodPerecedero::prodPerecedero(const prodPerecedero& obj)
	:producto(obj), _nacional(obj._nacional), _peso(obj._peso) {
	_fechaPtr = new fecha(*obj._fechaPtr);
}


string prodPerecedero::toString() const
{
	stringstream s;

	s << producto::toString();
	s << "Nacional: ";
	if (_nacional) {
		s << " si" << endl;
	}
	else {
		s << " no" << endl;
	}
	
	s << "Peso: " << _peso << endl;
	s << "Fecha caducidad:" << _fechaPtr->toString() << endl;
	//s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

	return s.str();
}
