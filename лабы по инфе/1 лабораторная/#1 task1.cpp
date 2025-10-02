// Sample C++ code
#include <iostream>
using namespace std;

int main() {
    float a=0;
    cout<<"Введите свой доход: ";
    cin>>a;
    if (a<=50000)\
    {
        cout<<"Ваш налог: "<<a*0.13;
    }
    else {
        if (50001<a<=100000)
        {
            cout<<"Ваш налог: "<<a*0.2;
        }
        else
        {
            cout<<"Ваш налог: "<<a*0.25;
        }
    }
    return 0;
}