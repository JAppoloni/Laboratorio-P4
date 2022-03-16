#ifndef CLASS_C
#define CLASS_C

class ClassA;
class ClassB;

class ClassC{
    private:
        int c;
        ClassA * myA;
        ClassB * myB;
    public:
        ClassC(int, ClassA*, ClassB*);
        void printInt();
};

#include "A.h"
#include "B.h"

#endif
