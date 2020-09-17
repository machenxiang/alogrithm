#include<iostream>
using namespace std;
long f(long n){
    if(n==1){
        return 1;
    }
    else{
        return f(n-1)*n;
    }
}

int sum(int n){
    if(n==1){
        return 1;
    }
    else{
        return sum(n-1)+n;
    }
    
}
int main(void)
{
   // cout<<"hah"<<endl;
   cout<<f(7)<<endl;
   cout<<sum(100)<<endl;
   return 0;
}