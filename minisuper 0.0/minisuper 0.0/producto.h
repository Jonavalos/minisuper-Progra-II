#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "categoria.h"
#include "fecha.h"
class producto
{
public:
	producto();
	producto(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite);
	producto(const producto& prod);
	virtual ~producto();

	//poner const en gets
	virtual string toString() const;
	virtual double getGanancia()const ;

	//operadores
	virtual bool operator==(const producto& obj);

	//supongo que se usa la categoria con su % de ganancia para sacar la ganancia aqui
	//**PREGUNTAR**
	//tirar excepcion de categoria no existente
	

protected:
	string _codigo;
	string _nombreComercial;
	string _descripcion;
	double _precioCosto;
	string _categoria;
	int _existencia;
	int _limite;

};

//declarada como free function
// o se le agrega 'friend' al inicio para poderla declarar dentro de la clase
ostream& operator<<(ostream& COUT, const producto& obj);

#endif // !PRODUCTO_H



