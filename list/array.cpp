#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct 
{
    int *Point;//array的首地址
    int capacity;//array的容量
    int count;//array的元素个数
    
}Array;

bool is_full(Array *arr);
bool is_Empty(Array *arr);
void show_arr(Array * arr);

//开辟空间，赋初值
void init_arr(Array * arr,int cap){
    arr->Point=(int *)malloc(sizeof(int)*cap);
    arr->capacity=cap;
    arr->count=0;
}

//数组尾部追加元素 
bool append_arr(Array * arr,int value){

    if(is_full(arr)){
        return false;
    }
    else{
        arr->Point[arr->count]=value;
        arr->count=(arr->count)+1;
        return true;
    }
    /*  放在这里无法完成正常的count++
    arr->count=(arr->count)+1;
    */
}
//pos从1开始计数，第一个位置为arr[0]
//cout和pos是一样的都是从1开始计数

bool insert_arr(Array *arr,int pos,int value){
    //判断是否满
    if(is_full(arr)){
        cout<<"数组已满，无法插入"<<endl;
        return false;
    }
    if(pos<1||pos>(arr->count)+1){
        cout<<"插入位置不合法"<<endl;
        return false;
    }
    //开始移动数组
    for (int i = (arr->count)-1; i>=(pos-1); i--)
    {
        arr->Point[i+1]=arr->Point[i];
    }
    arr->Point[pos-1]=value;
    (arr->count)++;
    return true;
}
//删除指定位置的元素，并返回删除的元素
//pos从1开始计数，第一个位置为arr[0]
//int *ptr声明了一个为int 指针的形参，名字为ptr
bool delete_arr(Array *arr,int pos,int *ptr){
    if(is_Empty(arr)){
        return false;
    }
    if(pos<1||pos>(arr->count)){
        return false;
    }
    *ptr=arr->Point[pos-1];
    for(int i=pos;i<=arr->count;i++){
        arr->Point[i-1]=arr->Point[i];
    }
    (arr->count)=(arr->count)-1;
    return true;
}

bool is_Empty(Array *arr){
    if(arr->count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_full(Array *arr){
    if(arr->capacity==arr->count){
        return true;
    }
    else{
        return false;
    }
}
//升序
void sort_arr(Array *arr){
    show_arr(arr);
    int temp=0;
    for(int i=0;i<arr->count;i++)
    {
        for(int j=i+1;j<arr->count;j++)
        {
            //如果比后面数字大，则交换
            if((arr->Point)[i]>(arr->Point)[j]){
                temp=(arr->Point)[i];
                (arr->Point)[i]=(arr->Point)[j];
                (arr->Point)[j]=temp;
                //show_arr(arr);
            }
        }
    }
}
// void sort_arr1(Array *arr){
//     show_arr(arr);
//     int temp=0;
//     for(int i=0;i<arr->count;i++)
//     {
//         for(int j=i;j<arr->count;j++)
//         {
//             //如果比后面数字大，则交换
//             //这样写是错的，在j=3时j+1=4，元素只有四个，而下表四代表第5个元素
//             if((arr->Point)[i]>(arr->Point)[j+1]){
//                 temp=(arr->Point)[i];
//                 (arr->Point)[i]=(arr->Point)[j+1];
//                 (arr->Point)[j+1]=temp;
//             }
//             cout<<"内层循环"<<" J="<<j<<endl;
//             show_arr(arr);

//         }
//         cout<<"外层循环"<<" i="<<i<<endl;
//         show_arr(arr);
//     }
// }

//倒置
void inverse_arr(Array *arr){
    int i=0;
    int j=arr->count-1;
    int temp=0;
    while(i<j)
    {
        temp=arr->Point[i];
        arr->Point[i]=arr->Point[j];
        arr->Point[j]=temp;
        i++;
        j--;
    }
    

}

void show_arr(Array * arr){
    if(is_Empty(arr))
    {
        cout<<"数组为空，无法输出"<<endl;
    }
    else
    {
        for(int i=0;i<arr->count;i++)
        cout<<arr->Point[i]<<" ";
    }
    cout<<endl;

}



int main()
{
    Array arr1;
    int pVal;
    init_arr(&arr1,6);
    show_arr(&arr1);
    append_arr(&arr1,5);
    append_arr(&arr1,6);
    append_arr(&arr1,1);
    append_arr(&arr1,9);
    show_arr(&arr1);
    inverse_arr(&arr1);
    show_arr(&arr1);
    cout<<arr1.count<<endl;
    sort_arr(&arr1);
    show_arr(&arr1);
    return 0;
}