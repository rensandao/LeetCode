/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-15
****************************************************************/ 
#include <iostream>
#include <vector>

using std::vector;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 /*
 181215
 思路1：如果用继续用队列的方式，行不行

*/




 /*
 181215
 思路2：在递归方法的基础上， 利用vector的操作insert，每一层的vector插入到首段之前。
 
 */
//using
//method2
vector<vector<int>> levelOrderBottom1(TreeNode* root) {
	vector<vector<int>> res;
		

}

vector<int> FindLevelOrder(TreeNode *node, int level, vector<vector<int>> &res) {


}

/*
思路3：

*/





