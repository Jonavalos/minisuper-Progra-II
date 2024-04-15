#include "producto.h"

producto::producto(): _codigo(""), _nombreComercial(""), _descripcion(""), _precioCosto(0.0), _categoria(""), _existencia(0), _limite(0){}

producto::producto(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite)
	: _codigo(codigo), _nombreComercial(nombreComercial), _descripcion(descripcion), _precioCosto(precioCosto), _categoria(categoria), _existencia(existencia), _limite(limite) {}

producto::producto(const producto& prod)
	: _codigo(prod._codigo), _nombreComercial(prod._nombreComercial), _descripcion(prod._descripcion), _precioCosto(prod._precioCosto), _categoria(prod._categoria), _existencia(prod._existencia), _limite(prod._limite) {}

producto::~producto()
{
}

string producto::toString() const
{
	stringstream s;
	s << "~ ~ ~ ~ ~ Informacion de producto ~ ~ ~ ~ ~" << endl;
	s << "Codigo: " << _codigo << endl;
	s << "Nombre comercial: " << _nombreComercial << endl;
	s << "Desripcion: " << _descripcion << endl;
	s << "PrecioCosto: " << _precioCosto << endl;
	s << "Categoria: " << _categoria << endl;
	s << "Existencia: " << _existencia << endl;
	s << "Limite: " << _limite << endl;
	//s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
	return s.str();
}

bool producto::operator==(const producto& obj)
{
	if (this->_codigo == obj._codigo && 
		this->_nombreComercial == obj._nombreComercial && this->_descripcion == obj._descripcion
		&& this->_precioCosto == obj._precioCosto && this->_categoria == obj._categoria 
		&& this->_existencia == obj._existencia && this->_limite == obj._limite) {
		return true;
	}
	return false;
}

string producto::getNombre() {
	return _nombreComercial;
}

double producto::getGanancia() const
{
	return _precioCosto * categoria::porcentajeGanancia(_categoria);
}

ostream& operator<<(ostream& COUT, const producto& obj)
{
	COUT << obj.toString() << endl;
	return COUT;
}
