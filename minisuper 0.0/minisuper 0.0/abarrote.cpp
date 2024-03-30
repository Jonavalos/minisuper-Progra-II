#include "abarrote.h"

abarrote::abarrote() : prodPerecedero(), _empresaNombre("") {
}

abarrote::abarrote(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string empresaNombre)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso), _empresaNombre(empresaNombre) {
}

abarrote::abarrote(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string empresaNombre)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaP, nacional, peso), _empresaNombre(empresaNombre) {
}

abarrote::abarrote(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, perecedero* perecederoPtr, bool nacional, double peso, string empresaNombre)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, perecederoPtr, nacional, peso), _empresaNombre(empresaNombre) {
}

abarrote::abarrote(const abarrote& obj) : prodPerecedero(obj), _empresaNombre(obj._empresaNombre) {
}

abarrote::~abarrote()
{
}

string abarrote::toString() const
{
	stringstream s;

	s << prodPerecedero::toString();
	s << "Nombre de la empresa: " << _empresaNombre << endl;
	s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

	return s.str();
}
