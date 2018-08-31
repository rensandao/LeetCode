/*按前序输入结点的值（一个字符）
#表示空树，构建二叉链表表示二叉树T。
*/

void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c",&ch);
	if(ch=='#')
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));   // ??
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)-> lchild); //构造左子树
		CreateBiTree(&(*T)-> rchild);  //构造右子树
	}
}

