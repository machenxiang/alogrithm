#include<iostream>
using namespace std;
//形参a原始位置b中间位置c目标位置
void hannuota(int n,char a,char b,char c){
    if(n==1){
        cout<<"将编号为"<<n<<"的盘子从"<<a<<"柱子上移动到"<<c<<"柱子上"<<endl;
    }
    else{
        hannuota(n-1,a,c,b);
        cout<<"将编号为"<<n<<"的盘子从"<<a<<"柱子上移动到"<<c<<"柱子上"<<endl;
        hannuota(n-1,b,a,c);
    }
    
}
int main(void)
{
    int len;
    char ch1='a';
    char ch2='b';
    char ch3='c';
    cout<<"请输入汉诺塔层数"<<endl;
    cin>>len;
    hannuota(len,ch1,ch2,ch3);

   return 0;
}