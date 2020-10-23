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

void Menu::list(const StaticList<Cancion, 4000> &list){
    std::cout<<"\033[1;44;31m";
    for (int i = 0; i < list.getSize(); ++i) {
        std::cout<<list.fetch(i)<<std::endl;
    }
    std::cout<<"\033[0m"<<std::endl<<"-------------------------------------------"<<std::endl;
}

char Menu::options(){
    char ret;
    std::cout<<"Z - Incluir nueva cancion  X - Eliminar una cancion  S - Buscar una cancion  P - Ordenar la lista  F-Salir"<<std::endl;
    std::cin>>ret;
    std::cout<<std::endl<<"-------------------------------------------"<<std::endl;
    return ret;
}

int Menu::printMenu(const StaticList<Cancion, 4000> &list){
    Menu::header();
    Menu::list(list);
    return Menu::options();
}

void Menu::scanCancion(StaticList<Cancion, 4000> &list) {
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

int Menu::deleteCancion(StaticList<Cancion, 4000> &list) {
    int intIn;
    std::cout<<std::endl<<"Ingrese la posicion de la cancion en la lista: ";
    std::cin>>intIn;
    list.erase(intIn);
    return 0;
}

int Menu::buscarCancion(StaticList<Cancion, 4000> &list) {
    std::string strIn;
    bool method = 0;
    Cancion canIn;
    int res;

    std::cout<<std::endl<<"Ingrese el autor o el nombre de la cancion que desea buscar: ";
    std::getline(std::cin >> std::ws, strIn);
    canIn.setAutor(strIn);
    canIn.setNombre(strIn);
    std::cout<<std::endl<<"Que metodo desea usar (1 - Linear, 0 - Binaria): ";
    std::cin>>method;
    if(method)
        res = list.linearSearch(canIn);
    else
        res = list.binarySearch(canIn);

    if(res!=-1)
        std::cout<<std::endl<<list.fetch(res).toString()<<std::endl;
    else
        std::cout<<std::endl<<"Cancion no encontrada"<<std::endl;

    return 0;
}

void Menu::ordenarLista(StaticList<Cancion, 4000> &canciones) {
    uint16_t metodoOrd;
    bool campoAOrdenar;

    std::cout<<std::endl<<"Que metodo desea usar?"
    <<std::endl<<"0 - Burbuja (mejorada)"
    <<std::endl<<"1 - Shell"
    <<std::endl<<"2 - Insercion"
    <<std::endl<<"3 - Seleccion"
    <<std::endl<<"Opcion: ";
    std::cin>>metodoOrd;

    std::cout<<std::endl<<std::endl
    <<"Como quiere ordenar la lista?"
    <<std::endl<<"0 - Por nombre de cacion"
    <<std::endl<<"1 - Por nombre de autor"
    <<std::endl<<"Opcion: ";
    std::cin>>campoAOrdenar;

    switch(metodoOrd){
        case 0:
            if(campoAOrdenar)
                canciones.sortByEnhancedBubble(&Cancion::compareByAutor);
            else
                canciones.sortByEnhancedBubble(&Cancion::compareByNombre);
            break;

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

    }
}
