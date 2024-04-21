#include "decoradorAbs.h"

decoradorAbs::decoradorAbs(double precioAcumulado, compraProducto* compraPtr) : compraProducto(precioAcumulado), _compraPtr(compraPtr) {}

decoradorAbs::~decoradorAbs() {}