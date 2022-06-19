#ifndef CLASS_B
#define CLASS_B

#include "A.hpp"
#include "C.hpp"

class B{
    private:
        int b;
        A * myA;
        C * myC;
    public:
        B(int, A*, C*);
        void printInt();
};

#endif