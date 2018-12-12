#include <vector>
#include <stack>

using std::vector;
using std::stack;

//Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//#1 postorder traversal using stack
/*
思路1：
思维的出发可以对比先序遍历，因为先序和后续遍历顺序中，都是先left或right。那么入栈的顺序也应该都是先压右孩子结点，在左孩子结点。

*/
class solution {
public:
   vector<int> postorderTraversal(TreeNode* root){
    
    
   }
};
