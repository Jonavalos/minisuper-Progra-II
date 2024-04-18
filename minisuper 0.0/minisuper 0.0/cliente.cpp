#include "cliente.h"

cliente::cliente(string cedula) : _cedula(cedula) {
}

cliente::cliente(const cliente& cli) : _cedula(cli._cedula) {

}

cliente::~cliente() {

}
