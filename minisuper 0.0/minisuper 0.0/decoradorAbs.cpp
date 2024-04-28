#include "decoradorAbs.h"

decoradorAbs::decoradorAbs(double precioAcumulado, int cantidad, compraProducto* compraPtr) 
	: compraProducto(precioAcumulado, cantidad), _compraPtr(compraPtr) {}

decoradorAbs::~decoradorAbs() {}