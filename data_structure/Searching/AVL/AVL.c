/*****step1. 构建存储结构。******/

/*
AVL二叉树的二叉链表结点结构定义
*/
typedef struct BiTNode
{
  int data;
  int bf;
  struct BiTNode *lchild, *rchild;   
}BiTNode, *BiTree;

/*****step2. 左右旋转操作功能******/
/*
step2. 右旋操作 
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
 左旋操作
*/
void L_Rotate(BiTree *P)
{
  BiTree R;
  R=(*P)->rchild;
  (*P)->rchild=R->lchild;
  R->lchild=(*P);
  *P=R;
}

/*****step3. 左右旋转的分类情况******/
/*
左平衡旋转处理
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

/*右平衡旋转情况*/



/*****step4 主函数：
    （1）查找target,没有则插入结点；
    （2）判断是否仍平衡二叉树，不是则执行左或右子树旋转操作
    （3）返回结果；
******/
Status InsertAVL(BiTree *T,int e,Status *taller)
{
  if(!*T)  //表示空树或叶子结点
  {
    /*加入taller，表示插入新结点，树长高*/
    *T =(BiTree)malloc(sizeof(BiTNode));
    (*T)->data=e;
    (*T)-lchild=(*T)->rchild =NULL;
    (*T)->bf=EH;
    *taller =TRUE;
    }
    else
    {
      if(e==(*T)->data; 
      {
        *taller = FALSE;
         return FALSE;
      }
      if(e< (*T)->data)  //小于结点数据则在T的左子树进行搜索；
       {
        if(!InsertAVL(&(*T)->lchild,e,taller))   //未插入递归调用直到找到返回FALSE，否则说明插入了结点！哪一步？
          return FALSE;
       }
         if(*taller)   //已经插入左子树中。
         {
          switch((*T)->bf)   //再检查T的平衡度，自动更新？？
          {                  //判断插入前原来的左右子树的深度比较，根据平衡度做对应的平衡处理
            case LH:
              LeftBalance(T);
              *taller=FALSE;
              break;
            case EH:
              (*T)->bf=LH;
              *taller=TRUE;
              break;
            case RH:
              (*T)->bf=EH;
              *taller=FALSE;
              break;
          }
         }      
   }
   
   else
   {
     if(!InsertAVL(&(*T) ->rchild, e, taller))
         return FALSE;
     if(*taller)
     {
       switch((*T)->bf)
       {
         case LH:
           (*T)->bf =EH;
           *taller=FALSE;
           break;
         case EH:
           (*T)->bf =RH;
           *taller=TRUE;
           break;
         case RH:
           RightBalance(T);
           *taller=FALSE;
           break;       
       } 
      }
     }
  }
  return TRUE;
}
















