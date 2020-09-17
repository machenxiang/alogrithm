#include<iostream>
using namespace std;
//顺序表查找
int sequential_search(int *arr,int len,int key){
    arr[0]=key;
    int n=len-1;
    while (arr[n]!=key)
    {
        n--; 
    }
    return n;
    
}
//二分法查找
int binary_search(int *arr,int len,int key){
    int low=0;int high=len-1;int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(key>arr[mid]){
            low=mid+1;
        }
        else if (key<arr[mid]){
            high=mid-1;
        }
        else{
            return mid;
        }
    }
    
    return 0;
}
int main(){
    int arr[]={0,1,2,3,4,5,6,7,8,9};
    int len=sizeof(arr)/sizeof(int);
    cout<<sequential_search(arr,len,2)<<endl;
    cout<<binary_search(arr,len,9)<<endl;

    return 0;
}