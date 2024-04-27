#ifndef PRODPERECEDERO_H
#define PRODPERECEDERO_H
#include "producto.h"

class prodPerecedero: public producto
{
public:
	prodPerecedero(); //con datos de fecha, con puntero a fecha, con puntero a atributo. Ver dudas en main.cpp
	virtual ~prodPerecedero();
	prodPerecedero(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso);	
	prodPerecedero(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso);
	prodPerecedero(const prodPerecedero& obj);

	virtual string toString() const;
private:
	bool _nacional;
	double _peso;
	fecha* _fechaPtr;
};


#endif // !PRODPERECEDERO_H


