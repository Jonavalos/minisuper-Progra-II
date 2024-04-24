#ifndef CONSERVA_H
#define CONSERVA_H
#include "producto.h"
class conserva: public producto
{
public:
	conserva();
	virtual ~conserva();
	conserva(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, bool envasado);
	conserva(const conserva& obj);
	
	virtual string toString() const;

private:
	bool _envasado;

};

#endif // !CONSERVA_H



