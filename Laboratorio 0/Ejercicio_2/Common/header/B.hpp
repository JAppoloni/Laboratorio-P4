#ifndef CLASS_B
#define CLASS_B

#include "A.hpp"
#include "C.hpp"

class ClassB{
    private:
        int b;
        ClassA * myA;
        ClassC * myC;
    public:
        ClassB(int, ClassA*, ClassC*);
        void printInt();
};

#endif