#include<iostream>
using namespace std;
//函数声明可以不写形参
//bool is_full(QUEUE * pq);
int len=6;
//出队列入队列r,f都是+操作
typedef struct 
{
    int * pBase;
    int front ;
    int rear;
}QUEUE;
bool is_full(QUEUE *pq);
//初始化队列，rear和front都为0
void init_queue(QUEUE * pq){
    pq->pBase=(int*)malloc(sizeof(int)*len);
    pq->front=0;
    pq->rear=0;
}
//入队
bool entry_queue(QUEUE *pq,int val){
    if(is_full(pq)){
        cout<<"队列已满"<<endl;
        return false;
    }
    else{
        pq->pBase[pq->rear]=val;
        pq->rear++;
        return true;
    }
}
//判断队列是否满
bool is_full(QUEUE *pq){
    if((pq->rear+1)%len==pq->front){
        return true;
    }
    else{
        return false;
    }
}
void travel_queue(QUEUE *pq)
{
    int f=pq->front;
    while (f!=pq->rear){
        cout<<pq->pBase[f]<<" ";
        f=(f+1)%len;
    }
    cout<<endl;
}
bool is_Empty(QUEUE *pq){
    if(pq->front==pq->rear){
        return true;
    }
    else{
        return false;
    }
    
}
bool out_queue(QUEUE * pq,int *val){
    if(is_Empty(pq)){
        cout<<"队列为空"<<endl;
        return false;
    }
    else{
        *val=pq->pBase[pq->front];
        pq->front=(pq->front+1)%len;
        return true;
    }
}

int main(){
    QUEUE q1;
    int val;
    init_queue(&q1);
    entry_queue(&q1,1);
    entry_queue(&q1,2);
    entry_queue(&q1,3);
    entry_queue(&q1,4);
    entry_queue(&q1,5);
    travel_queue(&q1);
    out_queue(&q1,&val);
    travel_queue(&q1);

    cout<<val<<endl;
    return 0;
}