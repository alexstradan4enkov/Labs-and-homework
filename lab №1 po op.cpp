#include <iostream>
using namespace std;
int main(){
    int num[10];
    for (int i=0; i<10;i++)
    {
        cout<<"введите элемент "<< i+1<<": ";
        cin>>num[i];
    }
    cout<<"элементы массива: ";
    for (int i=0; i<10; i++)
    {
        cout<<num[i]<<",";
    }
    int sum=0;
    for (int i=0;i<10;i++)
    {
        sum=sum+num[i];
    }
    cout<<"сумма элементов: "<<sum<<endl;
    int min=num[0];
    for (int i=0;i<10;i++) {
        if (min>num[i]){
            min=num[i];
        }
    }cout<<"минимальный элемент: "<<min<<endl;
     for (int j=0;j<9;j++){   for (int i=0;i<9;i++) {
            if (num[i]>num[i+1]) {
                int h=num[i];
                num[i]=num[i+1];
                num[i+1]=h;
            }
         }  
    }
    for (int i=0; i<10; i++)
    {
        cout<<num[i]<<",";
    }
    return 0;
}
