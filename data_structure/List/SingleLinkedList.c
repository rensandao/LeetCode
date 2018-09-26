#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int ElemType;
typedef int Status;


// 线性表的单链表存储结构
typedef struct Node
{
  ElemType data;
  struct Node *next;
}Node;
typedef struct Node *LinkList;  //或直接写在上述定义后面。Node表示一般结构体型结点，*LinkList表示指向结构体型结点的指针。

// 单链表的读取（第1种表示），最坏时间复杂度O(n)
Status GetElem(LinkList L, int i, ElemType *e)  //
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

//单链表的读取（第2种表示）
Node* GetElem(LinkList L, int i)
{
    int j;
    Node *p=L;      //L即是头指针，P指向头指针
    j =1;
    while (p && j<i)
    {
        p = p->next;        //p->next
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
  描述
  初始条件：顺线性表L已经存在，
  操作：在i个位置之前插入新元素e，L长度加1  
  
  思路：
  step1.判断限制条件。
  step2.遍历链表，直至第i-1个
  step3.元素赋值
  step4.链表指针更换
  

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
  s = (LinkList)malloc(sizeof(Node));  //
  
  s.data = e;
  s.next = p->next;  //第i位置结点
  p->next = s;
  L->length ++;
  return OK; 
  
}

//删除
/*
  描述
  初始条件：顺序线性表L存在
  操作：删除L的第i个数据元素，并用e返回其值，L长度减1。
  
  思路（与插入相反）
  step1.判断限制条件。声明一节点p指向链表第一个结点，初始化j=1开始；
        当j<i,遍历链表，直到i位置；
        
  step2.将要删除结点p->next赋给q；
  step3.链表指针更新;
  step4.q结点的值赋给e，返回;
  step5.释放q结点。
  
*/

Status ListDelete(LinkList *L, int i, ElemType *e)
{
  int j;
  LinkList p,q;
  p = *L;
  j=1;
  if(j<i)
  {
    p = p->next;   //i-1位置结点
    j++;
  }
  if(!p ||j>i)
    return ERROR;
  
  q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  
  return OK;  
}










