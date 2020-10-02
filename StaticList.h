//
// Created by manie on 02/10/2020.
//

#ifndef LISTA_ESTATICA_STATICLIST_H
#define LISTA_ESTATICA_STATICLIST_H

#include <array>
#include "StaticListException.h"

template<typename T, int MAXSIZE = 2048>
class StaticList {
private:
    std::array<int, MAXSIZE> data;
    int last;

    void copy(const StaticList&);
    bool validPos(const int&);
public:
    StaticList();
    StaticList(const StaticList&);

    bool isEmpty() const;
    bool isFull() const;

    void insert(const T&, const int&);
    void pushBack(const T&);

    void erase(const int&);

    T fetch(const int&) const;

    int getSize() const;

    int getFirst() const;
    int getLast() const;
    int getPrevious(const int&) const;
    int getNext(const int&) const;

    void eraseAll();

    StaticList& operator = (const StaticList&);
};

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::StaticList():last(-1) {}

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::StaticList(const StaticList<T, MAXSIZE>& cpy) {
    this->size = cpy.getSize();
    this->copy(cpy);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::copy(const StaticList<T, MAXSIZE>& cpy) {
    for (int i = 0; i < cpy.last() + 1; ++i) {
        this->data[i] = cpy.fetch(i);
    }
}

template<typename T, int MAXSIZE>
bool StaticList<T, MAXSIZE>::isEmpty() const {
    return last == -1;
}

template<typename T, int MAXSIZE>
bool StaticList<T, MAXSIZE>::isFull() const {
    return last == MAXSIZE;
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::insert(const T &ins, const int &pos) {
    if(!validPos(pos)){
        throw StaticListException("Invalid memory access");
        return;
    }
}

template<typename T, int MAXSIZE>
bool StaticList<T, MAXSIZE>::validPos(const int &pos) {
    return pos >= 0 && pos <= MAXSIZE-1;
}


#endif //LISTA_ESTATICA_STATICLIST_H
