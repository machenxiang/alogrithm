#include<iostream>
using namespace std;
typedef struct BTnode
{
    char data;
    struct BTnode *plchild;
    struct BTnode *prchild;
}BTNODE,*pBTNODE;
 
 pBTNODE create_tree(void){
     pBTNODE pA=(pBTNODE)malloc(sizeof(BTNODE));
     pBTNODE pB=(pBTNODE)malloc(sizeof(BTNODE));
     pBTNODE pC=(pBTNODE)malloc(sizeof(BTNODE));
     pBTNODE pD=(pBTNODE)malloc(sizeof(BTNODE));
     pBTNODE pE=(pBTNODE)malloc(sizeof(BTNODE));
     pA->data='A';
     pB->data='B';
     pC->data='C';
     pD->data='D';
     pE->data='E';
     pA->plchild=pB;
     pA->prchild=pC;
     pC->plchild=pD;
     pD->prchild=pE;
     pB->prchild=pB->plchild=pC->prchild=pD->plchild=pE->plchild=pE->prchild=NULL;
     return pA;
 }

void fisrt_trave_btree(pBTNODE pbt){
    /* 1.先遍历根节点
       2.遍历左根树
       3.遍历右根树
     */
    //pBTNODE p=pbt;
    if(pbt!=NULL){
        cout<<pbt->data<<endl;
        fisrt_trave_btree(pbt->plchild);
        fisrt_trave_btree(pbt->prchild);
    }
}

void mid_trave_btree(pBTNODE pbt){
    /* 
       1.遍历左根树
       2.遍历根节点
       3.遍历右根树
     */
    //pBTNODE p=pbt;
    if(pbt!=NULL){
        mid_trave_btree(pbt->plchild);
        cout<<pbt->data<<endl;
        mid_trave_btree(pbt->prchild);
    }
}

void last_trave_btree(pBTNODE pbt){
    /* 
       1.遍历左根树
       2.遍历右根树
       3.遍历根节点
      
     */
    //pBTNODE p=pbt;
    if(pbt!=NULL){
        last_trave_btree(pbt->plchild);
        last_trave_btree(pbt->prchild);
        cout<<pbt->data<<endl;
        
    }
}
int main(void){

    pBTNODE btree = create_tree();
    fisrt_trave_btree(btree);
    cout<<endl;
    mid_trave_btree(btree);
    cout<<endl;
    last_trave_btree(btree);
    //cout<<btree->plchild->data<<endl;
    return 0;
}