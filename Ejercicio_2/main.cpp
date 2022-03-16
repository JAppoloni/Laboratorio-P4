#include<iostream>
using namespace std;

#include "include/A.h"
#include "include/B.h"
#include "include/C.h"

int main(){
    int a, b, c;

    cout<<"ingrese un valor para A: ";
    cin>>a;
    ClassA objA(a, NULL, NULL);
    cout<<"el objeto de la clase A es: ";
    objA.printInt();
    cout<<endl;

    cout<<"ingrese un valor para B: ";
    cin>>b;
    ClassB objB(b, NULL, NULL);
    cout<<"el objeto de la clase B es: ";
    objB.printInt();
    cout<<endl;

    cout<<"ingrese un valor para C: ";
    cin>>c;
    ClassC objC(c, NULL, NULL);
    cout<<"el objeto de la clase C es: ";
    objC.printInt();
    cout<<endl;

    return 0;
}