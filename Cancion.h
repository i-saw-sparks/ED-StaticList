//
// Created by manie on 02/10/2020.
//

#ifndef LISTA_ESTATICA_CANCION_H
#define LISTA_ESTATICA_CANCION_H

#include <string>
#include <iomanip>

class Cancion {
private:
    std::string nombre, autor, interprete;
    int posicion;
public:
    Cancion();
    Cancion(const Cancion&);

    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    int getPosicion() const;
    void setPosicion(int posicion);
    const std::string &getAutor() const;
    void setAutor(const std::string &autor);
    const std::string &getInterprete() const;
    void setInterprete(const std::string &interprete);

    const std::string toString();
};


#endif //LISTA_ESTATICA_CANCION_H
