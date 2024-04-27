#include "categoria.h"

double categoria::porcentajeGanancia(string categoria)
{
    if (categoria == "01") {//productos en conserva
        return 0.15;
    }
    if (categoria == "02") {//abarrotes: perecederos
        return 0.20;
    }
    if (categoria == "03") {//embutidos: public perecederos
        return 0.30;
    }
    return 0.0; //tirar excepcion de categoria no existente
}
