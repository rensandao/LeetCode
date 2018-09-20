/*
0.定义
线性表的顺序存储结构：
  三个属性：
  1. 存储空间的起始位置：数组data的存储位置即是存储空间位置；
  2. 线性表的最大存储容量： 数组长度MAXSIZE
  3. 线性表当前长度： length
  
 注意1：数组的长度与线性表的区别。
 注意2：线性表的下标从1开始。

*/

#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
  ElemType data[MAXSIZE];
  int length;
}SqList;


/*
1.获得元素操作

前提条件：顺序线性表L已存在，i表示线性表L的第i个位置满足：1<= i <= ListLength(L)
*/
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OK 1

status GetElem(SqList L, int i, ElemType *e)
{
  if(L.length == 0 || i<1 || i>L.length)  //如果链表为空，或链表下标不在范围内
    return ERROR;
  *e = L.data[i-1];   //指针e指向查找的元素
  return OK;
}

/*
2.插入操作

思路：
* 从最后一个位置开始向前遍历到第i个位置，分别将他们都向后移动一个位置；再插入元素；表长加1。
* 考虑限制问题：插入位置不合理；线性表长度大于数组长度；

*/

Status ListInsert(SqList *L, int i, ElemType e) //在L的第i个位置之前插入e，L长度加1
{
  if(L->length ==0 || i<1 || i>L.length)
    return ERROR;
  
  
  
  
  
  
  L->data[i-1] = e;
  L->length++;
  return OK;  
}


