/*
线性表的顺序存储结构：
  三个属性：
  1. 存储空间的起始位置：数组data的存储位置即是存储空间位置；
  2. 线性表的最大存储容量： 数组长度MAXSIZE
  3. 线性表当前长度： length
  
 注意：数组的长度与线性表的区别。

*/

#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
  ElemType data[MAXSIZE];
  int length;
}SqList;
