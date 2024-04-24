#include "cliente.h"

cliente::cliente(string cedula) : _cedula(cedula) {
}

cliente::cliente(const cliente& cli) : _cedula(cli._cedula) {

}

cliente::~cliente() {

}

string cliente::toString() const
{
    stringstream s;
    s << "Cedula: " << _cedula;
    return s.str();
}

string cliente::getCedula() const
{
    return _cedula;
}
