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
思维的出发点可以考虑下先序遍历，因为先序和后续遍历顺序中，都是先left或right。那么入栈的顺序也应该都是先压右孩子结点，在左孩子结点。
接下来核心的还是边界条件的确定问题：
1.入栈出栈操作针对的，都是当前结点，从根节点开始。再更新。
2.当前结点是从根结点开始，再每个子根结点。根节点的输出顺序规定是在最后输出。那么输出的条件是：当前结点是叶子结点。这是能想到的一个点。
3.




*/
class solution {
public:
   vector<int> postorderTraversal(TreeNode* root){
    
    
   }
};
