#ifndef FECHA_H
#define FECHA_H
#include "bibliotecas.h"
class fecha //excepcion de dia/mes/aio invalidos
{
public:
	fecha();
	fecha(int dia, int mes, int anio);
	fecha(const fecha& obj);
	virtual ~fecha();
	string toString() const;


private:
	int _dia;
	int _mes;
	int _anio;

};


#endif // !FECHA_H



