#include "excepciones.h"

const char* excepcionCategoria::what() const {
    return "Error: categoria inexistente (01, 02, 03)";
    cout << endl;
}

const char* excepcionFecha::what() const {
    return "Error: formato de fecha no aceptado ";
    cout << endl;
}

const char* excepcionRango::what() const {
    return "Error: lugar inexistente";
    cout << endl;
}

const char* excepcionCantidad::what() const {
    return "Error: cantidad no disponible";
    cout << endl;
}
