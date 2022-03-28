#include "header/B.hpp"
#include<iostream>
using namespace std;

B::B(int b, A * A, C * C){
    this->b = b; 
    myA = A;
    myC = C;
}

void B::printInt(){
    cout << b;
}