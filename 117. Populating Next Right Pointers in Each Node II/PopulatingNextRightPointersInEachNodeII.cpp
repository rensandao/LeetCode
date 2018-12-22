/**************************************************
Source:
Author: rensandao
First Creation: 2018-12-23
***************************************************/
//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


/*
181223
思路1：递归

*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
    }
};

/*
181223
思路2：迭代。层序遍历（BFS）用queue
*/

/*
181223
思路3：迭代。O(1)空间解法。
*/
