//
// Created by manie on 02/10/2020.
//

#include "Menu.h"

void Menu::header()  {
    std::cout<<"top 50 canciones mas escuchadas"<<std::endl;
    std::cout<<"-------------------------------------------"<<std::endl;
}

Menu::Menu() {

}

void Menu::list(const StaticList<Cancion, 50> &list){
    for (int i = 0; i < list.getSize(); ++i) {
        std::cout<<list.fetch(i).toString();
    }
    std::cout<<std::endl<<"-------------------------------------------"<<std::endl;
}

char Menu::options(){
    char ret;
    std::cout<<"Z - Incluir nueva cancion     X - Eliminar una cancion   F-Salir"<<std::endl;
    std::cin>>ret;
    std::cout<<std::endl<<"-------------------------------------------"<<std::endl;
    return ret;
}

int Menu::printMenu(const StaticList<Cancion, 50> &list){
    Menu::header();
    Menu::list(list);
    return Menu::options();
}

void Menu::scanCancion(StaticList<Cancion, 50> &list) {
    Cancion temp;
    std::string strIn;
    int intIn;

    std::cout<<"Ingrese el nombre de la cancion: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setNombre(strIn);
    std::cout<<"Ingrese el nombre del autor: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setAutor(strIn);
    std::cout<<"Ingrese el nombre del interprete: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setInterprete(strIn);
    std::cout<<"Ingrese el nombre del archivo: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setArchivoId(strIn);
    std::cout<<"Ingrese la posicion en el ranking: ";
    std::cin>>intIn;
    temp.setPosicion(intIn);
    std::cout<<"Ingrese la posicion de la cancion en la lista: ";
    std::cin>>intIn;

    list.insert(temp, intIn);
}

int Menu::deleteCancion(StaticList<Cancion, 50> &list) {
    int intIn;
    std::cout<<std::endl<<"Ingrese la posicion de la cancion en la lista: ";
    std::cin>>intIn;
    list.erase(intIn);
    return 0;
}
