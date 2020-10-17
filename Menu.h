//
// Created by manie on 02/10/2020.
//

#ifndef LISTA_ESTATICA_MENU_H
#define LISTA_ESTATICA_MENU_H

#include "StaticList.h"
#include "Cancion.h"
#include <iostream>
#include <iomanip>

class Menu {
public:
    Menu();
    static void header();
    static void list(const StaticList<Cancion, 50>&);
    static char options();
    static void scanCancion( StaticList<Cancion, 50>&);
    static int deleteCancion(StaticList<Cancion, 50>&);
    static int buscarCancion(StaticList<Cancion, 50>&);
    static int printMenu(const StaticList<Cancion, 50> &);
};


#endif //LISTA_ESTATICA_MENU_H
