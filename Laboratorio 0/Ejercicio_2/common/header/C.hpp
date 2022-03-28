#ifndef CLASS_C
#define CLASS_C

class A;
class B;

class C{
    private:
        int c;
        A * myA;
        B * myB;
    public:
        C(int, A*, B*);
        void printInt();
};

#include "A.hpp"
#include "B.hpp"

#endif
