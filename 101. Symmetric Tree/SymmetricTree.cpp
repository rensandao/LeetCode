/****************************************************************
source: https://github.com/rensandao/LeetCode/new/master/101.%20Symmetric%20Tree
Author: rensandao
First Creation: 2018-12-20
****************************************************************/ 
struct TreeNode{
	ElemType val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(size_t x): val(x), left(NULL), right(NULL){}	//initialization
};

/*
181220
题干提示：递归和迭代两种方式。

*/
class Solution {
public:
	
/*
181220
思路1：递归。
递归的本质是将问题分解成两个或者多个小问题，那么首先便先要找出这个最小问题及其解。再利用递归调用。
首先最小问题是什么？称之为问题核。
答：在二叉树的结构上找突破口。求对称性：
1）整体上，左侧与右侧同一层上的结点，左侧的某个结点的左孩子对应右侧对应结点的右孩子。
2）对应的结点的确定，源头是从根节点root开始，root到第二层root->left和root->right,但是实际第二层并不能满足这个【问题核】的要素，必要要考虑第三层，
在第二层到第三层之间，一个结点有两个子结点，这才有了普遍性，可利用性。也就是问题核的解的重利用-递归。

判断对不对称所有的可能性:
	a.root-left.val == root->right.val,
	b.left和right如果都为空，但因为没有结点数据不用比较数值，则继续；
	c.left和right如果有一个不为空，则说明不对称，返回false。
	d.剩下的是有结点数据的情况，判断a条件成不成立，如果不成立，则返回false；如果成立，则返回true，这个时候开始要进入下一层各自的对称结点，
	考虑使用递归调用了。
*/
	//recursive
    bool isSymmetric(TreeNode *root) {
        
        if (!root)  return true;
        if (!root->left && !root->right)  return true;
        if (!root->left || !root->right)  return false;
        
        return isSymmetricHelp(root->left, root->right);            
    }
    
    bool isSymmetricHelp(TreeNode *node1, TreeNode *node2) {
        
        if (!node1 && !node2)  return true;
        if (!node1 || !node2)  return false;
        return (node1->val == node2->val)  
                && isSymmetricHelp(node1->left, node2->right)
                && isSymmetricHelp(node1->right, node2->left);
    }
	
/*
181220
思路2.1：迭代。采用单栈或双栈,DFS遍历。思路分析参考思路1中的分析点。仍需要注意的是判断不对称的条件的严谨性。
*/
	//iterative
	bool isSymmetric2(TreeNode *root) {
        stack<TreeNode*> st1, st2;
        
        if (!root) return true;
        if (!root->left && !root->right)  return true;
        
        st1.push(root->left);
        st2.push(root->right);
        
        while (!st1.empty() && !st2.empty()) {
            TreeNode *node1, *node2;
            node1 = st1.top();  st1.pop();
            node2 = st2.top();  st2.pop();
            
            if (!node1 && !node2)  continue;
            if (!node1 || !node2)  return false;
			
            if (node1->val != node2->val)  return false;
            st1.push(node1->left);  st1.push(node1->right);
            st2.push(node2->right);  st2.push(node2->left);
        }
        return true;
    }

/*
思路2.2： 迭代。采用单queue或双queue。对二叉树进行层序遍历比较（即BFS）。整体思路与采用双栈相似。可参考repo：
Reference: 
https://github.com/haoel/leetcode/blob/master/algorithms/cpp/symmetricTree/symmetricTree.cpp
*/	
	
};
