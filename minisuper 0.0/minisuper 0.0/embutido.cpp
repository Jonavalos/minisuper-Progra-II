#include "embutido.h"

embutido::embutido() : _marca(""), _nombreAnimal(""), _parteDelAnimal(""), _tripa(true) {
}

embutido::embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso), _marca(marca), _nombreAnimal(nombreAnimal), _parteDelAnimal(parteDelAnimal), _tripa(tripa) {
}

embutido::embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca)
	: prodPerecedero(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaP, nacional, peso), _marca(marca), _nombreAnimal(nombreAnimal), _parteDelAnimal(parteDelAnimal), _tripa(tripa) {
}

embutido::embutido(const embutido& obj) : prodPerecedero(obj), _marca(obj._marca), _nombreAnimal(obj._nombreAnimal), _parteDelAnimal(obj._parteDelAnimal), _tripa(obj._tripa) {

}

embutido::~embutido() {}

string embutido::toString() const
{
	stringstream s;

	s << prodPerecedero::toString();
	s << "Marca: " << _marca << endl;
	s << "Nombre del animal: " << _nombreAnimal << endl;
	s << "Parte del animal: " << _parteDelAnimal << endl;
	s << "Tripa: ";
	if (_tripa) {
		s << "si" << endl;
	}
	else {
		s << "no" << endl;
	}
	s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

	return s.str();
}
