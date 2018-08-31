/*二叉树的二叉树线索存储结构定义*/

typedef enum{Link, Thread} PointerTag; // Link==0 指向左右孩子指针；Thread==1 指向前后驱的线索

typedef struct BiThrNode
{
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerTag LTag;      //左右标志
  PointerTag RTag;
} BiThrNode, *BiThrTree;


/*
线索化的实质是将二叉链表中的空指针改为指向前驱或后继的指针（这种指针即称为线索）。
将一棵二叉树转变成一个双向链表。
前驱或者后继信息只有在遍历二叉树时才能得到，因而`线索化过程就是在遍历过程中修改空指针的过程`。

*/

/*中序遍历线索化的递归函数实现*/

BiThrTree pre;    //全局变量，始终指向刚刚访问的节点
void InThreading(BiThrTree p)
{
  if(p)
  {
    InThreading(p->lchild);   //递归左子树线索化
    if(!p->lchild)
    {
      p->Ltag=Thread;   // 前驱线索
      p->lchild=pre;    // 左孩子指针指向前驱
    }
    if(!pre->rchild)
    {
      pre->RTag=Thread;
      pre->rchild=p;
    }
    pre = p;
    Inthreading(p->rchild);  //递归右子树线索化    
  }

}
