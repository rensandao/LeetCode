/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-16
****************************************************************/ 
#include <vector>
#include <queue>
using std::vector;
using std::queue;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
181216
思路1：递归法。整体思路借鉴102. Binary Tree Level Order Traversal中思路2。改动地方在，奇数层（1-3-5...）数据用push_back末端压入容器。
而偶数层（2-4...）用insert是的该层数据逆向保存在容器中。从而整体实现zigzag这种S形输出结果。
*/
//zigzag level order traversal using 
//method1
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
	if (!root)  return {};
	vector<vector<int>> res;
	if (root)  FindLevelOrder(root, 1, res);

	return res;
}

void FindLevelOrder(TreeNode *node, int level, vector<vector<int>> &res) {
	if (res.size() < level)  res.emplace_back(vector<int>());
	if (level%2 ==1) {
		res[level-1].emplace_back(node->val); 
	} else {
		res[level-1].insert(res[level-1].begin(), node->val);            

	}

	if (node->left) FindLevelOrder(node->left, level+1, res);
	if (node->right) FindLevelOrder(node->right, level+1, res);
}

/*
181216
思路2：

*/




