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

BiThrTree pre;    //全局变量，始终指向刚刚访问过的结点（按照顺序的） 初始应指向NULL
void InThreading(BiThrTree p)    //初始化当前输入的结点，结构体，包括数据，左右子树和左右标签Tag；
{
  if(p)  //判断是否有结点；
  {
    InThreading(p->lchild);   //递归左子树线索化
    if(!p->lchild)            // 若该结点没有左孩子；
    {
      p->Ltag=Thread;         // 若没有，则标签修改为Thread,表示前驱指针
      p->lchild=pre;          // 前驱指针指向前一个遍历顺序的结点
    }
    if(!pre->rchild)          // 若前一个结点（前驱）没有右孩子
    {                          
      pre->RTag=Thread;       // 则修改标签
      pre->rchild=p;          // 
    }
    pre = p;                  //上述2个if 不会同时执行的。
    Inthreading(p->rchild);  //递归右子树线索化    
  }

}
