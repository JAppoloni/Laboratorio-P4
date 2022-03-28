#include "header/A.hpp"
#include<iostream>
using namespace std;

A::A(int a, B * B, C * C){
    this->a = a; 
    myB = B;
    myC = C;
}

void A::printInt(){
    cout << a;
}