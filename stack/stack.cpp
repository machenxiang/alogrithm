#include<iostream>
using namespace std;
//节点
typedef struct  Node
{
    int Data;
    struct Node * pNext;
}NODE,*PNODE;
//栈
typedef struct 
{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;

//栈初始化
//栈顶等于栈底为空栈
void init_stack(PSTACK ps){
    ps->pBottom=(PNODE)malloc(sizeof(NODE));
    if(ps->pBottom==NULL){
        cout<<"内存分配失败"<<endl;
        exit(-1);
    }
    ps->pBottom->pNext=NULL;
    ps->pTop=ps->pBottom;
}
//压栈
//新的Node地址域存放的是上一个Node的地址
//然后将新的Node置为栈顶
void push_stack(PSTACK ps,int val){
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
    if(pNew==NULL){
    cout<<"内存分配失败"<<endl;
    exit(-1);
    }
    pNew->pNext=ps->pTop;
    pNew->Data=val;
    ps->pTop=pNew;
}
//遍历
void trave_stack(PSTACK ps){
    PNODE p=ps->pTop;
    while (p!=ps->pBottom)
    {
        cout<<p->Data<<" ";
        p=p->pNext;
    }
    cout<<endl;
}
//出栈，并保存返回出栈值
//将栈顶置为原来的栈顶元素的上一个元素
bool pop_stack(PSTACK ps,int * pval){
    if(ps->pBottom==ps->pTop){
        cout<<"栈为空"<<endl;
        return false;
    }
    PNODE temp=ps->pTop;
    *pval=temp->Data;
    ps->pTop=temp->pNext;
    free(temp);
    temp=NULL;
    return true;
}
//clear清空数据，栈的结构还在
void clear_stack(PSTACK ps){
    PNODE p=ps->pTop;
    PNODE q=NULL;
    while (p!=ps->pBottom)
    {
        q=p->pNext;
        free(p);
        p=q;
    }
    ps->pTop=ps->pBottom;
}

int main(){   
    STACK s1;
    int val;
    init_stack(&s1);
    push_stack(&s1,1);
    push_stack(&s1,-33);
    push_stack(&s1,3);
    trave_stack(&s1);
    // pop_stack(&s1,&val);
    // cout<<val<<endl;
    // pop_stack(&s1,&val);
    // cout<<val<<endl;
    // trave_stack(&s1);
    clear_stack(&s1);
    trave_stack(&s1);

    cout<<"hah"<<endl;
} 