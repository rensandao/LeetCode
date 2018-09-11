/* 二叉排序树的插入操作 */
/* 
前提：二叉排序树T中不存在关键字等于key的数据元素时，插入key并返回TRUE,否则返回FALSE.
*/
typedef struct BiTNode
{
  int data;
  struct BiTNode *lchild, *rchild; //左右孩子指针;
} BiTNode, *BiTree;

Status InsertBST(BiTree *T, int key)
{
  BiTree p,s;
  if(!SearchBST(*T,key,NULL,&p)
  {
    s = (BiTree)malloc(sizeof(BiTNode));
    s->data =key;
    s->lchild = s->rchild = NULL;
    if(!p)
      *T=s;
    else if(key<p->data)
      p->lchild =s;
    else
      p->rchild =s;
    return TRUE;
  }
  else
    return FALSE; //
}
