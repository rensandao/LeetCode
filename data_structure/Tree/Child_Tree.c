/*树的 孩子表示法结构定义*/
#define MAX_TREE_SIZE 100
typedef struct CTNode    /*孩子结点*/
{
  int child;  //数据域，存储界结点在表头数组中的下标   数组的排序已经排好，
  struct CTNode *next;
} *ChildPtr;

typedef struct      /*表头结构*/
{
  TElemType data;
  ChildPtr firstchild;
} CTBox;

typedef struct
{
  CTBox nodes{MAX_TREE_SIZE};
  int r,n;
} CTree;
