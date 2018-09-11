/*二叉树的二叉链表节点结构定义*/
typedef struct BiTNode
{
  int data;     
  struct BiTNode *lchild, *rchild; // left and right childen pointers.
}BiTNode, *BiTree;

/*
排序树查找
递归查找二叉排序树T中是否存在key，
指针f
*/
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
  if(!T)    /*若结点为叶子结点，则查找停止*/
  {
    *p=f;  //指针指向查找路径上访问的最后一个结点
    return FALSE;
  }
  else if (key== T->data)
  {
    *p = T;
    return TRUE;
  }
  else if (key< T->data)
    return SearchBST(T->lchild, key, T, p);
  else
    return SearchBST(T->rchild, key, T, p);
}
