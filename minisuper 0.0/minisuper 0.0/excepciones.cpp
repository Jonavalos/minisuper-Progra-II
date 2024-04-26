#include "excepciones.h"

const char* excepcionCategoria::what() const {
    return "Error: categoria mal puesta (01, 02, 03)";
    cout << endl;
}

const char* excepcionFecha::what() const {
    return "Error: formato no aceptado de fecha";
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
