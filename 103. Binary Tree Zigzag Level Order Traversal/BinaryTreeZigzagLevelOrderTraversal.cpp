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
思路1：递归法。认为更易思考，先写。整体思路借鉴102. Binary Tree Level Order Traversal中思路2。改动地方在，奇数层（1-3-5...）数据
用push_back末端压入容器。而偶数层（2-4...）用insert是的该层数据逆向保存在容器中。从而整体实现zigzag这种S形输出结果。

时间复杂度：O()
空间复杂度：O()
runtime: 4ms, 47.54%faster.
*/
//zigzag level order traversal using 
//method1
vector<vector<int>> zigzagLevelOrder1(TreeNode *root) {
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
思路2：迭代方法+static 标记（也是用于判别层数，再确定插入方式）。

时间复杂度：
空间复杂度：
Runtime: 
*/
//method2. 
vector<vector<int>> zigzagLevelOrder2(TreeNode *root) {
	vector<vector<int>> res;
	if(!root) return res;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		vector<int> levelVec;
		static int t=1; 
		int vLength = q.size();
		for (int i=0; i<vLength; i++) {
			TreeNode *temp = q.front();
			q.pop();
			if(t%2==1) {
				levelVec.push_back(temp->val);
			}  else {
				levelVec.insert(levelVec.begin(), temp->val);
			}

			if (temp->left)  q.push(temp->left);
			if (temp->right)  q.push(temp->right);
		}
		res.push_back(levelVec);
		t++;
	}	
	return res; 
} 

/* 
181217
对方法2的小技巧调整:
上述思路1、2中的vector插入方式都用到insert()方法，强调的是在单个元素插入时就确定位置；也可以采用整体reverse()的方法，比如将从左右正序插入
完的vector反转。

时间复杂度：
空间复杂度：
Runtime: 4ms, 47.54%faster.
*/
//method3
vector<vector<int>> zigzagLevelOrder3(TreeNode *root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
	bool isLR = false;  //在这里设置标志
	
    while (!q.empty()) {
        vector<int> levelVec;
        
        int vLength = q.size();
        for (int i=0; i<vLength; i++) {
            TreeNode *temp = q.front();
            q.pop();
            
            levelVec.push_back(temp->val);
            
            if (temp->left)  q.push(temp->left);
            if (temp->right)  q.push(temp->right);
        }
        if(isLR) reverse(levelVec.begin(), levelVec.end()); //隔一层的vector先反转，再压入大vector中。
        res.push_back(levelVec);
		isLR = !isLR; //每一层结束，标志取反。		
    }	
    return res; 
}




