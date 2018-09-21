// 线性表的单链表存储结构

typedef struct Node
{
  ElemType data;
  struct Node *next;
}Node;
typedef struct Node *LinkList; 

// 单链表的读取（2种表示）
Status GetElem(LinkList L, int i, ElemType *e)
{
  int j;
  LinkList p;
  p = L->next;    //注意，L->next表示第一个结点，L是头指针
  j = 1;
  while(p && j<i)
  {
    p = p->next;   //p由一般结构体变量变成了指针类型变量？
    j++;
  }
  if(!p || j>i)
    return ERROR;
  
  *e=p->data;
  return OK;
  
}


Node* GetElem(LinkList L, int i)
{
  int j;
    Node *p=L;      //L即是头指针，P指向头指针
    j =1;
    while (p && j<i)
    {
        p = p->next;        //p->next表示
        j++;
    }
    if (!p || j>i)
    {
        return nullptr;
    }
    return p;

}


//单链表的插入与删除
/*

  思路：
  step1.判断限制条件。
  step2.遍历链表，直至第i-1个
  step3.元素赋值
  step4.链表指针更换
  
  初始条件：顺线性表L已经存在，
  操作：在i个位置之前插入新元素e，L长度加1
*/
Status ListInsert(LinkList *L,int i, ElemType e)
{
  int j;
  LinkList p,s;
  p = *L;
  j = 1;
  if(j<i)
  {
    p = p->next; //最终p为第i-1位置结点
    j++;
  }
  if(!p || j>i)
    return ERROR;
  
  //生成空结点
  s = (LinkList)malloc(sizeof(Node));
  
  s.data = e;
  s.next = p->next;  //第i位置结点
  L->next = s;
  
  return OK; 
  
}






