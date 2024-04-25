#include "excepciones.h"

const char* excepcionCategoria::what() const {
    return "Error: categoria mal puesta (01, 02, 03)";
}

const char* excepcionFecha::what() const {
    return "Error: formato no aceptado de fecha";
}

const char* excepcionLimite::what() const {
    return "Error: limite ingresado no valido";
}

const char* excepcionExistencia::what() const {
    return "Error: existencia ingresada no valida";
}

const char* excepcionRango::what() const {
    return "Error: lugar inexistente";
}