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
 思路1：参考102. Binary Tree Level Order Traversal
 迭代法。如果用继续用队列queue的方式，行不行。
 (1)queue
 	还是利用vector的insert方式，从上到下层，每一层保存的vLevel插入到容器的首段。
	时间复杂度：
	空间复杂度：
	runtime: 8ms, 16.84%faster.
 (2)用deque也一样。 略。
*/
//Iteration mind. Binary tree level order tarversal.
//method1
vector<vector<int> > levelOrderBottom1(TreeNode *root) {
        if(!root) return {};
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);	

        while(!q.empty()){
            vector<int> vLevel;
            int vLength = q.size(); 
            for (int i=0; i<vLength; i++) {
                TreeNode *temp = q.front();
                q.pop();
                vLevel.push_back(temp->val);

                if (temp->left)  q.push(temp->left);
                if (temp->right)  q.push(temp->right);	
            }
            res.insert(res.begin(), vLevel);		
        }
        return res;
    }

 /*
 181215
 思路2：递归。参考题102. Binary Tree Level Order Traversal
 在递归方法的基础上， 利用reverse，把从上到下顺序结果颠倒，即为结果。
 时间复杂度：O(n)
 空间复杂度：O()
 running time: 4ms, 98.83%faster
 */
//recusive mind.
//method2
vector<vector<int> > levelOrderBottom(TreeNode *root) {
	if (!root)  return {};
	vector<vector<int> > res;
	if (root)  FindLevelOrder(root, 1, res);
	reverse(res.begin(), res.end());
	return res;
}

void FindLevelOrder(TreeNode *node, int level, vector<vector<int> > &res) {
	if (res.size() < level)  res.emplace_back(vector<int>());
	res[level-1].emplace_back(node->val);

	if (node->left)  FindLevelOrder(node->left, level+1, res);
	if (node->right)  FindLevelOrder(node->right, level+1, res);
}

/*
思路3：

*/





