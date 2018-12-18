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

//Morris算法
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root, *prev = NULL;
				
        
        
            
        return res;   
    }
};
