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
思路1：迭代，类Morris。
1）我们可以从所给的例子推理，结点2要变成结点1的右结点，3要接到2后面。这可以通过赋值root->right实现。但是问题是，如果直接改变，那各个root的右结点
怎么办，不就断了线索了嘛。所以在操作之前得先把这些后面的值要连接到其前面的结点才行。
2）也就是如下图，结点5要先连接到结点4后，这时候结点1空了，便可以将结点2接到1的右侧；同理，对于结点4和3也是，4接到3后，3再接到2后。如此循环。
     1					    1                   1                      1             1
	/ \					   / \                   \                      \             \   
   2   5		=>		  2           =>          2           =>         2       =>    2
  / \   \				 / \                     / \                    / \             \
 3  4    6				3   4                   3   4                   3                3
							 \                       \                   \                \
							  5                       5                   4                4
							   \                       \                   \                \
								6                       6                   5                5
												                             \                \
													                          6				   6			
                                                     
3）这让我想到了前序遍历morris算法思想，可以应用其代码逻辑结构。不过这里写出来会简单些。

时间复杂度：O(n)
空间复杂度：O(1)
Runtime: 8ms, 53.80% faster.
*/
//method1. Flatten binary tree to linked list tree iteratively.
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curNode = root, *preNode;
        while (curNode != nullptr) {
            if (curNode->left == nullptr) {
                curNode = curNode->right;                
            } else {
                preNode = curNode->left;
                while (preNode->right != nullptr)  preNode = preNode->right;
                
                preNode->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = nullptr;
                curNode = curNode->right;   
            } 
        }
    }
};

/*
181222
思路2：对称思维
因为是先序遍历，那考虑方便，直接全部放在坐边。最后再统一换到右结点。实现方法利用stack先序遍历，存放各个结点指针到vector中，再统一更换关系。
但明显，这里既用到stack，又有vector。

  	1                    
   / \                 
  2   5         =>     1-2-3-4-5-6       
 / \   \              
3   4   6            

时间复杂度：
空间复杂度：O(n+logn)
Runtime: 12ms. 18.72% faster.
*/
//method2. 
class Solution {
public:
    void flatten(TreeNode* root) { 
        if (!root) return;
        vector<TreeNode*> vec;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *temp = st.top();
            st.pop();
            vec.push_back(temp);
            
            if (temp->right)  st.push(temp->right);
            if (temp->left)  st.push(temp->left);           
        }  
        
        vec.push_back(nullptr);
        for (int i=0; i<vec.size(); i++) {
            if(vec[i]) {
                vec[i]->right = vec[i+1];
                vec[i]->left = nullptr;                
            }       
        }
    }
};

/*
181222
思路3：递归思想，八字形。左子树捋顺了，右子树捋顺了，再最后操作。
*/


