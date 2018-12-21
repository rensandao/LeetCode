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

/*
181220
思路1：递归。
平衡二叉树的定义：a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
即任意结点的两个子树的高度差不超过1.

辅助高度记录L1,L2。?

时间复杂度：
空间复杂度：
Runtime:

*/
class Solution1 {
public:
    bool isBalanced(TreeNodeb *root) {
       if(!root) return true;
	   if (abs(nodeDepth(root->left) - nodeDepth(root->right) >1) return false;
	   return isBalanced(root->left) && isBalanced(root->right);       
    }
private:	   		   
    int nodeDepth(TreeNode *root) {
		if (!root) return 0;
		return 1 + max(nodeDepth(root->left), nodeDepth(root->right));
	}	   
};

           
/*
181221
思路2：对思路1递归方法的改进

*/	
class Solution2 {
public:
    bool isBalanced(TreeNodeb *root) {
       if(!root) return true;
	   if (abs(nodeDepth(root->left) - nodeDepth(root->right) >1) return false;
	   return isBalanced(root->left) && isBalanced(root->right);       
    }
private:	   		   
    int nodeDepth(TreeNode *root) {
		if (!root) return 0;
		return 1 + max(nodeDepth(root->left), nodeDepth(root->right));
	}	   
};	   
		   
