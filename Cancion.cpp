//
// Created by manie on 02/10/2020.
//

#include "Cancion.h"

const std::string &Cancion::getNombre() const {
    return nombre;
}

void Cancion::setNombre(const std::string &nombre) {
    Cancion::nombre = nombre;
}

int Cancion::getPosicion() const {
    return posicion;
}

void Cancion::setPosicion(int posicion) {
    Cancion::posicion = posicion;
}

Cancion::Cancion() {

}

Cancion::Cancion(const Cancion &cpy) {
    this->posicion = cpy.posicion;
    this->nombre = cpy.nombre;
    this->interprete = cpy.interprete;
    this->autor = cpy.autor;
}

const std::string &Cancion::getAutor() const {
    return autor;
}

void Cancion::setAutor(const std::string &autor) {
    Cancion::autor = autor;
}

const std::string &Cancion::getInterprete() const {
    return interprete;
}

void Cancion::setInterprete(const std::string &interprete) {
    Cancion::interprete = interprete;
}

const std::string Cancion::toString() {
    std::string ret;
    ret += autor + " | " + interprete + " | " + nombre + " | " + std::to_string(posicion) + "\n";
    return ret;
}

void Cancion::setArchivoId(const std::string &archivoId) {
    this->archivoId = archivoId;
}

const std::string &Cancion::getArchivoId() const {
    return archivoId;
}

bool Cancion::operator==(const Cancion &rhs) const {
    return nombre == rhs.nombre &&
           archivoId == rhs.archivoId;
}

bool Cancion::operator!=(const Cancion &rhs) const {
    return !(rhs == *this);
}