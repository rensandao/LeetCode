### 描述

### 思路

1. 用栈实现 *181210*

	前面刚做过先序遍历[144 Binary Tree Preorder Traversal](https://github.com/rensandao/LeetCode/tree/master/144.%20Binary%20Tree%20Preorder%20Traversal)。

	(1) *181210* 初次思路如下，但提交结果是Memory Limit Exceeded。

	
	a. 中序遍历顺序是：左孩子，根节点，左孩子。
	
		首先想到先序遍历的代码逻辑，是先把根节点压入栈，然后再判断若有右结点则压栈。再左结点入栈。

		整体指针移动的锚是根结点，且循环体内不用入栈，直接输出。所以整体比较顺。
	
	b. 但中序，细想一下，则依据先找到第一个左结点，以及其双亲和其兄弟。这样的小三角结构。然后再循环。ps:循环的边界在哪？ 
	
		逻辑：
			1）当前结点有无左结点？ 
				无。输出当前结点的数据。是否有右结点。有则压入右结点。
				有。是否有右结点，有则压入右结点。
					->左结点是否为叶子结点？(判断条件，左右指针皆为NULL则为叶子结点。) 
						是，输出叶子结点的数据。再输出当前结点数据。 
						否，（当前结点入栈，同时当前结点更新为左结点(入栈）。再循环。） 

	(2) *181210* 参考代码
		
	代码非常简洁。大循环（即遍历何时结束）的条件考虑了两个：栈是否为空，或当前结点是否空。（通常，反正我不能直接想到，而这恰恰是思路的关键之一，不然就如上述第一次想的思路），第二点，是中序遍历的思路跟先序差别在，入栈顺序是先根节点，然后left,再right。利用栈和循环的巧妙结合。
	
	基本逻辑：

	1)当前结点不为空，则先压入。再更新当前结点为左孩子结点。
	
	2)当前结点为空，则取栈顶指针，保存数据。再弹出栈顶。当前结点更新为右结点。

	
2. 用Morris算法	
	
	
	

### 代码
1. 见[solution.h](https://github.com/rensandao/LeetCode/blob/master/094%20Binary%20Tree%20Inorder%20Traversal/solution.h)

### 知识点
* morris算法
	[参考1](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html)    [参考2](https://www.jianshu.com/p/484f587c967c)   [参考3](https://stackoverflow.com/questions/6478063/how-is-the-time-complexity-of-morris-traversal-on)
