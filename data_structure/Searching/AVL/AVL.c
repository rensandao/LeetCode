/*
1. AVL二叉树的二叉链表结点结构定义
*/
typedef struct BiTNode
{
  int data;
  int bf;
  struct BiTNode *lchild, *rchild;   
}BiTNode, *BiTree;

/*
2. 右旋操作 
p为根的二叉树右旋处理，
*/
void R_Rotate(BiTree *P)
{
  BiTree L; 
  L = (*P)->lchild;    // L指向P的左子树
  (*P)->lchild = L->rchild; //L现在的右子树放到P的左子树上
  L-rchild=(*P);  // P现在放到L的右子树
  *P=L;     //L放到P之前的位置，完成更新
}

/*
3. 左旋动作
*/
void L_Rotate(BiTree *P)
{
  BiTree R;
  R=(*P)->rchild;
  (*P)->rchild=R->lchild;
  R->lchild=(*P);
  *P=R;
}

/*
4.左平衡旋转处理
*/
#define LH +1  //左侧深度高
#define EH 0
#define RH -1   // 右侧深度高

void LeftBalance(BiTree *T)  //指针T指向结点为根
{
  BiTree L,Lr;
  L=(*T)->lchild;
  switch(L->bf)
  {
      //检查T的左子树的平衡度，并处理
    case LH:  // 插在T的左孩子左子树，单右旋
      (*T)->bf =L->bf =EH;
      R_Rotate(T);
      break;
    case RH: // 新结点插入在T的左孩子右子树，双旋处理
      Lr= L->rchild;   //Lr指向T的左孩子右子树根
      switch(Lr->bf)
      {
        case LH: 
          (*T)->bf =RH;
          L-bf=EH;
          break;
        case EH:
          (*T)-bf = L->bf=EH;
          break;
        case RH:
          (*T)->bf=EH;
          L->bf=LH;
          break;
        
      }
      Lr->bf=EH;
      L_Rotate(&(*T)->child);
      R_Rotate(T);  
  }
}






