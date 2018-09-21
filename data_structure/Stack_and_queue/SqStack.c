/*
栈的结构定义
*/
typedef int ElemType;
typedef struct
{
  ElemType data[MAXSIZE];
  int top;      //用于栈顶指针； 相当于顺序存储结构的数组下标，不够这里top可以为-1； 
}SqStack;

Status Push(SqStack *S, ElemType e)
{
  if(*S->top == MAXSIZE-1)   //????? S or *S
    return ERROR;
    
  S->top++;      // 栈顶指针？加1
  S->data[S->top] =e;    //插入新元素e到新位置 即还是栈顶
  
  return OK;
}

/*
栈的顺序存储结构——出栈操作pop
*/
Status Pop(SqStack *S, ElemType *e)     //又是*S??
{
  if(S->top == -1)
    return ERROR;
  *e = S->data[S->top];
  S->top--;
  
  return OK;
}

