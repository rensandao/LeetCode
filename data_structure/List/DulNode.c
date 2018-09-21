/*
线性表的双向链表存储结构

*/
typedef struct DulNode
{
  ElemType data;
  struct DulNode *prior;  //直接前驱指针
  struct DulNode *next;   //直接后驱指针
} DualNode, *DuLinkList;


//插入操作的顺序很重要
/*
  存储元素e结点为s，将结点s插入到结点p和p->next之间  (图形记忆)step1/2/3/4
*/
s->prior = p;
s->next = p->next;
p->next->prior = s;
p->next =s;

