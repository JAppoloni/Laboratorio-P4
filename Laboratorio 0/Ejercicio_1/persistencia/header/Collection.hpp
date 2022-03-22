#ifndef _COLLECTION_HH_
#define _COLLECTION_HH_

#include "../../common/datatype/header/Constantes.hpp"
#include <iostream>

template<typename T>
class Collection {
    private:

    T* array;
    int top;
    
    public:
    
    Collection() {
        array = new T[MAX_HUESPEDES];
        top = -1;
    }

    ~Collection() {
        delete[] array;
    }

    void add(T value) {
        top++;
        array[top] = value;
    }

    int index(T value) {
        int index = 0;
        while (index <= top && value != array[index]) {
            index++;
        }

        return index > top ? -1 : index;
    }

    bool exists(T value) {
        return index(value) != -1;
    }

    void remove(T value) {
        int position = index(value);
        if (position == -1) {
            return;
        }

        while (position < top) {
            array[position] = array[position + 1];
            position++;
        }

        top--;
    }

    int size() {
        return top + 1;
    }

    T* values() {
        return array;
    }

    friend std::ostream& operator<<(std::ostream& out, const Collection<T> &collection) {
        int index = 0;
        while (index <= collection.top) {
            out << collection.array[index] << ", ";
            index++;
        }

        return out;
    }
};


#endif
