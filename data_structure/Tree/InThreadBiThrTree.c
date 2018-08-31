/*1. 二叉树的二叉树线索存储结构定义*/
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

/*2. 中序遍历线索化的递归函数实现*/

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
    pre = p;                  //画图可知，上述2个if 不会同时执行的。
    Inthreading(p->rchild);  //递归右子树线索化    
  }

}


/*为了更好遍历操作，作了调整：在上述二叉树线索链表上添加了一个新的结点——头结点！
并让头结点lchild指针指向二叉树的根节点；
rchild指向中序排列访问的最后一个节点；
二叉树中序序列中第一个节点lchild指针和最后一个rchild指针均指向头结点的指针域。

*/

/*3. 基于上述的调整后，以下便是遍历获取数据的算法。
  T:中序遍历二叉线索链表表示的二叉树
  T指向头结点，头结点左链lchild指向根节点，头结点右键rchild指向中序遍历的最后一个结点。
*/
Status InOrderTraverse_Thr(BiThrTree T)
{
  BiThrTree p;
  p = T->lchild;
  
  while( p != T)            
  {
    while(T->LTag==Link )   //若LTag==Link, 直到中序序列第一结点。
      p = p->lchild;
      print("%c", p);
    while(p->RTag==Thread && p->rchild !=T)  //从第一结点开始，根据rchild指针域 直到 头结点
    {                                        //如果RTag=1且不是最后则执行，如果RTag=0,则跳出。
      p = p->rchild;  //
      print("%c",p->data);
    }
    p = p->rchild;                          // 跳到下一个结点；
  }
  return OK; 
}


/*
小结：
1. 充分利用二叉树链表中的空指针域的空间（节省了空间）
2. 保证创建时的一次遍历就可以存储信息，以后随后方便使用前驱后继的信息（节省了时间）
3. 根据实际问题，如果所用二叉树经常遍历或者查找节点时需要某种遍历序列中的前驱和后继，那么
    采用这种线索二叉链表的存储结构是很好的选择。
*/

