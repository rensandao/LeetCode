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
但如果不是叶节点呢，那么操作正常的操作是参考先序遍历，先压右孩子结点（如果有的话），再左孩子结点（如果有的话）。
那么，根据1和2条件大概写出下述代码初稿：
```
temp = st.top();
if(!temp->left && !temp->right) {
	res.push_back(temp->val);
	st.pop();
	
} else {
	if(temp->right) st.push(temp->right);
	if(temp->left) st.push(temp->left);

}
```
		5
	   / \
	  3   4
	 / \
	1   2

3.我们做一次演绎试图验证严谨性，但是到了叶子结点为1时，开始输出，有问题了：
此时2和1依次压入栈，当前结点更新为1的位置，保存数据，栈顶指针出栈，结点2再保存数据，栈顶指针出栈。轮到结点3，陷入了重复。不能进入条件，
从而不能保存结点3数据。
这时候判别的仍是左右孩子结点，而左右孩子结点已经保存了数据，同时弹出。对这个问题解决应该怎么解决？
答：设置限制条件：判断当前结点的左右孩子结点是否等于之前刚刚弹出来的栈顶结点，以确定前面的结点都已经保存过了，该轮到自己了。

*/
class solution {
public:
   vector<int> postorderTraversal(TreeNode* root) {
       if (!root)  return{};
	   vector<int> res;
	   stack<TreeNode*> st;
	   st.push(root);
	   TreeNode *prev_node = root;
	   while (!st.empty()) {
		   TreeNode *temp = st.top();
		   if ((!temp->left && !temp->right) || temp->left == pre_node || temp->right == pre_node) {
			   res.push_back(temp->val);
			   st.pop();
			   prev_node = temp;		   
		   } else {
			   if (temp->right)  st.push(temp->right);
			   if (temp->left)  st.push(temp->left);
		   }
	   }
	   
	   return res;
   }
};
