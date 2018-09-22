### 栈与队列

#### 栈
*****
1.定义理解
```
  栈(stack) 是限定仅在表尾进行插入和删除操作的线性表。
  
  首先，栈是线性表。各元素具有前驱后继关系。规定只能在线性表的表尾进行插入和删除操作，其表尾指的是栈顶。
  
  FIFO（先进后出结构）
 
```
2.ADT

  * InitStack(*S)
  * DestroyStack(*S)
  * ClearStack(*S)
  * StackEmpty(S)   //需要修改表的传指针*S，不需要的传值S
  * GetTop(S,*e)
  * Push(*S,e)
  * Pop(*S,*e)
  * StackLength(S)


#### 队列
*****
 队列(queue) 是只允许在一端进行插入操作，而在另一端进行删除操作的线性表。
