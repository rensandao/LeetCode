/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-16
****************************************************************/ 
#include<vector>
using std::vector;

//Definition for a binary tree node.
struct TreeNode{
	ElemType val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(size_t x): val(x), left(NULL), right(NULL){}	
};

/*
181218
思路1：
1)题目的意思是将原树的数据按照左-根-右的顺序从小到大重新组织，同时原树的结构不变；
2）考虑用什么数据结构？循环的条件是什么？ 
3）时间、空间复杂度？

先想到大体方向是，
排序->若1.两两交换,空间O(1) 
	  若2.重建，空间O(n)
	  所以，要用交换或更换的某种方式；
那么用什么数据结构？一般用栈或者队列，或者之前链表。

考虑用栈的话，空间用到还是会需要O(n)的。唯一能实现O(1)空间的最可能是链表。
在树的前中后序遍历实现上，能够达到空间O(1)的算法叫 Morris算法。之前看了一点，但没有全部实现，正好现在又碰上了。索性一起解决了。


时间复杂度：
空间复杂度：O(1)
Runtime: 
*/
//method1
//recovery binary search tree using ...
void recoverTree1(TreeNode *root) {
        
}


/*
思路2：


时间复杂度：
空间复杂度：
Runtime: 
*/
//method2
//recovery binary search tree using ...
void recoverTree2(TreeNode *root) {
        
}





