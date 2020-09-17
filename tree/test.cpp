
#include<iostream>
#include<malloc.h>
#include<stack>
using namespace std;
//结构体里面引用结构体要把结构体写完整才会不报错
typedef struct Node
{
    int Date;
    struct Node* pNext;
}NODE,*pNODE;//NODE等价于struct Node，struct Node*等价于pNODE


pNODE creat_list(void){
    int len;//链表长度
    int temp;//用于暂时存储数据
    pNODE pHead=(pNODE)malloc(sizeof(NODE));
    if(pHead==NULL)
    {
        cout<<"内存分配失败，程序终止"<<endl;
        exit(-1);
    }
    pNODE pTail= pHead;
    pTail->pNext=NULL;
    //空链表也有头结点
    cout<<"请输入创建链表的长度"<<endl;
    cin>>len;
    for(int i=0;i<len;i++){
        pNODE pNew=(pNODE)malloc(sizeof(NODE));
        if(pNew==NULL){
            cout<<"内存分配失败，程序终止"<<endl;
            exit(-1);
            }
        cout<<"请输入第"<<i+1<<"个节点的值: ";
        cin>>temp;
        cout<<endl;
        pNew->Date=temp;
        pTail->pNext=pNew;
        
        pNew->pNext=NULL;
        pTail=pNew;
    }
    return pHead;
}
void traversal_list(pNODE pnode){
    cout<<"开始遍历链表"<<endl;
    pNODE p=pnode->pNext;
    while(p!=NULL){
        cout<<p->Date<<" ";
        p=p->pNext;
    }
    cout<<endl;
}
bool is_Empty(pNODE pHead){
    if(pHead->pNext==NULL){
        return true;
    }
    else{
        return false;
    }
    
}
int length_list(pNODE pHead){
    int len=0;
    pNODE p=pHead->pNext;
    while(p!=NULL){
        len++;
        p=p->pNext;
    }
    return len;
}
//在pHead所指向的链表的第pos个节点前面插入一个节点，节点值为val，并且pos从1开始
bool insert_list(pNODE pHead,int pos,int val){
    int i=0;
    pNODE p=pHead;
    while (p!=NULL&&i<pos-1){
        p=p->pNext;
        i++;
    }
    if(i>pos-1||p==NULL){
        return false;
    }
    pNODE pNew=(pNODE)malloc(sizeof(NODE));
    pNew->Date=val;
    if(pNew==NULL){
        cout<<"内存已满，程序终止"<<endl;
        exit(-1);
    }
    pNODE temp=p->pNext;
    p->pNext=pNew;
    pNew->pNext=temp;
    return true;
}
//删除指定位置的链表并返回删除位置的值
bool delete_list(pNODE pHead,int pos,int* val){
        int i=0;
    pNODE p=pHead;
    while (p->pNext!=NULL&&i<pos-1){
        p=p->pNext;
        i++;
    }
    if(i>pos-1||p->pNext==NULL){
        return false;
    }
    pNODE q=p->pNext;
    *val=q->Date;
    p->pNext=p->pNext->pNext;
    free(q);
    q=NULL;
    return true;
}
//从小到大排序
bool sort_list(pNODE pHead){
    int len=length_list(pHead);
    int i,j;//用于计数
    int temp=0;
    pNODE p,q;
    for( i=0,p=pHead->pNext;i<len;i++,p=p->pNext){
        for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext){
            if(p->Date>q->Date){
                temp=p->Date;
                p->Date=q->Date;
                q->Date=temp;
            }
        }
    }
}
    Node* FindKthToTail(Node* head, unsigned int k) {
        stack<Node *> s1;
        Node* p=head;
        int count=0;
        while(p!=NULL){
            s1.push(p);
            p=p->pNext;
        }
        if(s1.empty()){
            return NULL;
        }
        for(int i=1;i<k;i++){
            s1.pop();
        }
        return s1.top();
     
    }

int main(){
    pNODE pHead=creat_list();

    traversal_list(pHead);
   // is_Empty(pHead);
    cout<<"链表长度为："<<length_list(pHead)<<endl;
    //sort_list(pHead);
    traversal_list(pHead);
    //insert_list(pHead,1,10);
    //traversal_list(pHead);
    cout<<FindKthToTail(pHead,2)->Date<<endl;
    return 0;
}


