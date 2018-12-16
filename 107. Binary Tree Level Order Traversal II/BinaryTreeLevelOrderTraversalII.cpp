/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-15
****************************************************************/ 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // std::reverse()
using std::vector;
using std::reverse;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 /*
 181215
 思路1：迭代法。如果用继续用队列queue的方式，行不行。

*/




 /*
 181215
 思路2：在递归方法的基础上， 利用reverse，把从上到下顺序结果颠倒，即为结果。 
 */
//using
//method2
vector<vector<int>> levelOrderBottom(TreeNode *root) {
	if (!root)  return {};
	vector<vector<int>> res;
	if (root)  FindLevelOrder(root, 1, res);
	reverse(res.begin(), res.end());
	return res;
}

void FindLevelOrder(TreeNode *node, int level, vector<vector<int>> &res) {
	if(res.size() < level)  res.emplace_back(vector<int>());
	res[level-1].emplace_back(node->val);

	if(node->left) FindLevelOrder(node->left, level+1, res);
	if(node->right) FindLevelOrder(node->right, level+1, res);
}

/*
思路3：

*/





