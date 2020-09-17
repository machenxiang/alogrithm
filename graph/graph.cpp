#include<iostream>
using namespace std;
#define MAXVEX 100//最大定点数100
#define INFINITY 65535//无穷，表示没有连接
#define LEN 6

typedef struct {
    int *pbase;
    int front;
    int rear;
}QUEUE;
bool is_full(QUEUE* pq);
bool is_Empty(QUEUE *pq);
bool travelFlag[MAXVEX];

void init_queue(QUEUE *pq){
    pq->pbase=(int *)malloc(sizeof(int)*6);
    pq->front=0;
    pq->rear=0;
}

void ENQUEUE(QUEUE *pq,int val){
    if(is_full(pq)){
        cout<<"队列已满"<<endl;
    }
    else{
        pq->pbase[pq->rear]=val;
        pq->rear=((pq->rear)+1)%LEN;
    }
}
void OUT_QUEUE(QUEUE *pq,int *val){
    if(is_Empty(pq)){
        cout<<"队列空"<<endl;
    }
    else
    {
        *val=pq->pbase[pq->front];
        pq->front=(pq->front+1)%LEN;
    }
    
}
bool is_full(QUEUE* pq){
    //if(pq->rear+1%LEN==pq->front)
    //不加括号就先计算了1%len
    if((pq->rear+1)%LEN==pq->front){
        cout<<"队列已满"<<endl;
        return true;
    }
    else{
        return false;
    }
    
}
bool is_Empty(QUEUE *pq){
    if(pq->rear==pq->front){
        return true;
    }
    else{
        return false;
    }
    
}
void traverse_queue(QUEUE *pq){
    int p=pq->front;
    while (p!=pq->rear)
    {
        cout<<(pq->pbase)[p]<<" ";
        p=(p+1)%LEN;
    }
    cout<<endl;
    
}


typedef struct Graph
{
    char vex[MAXVEX];
    int adjMartix[MAXVEX][MAXVEX];
    int numVertex;
    int numEdge;
}GRAPH;


void CreateGraph(GRAPH *g){
    int a,b,w;
    cout<<"请输入图的顶点数"<<endl;
    cin>>g->numVertex;
    cout<<"请输入图的边数"<<endl;
    cin>>g->numEdge;
    for(int i=0;i<g->numVertex;i++){
        cout<<"请输入顶点"<<endl;
        cin>>g->vex[i];
    }
    //初始化邻接矩阵
    for(int i=0;i<g->numVertex;i++){
        for(int j=0;j<g->numVertex;j++){
            g->adjMartix[i][j]=INFINITY;
        }
    }
    //按边的个数输入权重
    //无向图为对称矩阵
    cout<<"边数："<<g->numEdge<<endl;
    for(int i=0;i<g->numEdge;i++){
        cout<<"请输入边的起始顶点"<<endl;
        
        cin>>a;cin>>b;cin>>w;
        g->adjMartix[a][b]=w;
        g->adjMartix[b][a]=w;
    }
}
//深度优先遍历
void DFS(GRAPH *g,int j){
    travelFlag[j]=true;
    cout<<g->vex[j]<<endl;;
    for(int k=0;k<g->numVertex;k++){
        if(g->adjMartix[j][k]!=INFINITY&&travelFlag[k]!=true){
            DFS(g,k);
        }
    }
}
void DFStravse(GRAPH *g){
    for(int i=0;i<g->numVertex;i++){
        travelFlag[i]=false;
    }

    for(int i=0;i<g->numVertex;i++){
        if(travelFlag[i]==false){
            DFS(g,i);
        }
    }

}
void BFSTraverse(GRAPH *g){
    QUEUE q;int k;//存放临时遍量
    //初始化全部未遍历
    //1.从第一个点开始，未遍历则标记遍历输出，加入队列
    //2.队列不为空则出队列（这个值已经遍历了）然后找到和这个点相连的点再次判断
    //3.未遍历则标记遍历输出，加入队列
    init_queue(&q);
    for(int i=0;i<g->numVertex;i++){
        travelFlag[i]=false;
    }

    for(int i=0;i<g->numVertex;i++){
        if(!travelFlag[i]){
            travelFlag[i]=true;
            cout<<g->vex[i]<<" ";
            ENQUEUE(&q,i);
        }
        while(!is_Empty(&q)){
            OUT_QUEUE(&q,&k);
            for(int j=0;j<g->numVertex;j++){
                int temp=k;
                if((g->adjMartix)[k][j]!=INFINITY&&!travelFlag[j]){
                    travelFlag[j]=true;
                    cout<<g->vex[j]<<" ";
                    ENQUEUE(&q,j);
                }
            
            }
        }
    }
    cout<<endl;
}

int main(){
    GRAPH g;
    CreateGraph(&g);
    cout<<"深度优先遍历"<<endl;
    DFStravse(&g);
    cout<<"广度优先遍历"<<endl;
    BFSTraverse(&g);
    
    
    
    return 0;
}


