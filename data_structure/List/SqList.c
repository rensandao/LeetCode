//线性表

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

初始条件：线性表L已存在，1<= i <= ListLength(L);
操作：在L的i位置之前插入新元素；

思路：
* 从最后一个位置开始向前遍历到第i个位置，分别将他们都向后移动一个位置；再插入元素；表长加1。
* 考虑限制问题：插入位置不合理；线性表长度大于数组长度；

*/

Status ListInsert(SqList *L, int i, ElemType e) //在L的第i个位置之前插入e，L长度加1
{
  if(L->length ==0 || i<1 || i>L->length)   //step1.判断限制条件
    return ERROR;
  if(L->length >= MAXSIZE)
    return ERROR;
  if(i<=L->length)  // 位置不在表尾   step2. 移位存好已有数据
  {
    for(int j=L->length;j>=i-1;j--)   //将插入位置i后面所有的数据都向后移一位保存
        L->data[j+1] = L->data[j];    //如果从前面存的话，就会导致数据丢失。这种方式只能从最后空位存
  }                                   //插入i位置之前，即数组i-1之前。那么i-1之后的数据后移，所以递归条件j>=i-1;
    
  L->data[i-1] = e;  //step3.存入新数据
  L->length++;       //step4.更新表长
  return OK;  
}

/*
3.删除操作

算法思路（与插入基本相反）：
1. 检查限制条件：删除位置不合理
2. 取出删除元素
3. 从删除位置开始遍历到最后一个元素位置，分别向前移位
4. 更新表长

初始条件：已知顺序线性表L，i=[1,ListLength(L)]
操作：删除第i个数据元素，并用e返回其值，L长度减1
*/

Status ListDelete(SqList *L, int i, ElemType *e)
{
  int k;
  if(L->length==0)        //step1. 判断
     return ERROR;
  if(i<1 || i>L->length)
    return ERROR;
  *e = L->data[i-1];   // step2. 先保存要删掉的值
  if(i<L->length)    //若删除的不是最后值
  {
   for(k=i+1;k<=L->length;k++)    //step3. 移位
     L->data[k-1] = L->data[k];   
  }
  L->length--;    //step4. 更新表长
  return OK;
}












