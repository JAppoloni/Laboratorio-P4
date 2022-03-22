#include<iostream>
using namespace std;

#include "Common/header/A.hpp"
#include "Common/header/B.hpp"
#include "Common/header/C.hpp"

int main(){
    int a, b, c;

    cout<<"ingrese un valor para A: ";
    cin>>a;
    A objA(a, nullptr, nullptr);
    cout<<"el objeto de la clase A es: ";
    objA.printInt();
    cout<<endl;

    cout<<"ingrese un valor para B: ";
    cin>>b;
    B objB(b, nullptr, nullptr);
    cout<<"el objeto de la clase B es: ";
    objB.printInt();
    cout<<endl;

    cout<<"ingrese un valor para C: ";
    cin>>c;
    C objC(c, nullptr, nullptr);
    cout<<"el objeto de la clase C es: ";
    objC.printInt();
    cout<<endl;

    return 0;
}