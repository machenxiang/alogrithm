#include<iostream>
using namespace std;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
//i表示第i个元素，二线性表的起始索引为0，

typedef struct 
{
    ElemType data[MAXSIZE];//定义了线性表的容量
    int length;//线性表当前长度线性表中元素的个数
}Sqlist;

//插入线性表
Status ListInsert(Sqlist *L,int i,int e)
{
    if(L->length==MAXSIZE)//线性表已经满了
    {
        return ERROR;
    }
    if(i<1||i>L->length+1)//插入的位置小于1或者大于线表元素个数()
    {
        return ERROR;
    }
    if(i<=L->length)//插入位置正确
    {
        for(int j=L->length-1;j>=i-1;j-- )
        {
            L->data[j+1]=L->data[j];
        }
    }
}

//获得元素
Status GetElem(Sqlist *L,int i,int *e)
{
    if(i<1||i>L->length)
    {
        return ERROR;
    }
    *e=L->data[i-1];
    return OK;
}
void PrintElem(Sqlist *l)
{
    for(int i=0;i<=l->length-1;i++)
    {
        cout<<l->data[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Sqlist l={100,10,1};
    printf("%d\n",l.data[1]);
    printf("hah");
    return 0;
}
