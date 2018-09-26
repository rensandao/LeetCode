#include "stdio.h"

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#define MAXSIZE 20
typedef int ElemType;
typedef int Status;

typedef struct
{
  ElemType data[MAXSIZE];
  int length;
}SqList;

Status InitList(SqList *L)  //初始化顺序线性表
{
  L->length =0;
  return OK;
}

int main()
{
  SqList L;
  ElemType e;
  Status i;
  
  i = InitList(&L);
  printf("After Initializing: L.length=%d\n", L.length);
}
