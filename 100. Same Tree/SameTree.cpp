/****************************************************************
source: https://github.com/rensandao/LeetCode/edit/master/100.%20Same%20Tree/SameTree.cpp
Author: rensandao
First Creation: 2018-12-19
****************************************************************/ 
#include <stack>
//#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
/*
181219
思路1： 双栈。
怎么分析？
数据结构用什么？

时间复杂度：
空间复杂度：
Runtime:4ms
*/
//Same Tree
//method1. 
bool isSameTree1(TreeNode *p, TreeNode *q) {
	stack<TreeNode*> st1, st2;
	st1.push(p); st2.push(q);

	while (!st1.empty()) {
		TreeNode *c1, *c2;
		c1 = st1.top(); st1.pop();
		c2 = st2.top(); st2.pop();
		//这几个条件要周密
		if (!c1 && !c2)  continue;
		if (!c1 || !c2)  return false;
		if(c1->val != c2->val) return false;

		//不能加if(c1->left)
		st1.push(c1->left);
		st1.push(c1->right);

		st2.push(c2->left);
		st2.push(c2->right);
	}
	return true;        
}

/*
181219
思路2：递归。
判断条件严谨是重点。
*/
//method2.
bool isSameTree2(TreeNode *p, TreeNode *q) {
	if(!p && !q) return true;  
	if(!p || !q) return false;  
	return (p->val == q->val) && isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
}
