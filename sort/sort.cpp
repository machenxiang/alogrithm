#include<iostream>
using namespace std;
int len;
//还差堆排序和归并排序
/***************桶排序**************
1.5个元素参与排序
2.排序的值范围为0~10
3.从小到大排序
4.返回一个新的数组
 */
void barrel_sort(int *arr){
    int temp_arr[11]={0};
        for(int j=0;j<len;j++){
            temp_arr[arr[j]]++;
        }
        cout<<"计数情况为：";
        for(int i=0;i<=10;i++){
            cout<<temp_arr[i]<<" ";
        }
        cout<<endl;
    for(int i=0;i<=10;i++){
        for(int j=0;j<temp_arr[i];j++){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
/*冒泡排序
从大到小
 */
void bubble_sort(int *arr){
    int temp=0;
    for(int i=0;i<len;i++){
        for(int j=1;j<len-i;j++){
            if(arr[j-1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
        cout<<endl;
            for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*快速排序
1.从小到大
 */
 void quick_sort(int *a,int left,int right){

    if(left>=right){
        return;
    }
    int i=left;
    int j=right;
    int basic=a[i];
    while (i!=j){
        while(a[j]>=basic&&i<j){
            j--;
        }
        while (a[i]<=basic&&i<j){
            i++;
        }
        //可能出现a[i]中一直没有大于basic的数
        if(i<j){
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    a[left]=a[j];
    a[j]=basic;
    //这样写会导致数组越界，在老的数组已经制定到新位置上后，还在继续+1或-1会导致越界
    // quick_sort(&a[left],left,i-1);

    // quick_sort(&a[i+1],i+1,right);
    quick_sort(a,left,i-1);

    quick_sort(a,i+1,right);
}
//选择排序
//从小到达
void select_sort(int *arr,int len){
    int temp_index=0;
    bool swap_flag=false;
    for(int i=0;i<len;i++){
        int min=arr[i];
        for(int j=i+1;j<len;j++){
            if(min>arr[j]){
                min=arr[j];
                temp_index=j;
                swap_flag=true;
                
            }
        }
        //判断交换条件不能每一步都交换，不然会错
        if(swap_flag){
            int temp=arr[temp_index];
            arr[temp_index]=arr[i];
            arr[i]=temp;
            swap_flag=false;
        }
    }
}
//直接插入排序
void Insert_sort(int *arr,int len){
    int i,j,temp;
    for(i=1;i<len;i++){
        temp=arr[i];
        for(j=i-1;j>=0&&arr[j]>temp;j--){
            arr[j+1]=arr[j];//当前面的元素比后面的大，则把前面的向后移动
        }
        //执行完j--再去判断是否满足条件，满足则执行for循环，不满足则跳出，所以在不满足时已经有多减了一次
        arr[j+1]=temp;
    }
}
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void ShellSort(int *arr,int len){
    
    int i,j,gap;
    for(gap=len/3;gap>0;gap=gap/3){
        for(i=gap;i<len;i++){
            for(int j=i;j-gap>=0&&arr[j-gap]>arr[j];j=j-gap){
                swap(arr[j-gap],arr[j]);
            }
        }
        for(int k=0;k<len;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    // cout<<"请输入数组长度"<<endl;
    // cin>>len;
    // int arr[len]={0};
    // cout<<"请输入数据"<<endl;
    // for(int i=0;i<len;i++){
    //     cin>>arr[i];
    // }
    //barrel_sort(arr);

    //bubble_sort(arr);
    //quick_sort(arr,0,len-1);
    //select_sort(arr,len);
    //Insert_sort(arr,len);
    int arr[] = {55,2,6,4,32,12,9,73,26,100,0,37};
    int len= sizeof(arr)/sizeof(int);
    // ShellSort(arr,len);
    quick_sort(arr,0,len-1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}