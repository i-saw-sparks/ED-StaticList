//
// Created by manie on 02/10/2020.
//

#ifndef LISTA_ESTATICA_STATICLIST_H
#define LISTA_ESTATICA_STATICLIST_H

#include <array>
#include "StaticListException.h"
#include <string>
#include <functional>

template<typename T, int MAXSIZE = 4096>
class StaticList {
private:
    std::array<T, MAXSIZE> data;
    int last;

    void copy(const StaticList &);

    bool validPos(const int &) const;
    void pushBack(const T &);
    void swapData(T&, T&);
public:
    StaticList();
    StaticList(const StaticList &);

    bool isEmpty() const;
    bool isFull() const;

    void insert(const T &, const int &);
    void erase(const int &);
    T fetch(const int &) const;

    int getSize() const;
    int getFirst() const;
    int getLast() const;
    int getPrevious(const int &) const;
    int getNext(const int &) const;

    void eraseAll();

    int binarySearch(const T &);
    int linearSearch(const T &);

    void sortByEnhancedBubble(std::function<int(T, T)> comp);
    void sortByShell(std::function<int(T, T)> comp);
    void sortByInsert(std::function<int(T, T)> comp);
    void sortBySelect(std::function<int(T, T)> comp);

    StaticList &operator=(const StaticList &);
};

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::StaticList():last(-1) {}

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::StaticList(const StaticList<T, MAXSIZE> &cpy) {
    this->size = cpy.getSize();
    this->copy(cpy);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::copy(const StaticList<T, MAXSIZE> &cpy) {
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
    if (pos == last) {
        pushBack(ins);
        return;
    }

    if (!validPos(pos))
        throw StaticListException("Invalid memory access");
    if (isFull())
        throw StaticListException("Invalid memory access, the list was full");

    for (int i = last; i>pos ; --i) {
        data[i+1] = data[i];
    }
    data[pos+1] = ins;
    last++;
}

template<typename T, int MAXSIZE>
bool StaticList<T, MAXSIZE>::validPos(const int &pos) const{
    return pos >= 0 && pos <= last;
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::pushBack(const T &ins) {
    if (isFull())
        throw StaticListException("Invalid memory access, the list was full");

    data[last + 1] = ins;
    last++;
}


template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::erase(const int &pos) {
    if (!validPos(pos))
        throw StaticListException("Invalid memory access");

    for (int i = pos; i < last ; ++i) {
        data[i] = data[i+1];
    }

    last--;
}


template<typename T, int MAXSIZE>
T StaticList<T, MAXSIZE>::fetch(const int &pos) const {
    if (!validPos(pos))
        throw StaticListException("Invalid memory access");
    return data[pos];
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::getSize() const {
    return last + 1;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::getFirst() const {
    if (isEmpty())
        return -1;
    return 0;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::getLast() const {
    return last;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::getPrevious(const int &pos) const {
    if (validPos(pos - 1))
        return pos - 1;
    else
        return -1;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::getNext(const int &pos) const {
    if (pos + 1 <= last + 1)
        return pos + 1;
    else
        return -1;
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::eraseAll() {
    last = -1;
}

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>& StaticList<T, MAXSIZE>::operator=(const StaticList &cpy) {
    copy(cpy);
    return *this;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::linearSearch(const T &look) {
    for (int i = 0; i < this->getSize(); ++i) {
        if(look == this->fetch(i))
            return i;
    }
    return -1;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::binarySearch(const T &look) {
    int i = 0, j = this->getLast(), mid;

    while(i <= j){
        mid = (i+j)/2;
        if(this->fetch(mid) == look)
            return mid;
        if(look < this->fetch(mid))
            j = mid-1;
        else
            i = mid +1;
    }

    return -1;
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByEnhancedBubble(std::function<int(T, T)> comp) {
    bool flag = false;
    int i = last;
    do {
        flag = false;
        for (int j = 0; j < i; ++j) {
            if(comp(data[j], data[j+1]) > 0 ){
                swapData(data[j], data[j+1]);
                flag = true;
            }
        }
        i--;
    }while(flag);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByShell(std::function<int(T, T)> comp) {

}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByInsert(std::function<int(T, T)> comp) {

}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortBySelect(std::function<int(T, T)> comp) {

}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::swapData(T& d1, T& d2) {
    T aux(d1);
    d1 = d2;
    d2 = aux;
}


#endif //LISTA_ESTATICA_STATICLIST_H
