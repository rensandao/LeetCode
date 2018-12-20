/**************************************************
Source:
Author: rensandao
First Creation: 2018-12-20
***************************************************/
//Definition for a binary tree node.
struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

/*
181220
思路1：递归。
平衡二叉树的定义：a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
即任意结点的两个子树的高度差不超过1.

辅助高度记录L1,L2。
*/
    bool isBalanced(TreeNodeb *root) {
       return isBalancedHelp(root) >= 0;
       
    }
	
	int isBalancedHelp( TreeNode *root)
	
	
};
