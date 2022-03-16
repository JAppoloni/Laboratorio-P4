#include "include/C.h"
#include<iostream>
using namespace std;

ClassC::ClassC(int c, ClassA * A, ClassB * B){
    this->c = c; 
    myA = A;
    myB = B;
}

void ClassC::printInt(){
    cout << c;
}