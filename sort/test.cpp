#include<iostream>
using namespace std;
//从小到达排序
void quick_sort(int* a,int left,int right){
    if(left>=right){
        return;
    }
    int l=left;
    int h=right;
    int basic=a[left];
    while (l!=h)
    {
        while(a[h]>=basic&&l<h){//右边为大数，右边比基准大为正常情况
            h--;
        }
        while (a[l]<=basic&&l<h)//左边为小数，左边比基准小为正常情况
        {
            l++;
        }
        if(l<h){
            int temp=a[l];
            a[l]=a[h];
            a[h]=temp;
        }
    }
    a[left]=a[l];
    a[l]=basic;
    quick_sort(a,left,l-1);
    quick_sort(a,l+1,right);
}
void COUT(int *a,int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"hah"<<endl;
    int arr[] = {55,2,6,4,32,12,9,73,26,100,0,37};
    int len= sizeof(arr)/sizeof(int);
    //cout<<len;
    COUT(arr,len);
    quick_sort(arr,0,len-1);
    COUT(arr,len);
    return 0;
}