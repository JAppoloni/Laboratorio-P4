#include "include/A.h"
#include<iostream>
using namespace std;

ClassA::ClassA(int a, ClassB * B, ClassC * C){
    this->a = a; 
    myB = B;
    myC = C;
}

void ClassA::printInt(){
    cout << a;
}