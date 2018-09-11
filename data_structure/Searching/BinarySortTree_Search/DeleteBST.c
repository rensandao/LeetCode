/*
删除结点有三种情况：
1.叶子结点；
2.仅有左或右子树的结点；
3.左右子树都有的结点。
*/


/*
二叉树存在关键字等于key的数据元素，则删除
*/

Status DeleteBST(BiTree *T, int key)
{
  if(!*T)
    return FALSE;
  else
  {
    if(key==(*T->data)
       return Delete(T);
    else if (key<(*T) ->data)
       return DeleteBST(&(*T)->lchild,key);
    else
       return DeleteBST(&(*T)->rchild,key);
  
  }

}
