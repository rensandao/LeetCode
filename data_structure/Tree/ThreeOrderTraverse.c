/*二叉树的前序遍历递归算法*/
void PreOrderTraverse(BiTree T)
{
  if(T==NULL)
    return;
  print("%c",T->data);  // 显示结点数据， 这里用%c
  PreOrderTraverse(T->lchild);   
  PreOrderTraverse(T->rchild);
}


/*中序*/
void PreOrderTraverse(BiTree T)
{
  if(T==NULL)
    return;
  PreOrderTraverse(T->lchild);
  print("%c",T->data);  // 显示结点数据，放在做左子节点后。
  PreOrderTraverse(T->rchild);
}

/*后序*/
void PreOrderTraverse(BiTree T)
{
  if(T==NULL)
    return;
  
  PreOrderTraverse(T->lchild);   
  PreOrderTraverse(T->rchild);
  print("%c",T->data);  // 显示根结点数据，放在左右之后
}
