/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-08

Code format and structure reference: 
https://github.com/pezy/LeetCode/blob/master/093.%20Binary%20Tree%20Inorder%20Traversal/solution.h
Algorithm reference:
PDF-> https://github.com/soulmachine/leetcode 
****************************************************************/
#include<vector>
#include<stack>
using namespace std; // std::vector, std::stack

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//用栈
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *temp = root;
        
        while (!st.empty() || temp != nullptr ) {
            if(temp != nullptr){
                st.push(temp);
                temp = temp->left;
            }
            else{
                temp = st.top();
                res.push_back(temp->val);
                st.pop();
                
                temp = temp->right;            
            }           
        }     
        return res;   
    }
};

/*
181218
Morris算法
morris算法类似于线索二叉树。利用结点指针，解决前驱结点回到根结点（当前结点）时的指向问题。从而也实现空间复杂度O(1)。

算法步骤：
判断当前结点是否有左孩子结点。
1.若无，则输出当前结点，同时当前结点更新为右孩子结点。
2.若有左孩子结点，找到当前结点在中序遍历情况下的前驱结点：
	a. 前驱结点的右孩子为空，则其右孩子设为当前结点；当前结点在更新为左孩子结点；
	b. 前驱结点的右孩子不为空（说明已经建立连接了），则右孩子设置为空（恢复了二叉树原貌），当前结点更新为当前结点的右孩子结点。
3.如此循环。

Reference:
https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
*/
//mehtod2. inorder traversal using morris algorithm.
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root, *prev = NULL;
		
		while (cur != NULL) {
			if (cur->left == NULL) {
				res.push_back(cur->val);
				cur = cur->right;				
			} else {
				prev = cur->left;
				while ( prev->right != NULL && prev->right != cur) 
					prev = prev->right;
				
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				} else {
					prev->right = NULL;
					res.push_back(cur->val);
					cur = cur->right;		
				}
			}
		}           
        return res;   
    }
};
