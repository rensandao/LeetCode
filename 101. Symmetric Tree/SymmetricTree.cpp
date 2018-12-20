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
	
	//思路1：递归。
	/*
	181220
	递归的本质是将问题分解成两个或者多个小问题，那么首先便先要找出这个最小问题及其解。再利用递归调用。
首先最小问题是什么？称之为问题核。
答：在二叉树的结构上找突破口。求对称性：
1）整体上，左侧与右侧同一层上的结点，左侧的某个结点的左孩子对应右侧对应结点的右孩子。
2）对应的结点的确定，源头是从根节点root开始，root到第二层root->left和root->right,判断所有的可能性。
	a.root-left.val == root->right.val,
	b.left和right如果都为空，但因为没有结点数据不用比较数值，则继续；
	c.left和right如果有一个不为空，则说明不对称，返回false。
	d.剩下的是有结点数据的情况，判断a条件成不成立，如果不成立，则返回false；如果成立，则返回true，这个时候开始要进入下一层各自的对称结点，
	考虑使用递归调用了。
	
	
	*/
    bool isSymmetric1(TreeNode *root) {
         
		
        
        
    }
	
	//思路2：迭代。
	bool isSymmetric2(TreeNode *root) {
	
	
	}
	
};
