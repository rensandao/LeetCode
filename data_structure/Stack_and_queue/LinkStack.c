/*
链栈结构
结合一般栈的栈顶操作和单链表的头指针的特点。
把头指针作为栈顶，不过数据域要使用。所以对于链栈来说，不需要头结点。
*/

typedef struct StackNode     //结点的数据域+指针域
{
  ElemType data;
  struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack    //栈的栈顶指针+栈长度
{
  LinkStackPtr top;     //top为结构体指针 
  int count;
}LinkStack;

/*
进栈操作
*/
Status Push(LinkStack *S, ElemType e)
{
  LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));  
  p->data = e;
  p->next = S->top;      //过渡结点，与单链表类似，因为要保存数据和地址，所以要分配空间给p节点
  
  S->top =p;    //栈操作
  S->count++;
  
  return OK;
}

/*
#出栈操作
*/
Status Pop(LinkStack *S, ElemType *e)
{
  LinkStackPtr p;        //?  不用开辟空间
  if(StackEmpty(*S))    //step1 出栈操作前检查栈大小
    return ERROR;
  *e=S->top->data;     //step1 先存数据
  p=S->top;            // 栈顶地址赋给p
  S->top = S->top->next;   //  栈顶地址下移一位
  free(p);                  //将p保存的地址释放掉
  S->count--;
  
  return OK;
}



