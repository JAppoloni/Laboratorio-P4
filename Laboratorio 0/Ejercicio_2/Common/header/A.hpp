#ifndef CLASS_A
#define CLASS_A

#include "C.hpp"

class ClassB;

class ClassA{
    private:
        int a;
        ClassB * myB;
        ClassC * myC;
    public:
        ClassA(int, ClassB*, ClassC*);
        void printInt();
};

#include "B.hpp"

#endif