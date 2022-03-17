#include "header/B.hpp"
#include<iostream>
using namespace std;

ClassB::ClassB(int b, ClassA * A, ClassC * C){
    this->b = b; 
    myA = A;
    myC = C;
}

void ClassB::printInt(){
    cout << b;
}