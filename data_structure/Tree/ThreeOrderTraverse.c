/*二叉树的前序遍历递归算法*/
//下述的代码，遍历输出只能以printf()形式输出，如果要在c++中存放在vector中，则需要定义全局变量vector变量。再调用vector元素输出函数。
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
