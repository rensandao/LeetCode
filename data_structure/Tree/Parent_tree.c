/*树的双亲表示法 节点结构定义*/

#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode            // 节点结构
{
  TElemType data;
  int parent;
} PTNode;
tydef struct                    //树结构
{
  PTNode nodes{MAX_TREE_SIZE};  //结点数组
  int r,n;                     //根位置和结点数
}PTree;
