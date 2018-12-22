/**************************************************
Source:
Author: rensandao
First Creation: 2018-12-22
***************************************************/

/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
//Definition for a binary tree node.
struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
181222
思路1：类Morris。
1）我们可以从所给的例子推理，结点2要变成结点1的右结点，3要接到2后面。这可以通过赋值root->right实现。但是问题是，如果直接改变，那各个root的右结点
怎么办，不就断了线索了嘛。所以在操作之前得先把这些后面的值要连接到其前面的结点才行。
2）也就是
     1						1                       
	/ \					   / 
   2   5		=>		  2   
  / \   \				 / \   
 3  4    6				3   4   
							 \
							  5
							   \
								6


    1                       
   / \
  2   5
 / \   \
3   4   6

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        
		
		
    }
};

/*
181222
思路2：对称思维
因为是先序遍历，那考虑方便，直接全部放在坐边。


*/
