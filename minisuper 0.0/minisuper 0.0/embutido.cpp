#include "embutido.h"

embutido::embutido() : carne(), _marca("") {
	_empaquePtr = new empaque();
}

embutido::embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca)
	: carne(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, dia, mes, anio, nacional, peso, nombreAnimal, parteDelAnimal), _marca(marca) {
	_empaquePtr = new empaque(tripa);
}

embutido::embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca)
	: carne(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaP, nacional, peso, nombreAnimal, parteDelAnimal), _marca(marca) {
	_empaquePtr = new empaque(tripa);
}

embutido::embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, perecedero* perecederoPtr, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca)
	: carne(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, perecederoPtr, nacional, peso, nombreAnimal, parteDelAnimal), _marca(marca) {
	_empaquePtr = new empaque(tripa);
}

embutido::embutido(const embutido& obj) : carne(obj), _marca(obj._marca) {
	_empaquePtr = new empaque(*obj._empaquePtr);
}

embutido::~embutido() {
	delete _empaquePtr;
}

string embutido::getNombre() {
	return _nombreComercial;
}

string embutido::toString() const
{
	stringstream s;

	s << carne::toString();
	s << "Marca: " << _marca << endl;
	s << "Empaque: " << _empaquePtr->toString() << endl;
	s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

	return s.str();
}
