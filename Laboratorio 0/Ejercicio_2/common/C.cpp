#include "header/C.hpp"
#include<iostream>
using namespace std;

C::C(int c, A * A, B * B){
    this->c = c; 
    myA = A;
    myB = B;
}

void C::printInt(){
    cout << c;
}