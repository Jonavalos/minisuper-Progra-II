#ifndef EMBUTIDO_H
#define EMBUTIDO_H
#include "carne.h"
#include "empaque.h"

class embutido : public carne
{

public:

	embutido();
	embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca);
	embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca);
	embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, perecedero* perecederoPtr, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca);
	embutido(const embutido& obj);
	virtual ~embutido();

	string getNombre();

	virtual string toString() const;

private:

	string _marca;
	empaque* _empaquePtr;

};

#endif // !EMBUTIDO_H