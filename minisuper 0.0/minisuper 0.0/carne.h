#ifndef CARNE_H
#define CARNE_H
#include "prodPerecedero.h"

class carne : public prodPerecedero
{

public:

	carne(); //con datos de fecha, con puntero a fecha, con puntero a atributo. Ver dudas en main.cpp
	carne(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string nombreAnimal, string parteDelAnimal);
	carne(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string nombreAnimal, string parteDelAnimal);
	carne(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, perecedero* perecederoPtr, bool nacional, double peso, string nombreAnimal, string parteDelAnimal);
	carne(const carne& obj);
	virtual ~carne();

	virtual string toString() const;

private:

	string _nombreAnimal;
	string _parteDelAnimal;

};

#endif // !CARNE_H