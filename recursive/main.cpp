#include<iostream>
using namespace std;
void f(int n){
    if(n==1){
        cout<<"hah"<<endl;
    }
    else{
        f(n-1);
    }
}
int main(void)
{
   // cout<<"hah"<<endl;
   f(3);
    return 0;
}