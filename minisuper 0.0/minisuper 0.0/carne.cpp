#include "carne.h"

carne::carne() : prodPerecedero(), _nombreAnimal(""), _parteDelAnimal("") {
}

carne::carne(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string nombreAnimal, string parteDelAnimal)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso), _nombreAnimal(nombreAnimal), _parteDelAnimal(parteDelAnimal) {
}

carne::carne(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string nombreAnimal, string parteDelAnimal)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaP, nacional, peso), _nombreAnimal(nombreAnimal), _parteDelAnimal(parteDelAnimal) {
}

carne::carne(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, perecedero* perecederoPtr, bool nacional, double peso, string nombreAnimal, string parteDelAnimal)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, perecederoPtr, nacional, peso), _nombreAnimal(nombreAnimal), _parteDelAnimal(parteDelAnimal) {
}

carne::carne(const carne& obj) : prodPerecedero(obj), _nombreAnimal(obj._nombreAnimal), _parteDelAnimal(obj._parteDelAnimal) {
}

carne::~carne()
{
}

string carne::toString() const
{
	stringstream s;

	s << prodPerecedero::toString();
	s << "Animal: " << _nombreAnimal << endl;
	s << "Parte del animal: " << _parteDelAnimal << endl;

	return s.str();
}
