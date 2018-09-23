### 串
1.定义（what?）
`` 串(string)是由零个或多个字符组成的有限序列，又叫 字符串。``


2.为什么有串（why?）
  
  字典的使用即是串的应用。
  
3.串的使用(how?)

  (1)存储结构
  
  (2)ADT
  ```
  串的基本操作与线性表差别较大。线性表更关注单个元素的操作，比如查找、插入或删除一个元素。
  
  串更多的是查找子串位置、获取指定位置子串、替换子串等操作。
  
  Operation
  * StrAssign(T,*chars) 生成一个其值等于字符串常量chars的串T
  * StrCopy(T,S) 复制S
  * ClearString(S)
  * StringEmpty(S)
  * StrLength(S)
  * StrCompare(S,T)
  * Concat(T,S1,S2)
  * SubString(Sub,S,pos,len)
  * Index(S,T,pos)
  * Replace(S,T,V)
  * StrInsert(S,pos,T)
  * StrDelete(S,pos,len)
  
  
  
  ```
  
  
  
  (3)朴素模式匹配算法
  
  (4)KMP模式匹配算法
