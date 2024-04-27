#ifndef ABARROTE_H
#define ABARROTE_H
#include "prodPerecedero.h"

class abarrote : public prodPerecedero
{

public:

	abarrote(); //con datos de fecha, con puntero a fecha, con puntero a atributo. Ver dudas en main.cpp
	abarrote(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string empresaNombre);
	abarrote(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string empresaNombre);
	abarrote(const abarrote& obj);
	virtual ~abarrote();

	virtual string toString() const;

private:

	string _empresaNombre;

};

#endif // !ABARROTE_H