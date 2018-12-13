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

/*
思路2：
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
//postorder traversal using stack
//method2
vector<int> postorderTraversal2(TreeNode* root) {
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

/*
思路3：
1.利用容器vector的操作方法insert来找解法。
后序遍历顺序依次为：left，right，root。我们在先序遍历时体会到了几行代码的简洁性：
	先push_back根节点，再弹出栈。再压右-左孩子结点。 
这里就可以先把根节点数据直接先存入vector中。vector的push_back是末端插入。
我们在保存的时候，可以其将左右孩子的结点数值，通过插入vector首端，变相地完成排序输出。所以严格地说，
这种方法是【栈+insert】.

insert时间消耗：插入首位O(1)，vector其他数据相应全部都要后移一位。空间就多了一位。 
栈时间空间复杂度为：O(n) 
*/
//postorder traversal using stack. 
//method3 
vector<int> postorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	st.push(root);

	while (!st.empty()) {
		TreeNode *temp = st.top();
		st.pop();
		res.insert(res.begin(), temp->val);

		if(temp->left)  st.push(temp->left);
		if(temp->right)  st.push(temp->right);	
	} 
	return res;
}

/*
思路4：还是利用先序遍历另一种方法（辅助结点）的基础上+insert()方法
先序另一种方法：
*/
//postorder traversal using stack
//method4
vector<int> postorderTraversal4(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	st.push(root)
	
	


	return res;
}

/*
思路5：

*/
//postorder traversal using stack
//method5















