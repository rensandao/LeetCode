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


/*********************************************************1*************************************************************************
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
***********************************************************1*************************************************************************/
//method1. Flatten binary tree to linked list tree iteratively.
class Solution1 {
public:
    void flatten(TreeNode *root) {
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


/**********************************************************2*************************************************************************
181223
思路2：对称思维,属于迭代。
因为是先序遍历，那考虑方便，直接全部放在坐边。最后再统一换到右结点。实现方法利用stack先序遍历，存放各个结点指针到vector中，再统一更换关系。
但明显，这里既用到stack，又有vector。

  	1                    
   / \                 
  2   5         =>     1-2-3-4-5-6       
 / \   \              
3   4   6            

时间复杂度：
空间复杂度：
Runtime: 12ms. 18.72% faster.
***********************************************************2************************************************************************/
//method2. 
class Solution2 {
public:
    void flatten(TreeNode *root) { 
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


/***********************************************************3*************************************************************************
181224
思路3：对思路2的改进，也属于迭代。参考PDF，https://github.com/soulmachine/leetcode
思路2是利用栈进行先序遍历，遍历的结点指针存在专门的容器内，再统一一次性操作。
这里可以巧妙利用栈的进出，在遍历过程中实现变换。
************************************************************3*************************************************************************/
//method3. Iterative flattenning.
class Solution3 {
public:
    void flatten(TreeNode *root) { 
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *temp = st.top();
            st.pop();
                      
            if (temp->right)  st.push(temp->right);
            if (temp->left)  st.push(temp->left);  
			
			//下面两行代码很巧妙，避免使用方法2中的vector
			temp->left = nullptr;
			while(!st.empty()) 	temp->right = st.top();  //condition
        }  
    }
};


/************************************************************4*************************************************************************
181223
思路4：递归思想，八字形。找到最小的[问题核]，一般分析到第3层。

时间复杂度：
空间复杂度：
Runtime: 12ms, 同上。
**************************************************************4***********************************************************************/
//recursive1 
class Solution4 {
public:
    void flatten(TreeNode *root) { 
        if (!root)  return;    //layer1->2
		flatten(root->left);
		flatten(root->right);
		
		if (!root->left)  return;  //caution. layer2->3
		TreeNode *temp = root->left;
		while (temp->right != nullptr)  temp = temp->right;
		
		temp->right = root->right;
		root->right = root->left;
		root->left = nullptr;
    }
};


/***********************************************************5*************************************************************************
181224
思路5：递归
TC:
SC:
Runtime:
************************************************************5************************************************************************/
class Solution5 {
public:
    void flatten(TreeNode *root) { 
      
		
    }
};

