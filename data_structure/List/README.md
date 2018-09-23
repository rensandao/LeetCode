### 线性表
****

1 [线性表的定义](https://blog.csdn.net/sinat_20265495/article/details/52716710)

2 线性表的基本操作(pseudo code)

  * InitList(*L) 初始化操作
  * ListEmpty(L) 
  * ClearList(*L)
  * GetElem(L,i,*e)
  * LocateElem(L,e)
  * ListInsert(*L,i,e)
  * ListDelete(*L,i,*e)  删除线性表L中第i个位置的元素，并用e返回其值。
  * ListLength(L)

一般，复杂的操作多是由这些基本的操作的组合来实现的。

3 线性表的顺序存储结构

  * 定义：用一段地址连续的存储空间，依次来存储线性表的数据元素。
  
4 顺序存储结构的插入与删除
```
 * 最差情况，插入与删除第一个位置，全体要移位n-1次。时间复杂度为O(n),平均为(n-1)/2.所以平均复杂度还是O(n)。
   
   而存取数据时，不管是哪个位置，都是O(1)。
   
   因而，线性表的顺序存储比较适合元素个数不太变化，更多的存取数据的应用。而非插入删除。
   
 * 优点： 无须为表中元素的逻辑先后关系增加额外的存储空间； 快速存取表中任意元素。
 
 * 缺点： 插入和删除移动大量元素；当线性表长度变化大时，难以确定合适的存储空间容量； 造成存储空间的“碎片”问题。
```

********

5 线性表的链式存储结构
```
  * 针对顺序存储的不足问题而提出。
  * 什么结点Node？：数据域+指针域 组成的元素的存储映像。
  * 由n个结点链接成一个链表，即线性表的链式存储结构。由于每个结点中只包含一个指针域，所以也叫`单链表`。
  * 单链表中，存储第一个结点位置叫做头指针！通常附设头结点，其数据域可以不存储信息。
  * 最后一个指针为空（NULL或^）
  
  头指针与头结点的异同：
  
  1. 头指针是指向链表的第一个结点的指针，若链表有头结点，则是指向头结点的指针。头结点的next指向第一个结点的指针。
  ```



6 单链表的读取

7 单链表的插入与删除
```
  算法复杂度为O(n)
  
  对于插入和删除数据频繁的操作，单链表的效率优势会越明显。

```

8 单链表的整表创建

9 单链表的整表删除

10 顺序存储结构与单链表结构优缺点
```
(1)存储分配方式： 顺序存储结构采用一段地址连续的存储单元依次存储；单链表采用链式，任意存储单元；
 
(2)时间性能：查找的话，顺序存储结构O(1),单链表O(n); 插入或删除的话，顺序结构平均移动一半元素，时间为O(n)；单链表O(1).

(3)空间性能： 顺序需预分配，大小需要把握。单链表很灵活。
 
 综上，频繁查找，插入删除操作很少时采用顺序结构。需频繁插入删除，应采用单链表。
 当线性表的元素个数变化较大或不知道，采用单链表。
 
 ```

*****

11 静态链表

12 循环链表

13 双向链表

****

14 总结



### 知识点
*****
1. 关于结构体指针的声明与定义，表示法问题；
   * LinkList p,q
   * p->
   * LinkList *L