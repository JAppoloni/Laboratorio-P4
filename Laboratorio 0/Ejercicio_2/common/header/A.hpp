#ifndef CLASS_A
#define CLASS_A

#include "C.hpp"

class B;

class A{
    private:
        int a;
        B * myB;
        C * myC;
    public:
        A(int, B*, C*);
        void printInt();
};

#include "B.hpp"

#endif