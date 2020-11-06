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
    T *data[MAXSIZE];
    int last;

    void copy(const StaticList &);

    bool validPos(const int &) const;
    void pushBack(const T &);
    void swapPointers(int, int);
public:
    StaticList();
    StaticList(const StaticList &);
    ~StaticList();

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

    int binarySearch(const T &, std::function<int(T, T)> comp);
    int linearSearch(const T &, std::function<int(T, T)> comp);

    void sortByEnhancedBubble(std::function<int(T, T)> comp);
    void sortByShell(std::function<int(T, T)> comp);
    void sortByInsert(std::function<int(T, T)> comp);
    void sortBySelect(std::function<int(T, T)> comp);
    void sortByMerge(const int&, const int&, std::function<int(T, T)> comp);
    void sortByMerge(std::function<int(T, T)> comp);
    void quickSort(const int&, const int&, std::function<int(T, T)> comp);
    void quickSort(std::function<int(T, T)> comp);

    StaticList &operator=(const StaticList &);
};

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::StaticList():last(-1) {
    for(T* n : data){
        n = nullptr;
    }
}

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::StaticList(const StaticList<T, MAXSIZE> &cpy) {
    for(T* n : data){
        n = nullptr;
    }
    this->copy(cpy);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::copy(const StaticList<T, MAXSIZE> &cpy) {
    for (int i = 0; i < cpy.last + 1; ++i) {
        data[i] = cpy.data[i];
    }
    last = cpy.last;
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

    data[pos+1] = new T(ins);
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

    data[last + 1] = new T(ins);
    last++;
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::erase(const int &pos) {
    if (!validPos(pos))
        throw StaticListException("Invalid memory access");

    delete data[pos];

    for (int i = pos; i < last ; ++i) {
        data[i] = data[i+1];
    }

    data[last] = nullptr;
    last--;
}


template<typename T, int MAXSIZE>
T StaticList<T, MAXSIZE>::fetch(const int &pos) const {
    if (!validPos(pos))
        throw StaticListException("Invalid memory access");
    return *(data[pos]);
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
    for (int i = 0; i < last; ++i) {
        delete data[i];
        data[i] = nullptr;
    }
    last = -1;
}

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>& StaticList<T, MAXSIZE>::operator=(const StaticList &cpy) {
    copy(cpy);
    return *this;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::linearSearch(const T &look, std::function<int(T, T)> comp) {
    for (int i = 0; i < this->getSize(); ++i) {
        if(comp(look, *(data[i])) == 0)
            return i;
    }
    return -1;
}

template<typename T, int MAXSIZE>
int StaticList<T, MAXSIZE>::binarySearch(const T &look, std::function<int(T, T)> comp) {
    int i = 0, j = last, mid;

    while(i <= j){
        mid = (i+j)/2;
        if(comp(*(data[mid]), look) == 0)
            return mid;
        if(comp(look, *(data[mid])) < 0)
            j = mid-1;
        else
            i = mid +1;
    }

    return -1;
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByEnhancedBubble(std::function<int(T, T)> comp) {
    bool flag;
    int i = last;
    do {
        flag = false;
        for (int j = 0; j < i; ++j) {
            if(comp(*(data[j]), *(data[j+1])) > 0 ){
                swapPointers(j, j+1);
                flag = true;
            }
        }
        i--;
    }while(flag);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByShell(std::function<int(T, T)> comp) {
    float factor = 1.f/2.f;
    int dif = ((last +1 ) * factor);

    while(dif > 0){
        for(int i = dif; i<= last; ++i){
            for(int j = i; j >= dif && comp(*(data[j-dif]), *(data[j])) > 0; j-= dif)
                swapPointers(j - dif, j);
        }
        dif *= factor;
    }
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByInsert(std::function<int(T, T)> comp) {
    int j;
    T* aux;

    for(int i = 1; i <= last; ++i){
        aux = data[i];
        j = i;
        while(j>0 && comp(*aux, *(data[j-1])) < 0){
            data[j] = data[j-1];
            j--;
        }
        if(i != j){
            data[j] = aux;
        }
    }
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortBySelect(std::function<int(T, T)> comp) {
    int aux;
    for(int i = 0; i < last; i++){
        aux = i;
        for(int j = i+1; j <= last; j++){
            if(comp(*(data[j]), *(data[aux])) < 0) {
                aux = j;
            }
        }

        if(i != aux){
            swapPointers(i, aux);
        }

    }
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByMerge(std::function<int(T, T)> comp) {
    sortByMerge(0, last, comp);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::sortByMerge(const int& left, const int& right, std::function<int(T, T)> comp) {

    if(left >= right)
        return;

    int mid((left + right)/2);

    sortByMerge(left, mid, comp);
    sortByMerge(mid + 1, right, comp);

    static T *aux[MAXSIZE];
    for(int i = left; i <= right; i++)
        aux[i] = data[i];

    int i(left), j(mid + 1), iter(left);

    while(i <= mid && j<= right){
        while(i <= mid && comp(*(aux[i]), *(aux[j])) <= 0) {
            data[iter++] = aux[i++];
        }

        if(i <= mid) {
            while (j <= right && comp(*(aux[j]), *(aux[i])) <= 0) {
                data[iter++] = aux[j++];
            }
        }
    }

    while (i <= mid)
        data[iter++] = aux[i++];
    while(j <= right)
        data[iter++] = aux[j++];
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::quickSort(std::function<int(T, T)> comp) {
    quickSort(0, last, comp);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::quickSort(const int& left, const int& right, std::function<int(T, T)> comp) {
    if(left >= right)
        return;

    int i(left), j(right);

    while(i < j) {
        while (i < j && comp(*(data[i]), *(data[right])) <= 0)
            i++;
        while (i < j && comp(*(data[j]), *(data[right])) >= 0)
            j--;
        if(i != j)
            swapData(data[i], data[j]);
    }

    if(i != right)
        swapData(data[i], data[right]);

    quickSort(left, i - 1, comp);
    quickSort(i + 1, right, comp);
}

template<typename T, int MAXSIZE>
void StaticList<T, MAXSIZE>::swapPointers(int pos1, int pos2) {
    T* aux(data[pos1]);
    data[pos1] = data[pos2];
    data[pos2] = aux;
}

template<typename T, int MAXSIZE>
StaticList<T, MAXSIZE>::~StaticList(){
    for (int i = 0; i <= last; ++i) {
        delete data[i];
        data[i] = nullptr;
    }
}

#endif //LISTA_ESTATICA_STATICLIST_H