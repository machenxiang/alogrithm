#include<iostream>
using namespace std;
typedef struct BTnode
{
    char data;
    struct BTnode *plchild;
    struct BTnode *prchild;
}BTNODE,*pBTNODE;
//用前序遍历方式输入数据
//指向这棵树的指针的指针
//传入的是指向一棵树的指针的指针
void create_btree(pBTNODE *T){
    char c;
    // scanf("%c",&c);
    cin>>c;
    if(c=='#'){
        *T=NULL;
    }
    else{
        //地址里面的地址开辟一个新空间
        *T=(pBTNODE)malloc(sizeof(BTNODE));
        (*T)->data=c;
        //这里取地址是对(*T)->prchild这个整体取地址，为了对应函数pBTNODE *T
        //指向取到指向左子树地址的地址
        create_btree(&((*(*T)).plchild));
        create_btree(&(*T)->prchild);
    }
    
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

    pBTNODE btree;
    create_btree(&btree);
    cout<<btree->data;
    fisrt_trave_btree(btree);
    cout<<endl;
    mid_trave_btree(btree);
    cout<<endl;
    last_trave_btree(btree);
    //cout<<btree->plchild->data<<endl;
    return 0;
}