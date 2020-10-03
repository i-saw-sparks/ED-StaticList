#include <iostream>
#include "StaticList.h"

int main(){
    StaticList<int> lista;

    lista.insert(5, -1);
    lista.insert(6, 0);
    lista.insert(7, 1);
    lista.pushBack(8);
    lista.insert(10, 0);



    std::cout<<lista.toString()<<std::endl;

    lista.erase(1);

    std::cout<<lista.toString();
}