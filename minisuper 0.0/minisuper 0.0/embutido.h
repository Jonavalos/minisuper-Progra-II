#ifndef EMBUTIDO_H
#define EMBUTIDO_H
#include "prodPerecedero.h"

class embutido : public prodPerecedero
{

public:

	embutido();
	embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca);
	embutido(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso, string nombreAnimal, string parteDelAnimal, bool tripa, string marca);
	embutido(const embutido& obj);
	virtual ~embutido();

	virtual string toString() const;

private:

	string _marca;
	bool _tripa;
	string _nombreAnimal;
	string _parteDelAnimal;

};

#endif // !EMBUTIDO_H