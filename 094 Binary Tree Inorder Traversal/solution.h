/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-08

Code format and structure reference: 
https://github.com/pezy/LeetCode/blob/master/093.%20Binary%20Tree%20Inorder%20Traversal/solution.h
Algorithm reference:
PDF-> https://github.com/soulmachine/leetcode 
****************************************************************/
#include<vector>
#include<stack>
using namespace std; // std::vector, std::stack

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//181208
//用栈
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *temp = root;
        
        while (!st.empty() || temp != nullptr ) {
            if(temp != nullptr){
                st.push(temp);
                temp = temp->left;
            }
            else{
                temp = st.top();
                res.push_back(temp->val);
                st.pop();
                
                temp = temp->right;            
            }           
        }     
        return res;   
    }
};

/*
181218
Morris算法
morris算法类似于线索二叉树。利用结点指针，解决前驱结点回到根结点（当前结点）时的指向问题。从而也实现空间复杂度O(1)。
线索二叉树的叶子结点有多少个,则有2倍数的空闲指针未利用。

			 6
			/ \
		   2   7
		  / \   \
         1  4    9
           / \  /   
           3 5  8
算法思想：
先一分为二思想，左子树和右子树。没有左子树则直接输出当前结点并进入右子树。这是一条逻辑。

若有左子树，则在其左子树中找到根结点(root)的前驱（predecessor)，建立线索关系以备
后用。然后从当前根节点收缩到左子树头节点(left)。这是一条逻辑。

而接上条逻辑，要考虑的是当遍历当前的结点又来到了我们之前建立了线索关系那一对中的前驱结点时情况，这也说明：
	1.其左侧的结点均已遍历并输出；
	2.该结点本为叶子结点，但因为之前已经将其右孩子结点与起后驱结点建立线索关系，便很自然地可以放心将自己输出，再更新为线索指向的结点。
	3.但似乎忘了一件事，就是要顺带将这条线索给撤销掉。为什么?一个是本身加入线索已经改变原来二叉树的结构，对于其他的操作会带来潜在问题。
---------------------------------------------------
具体步骤：
判断当前结点是否有左孩子结点。
1.若无，则输出当前结点，同时当前结点更新为右孩子结点。
2.若有左孩子结点，找到当前结点在中序遍历情况下的前驱结点：
	a. 前驱结点的右孩子为空，则其右孩子设为当前结点；当前结点在更新为左孩子结点；
	b. 前驱结点的右孩子不为空（说明已经建立连接了），则右孩子设置为空（恢复了二叉树原貌），当前结点更新为当前结点的右孩子结点。
3.如此循环。
----------------------------------------------------
时间复杂度：  n个结点，n-1条路径，每条路径最多访问2次。一次是为了创建与某个前驱之间的线索，一次是当前结点的更新定位。还是为O（n）。
空间复杂度： 只用到两个指针，没有申请新的内存，故为O（1）。

Reference:
https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
https://www.jianshu.com/p/484f587c967c
*/
//mehtod2. inorder traversal using morris algorithm.
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *current = root , *prevNode = NULL;
        
        while (current != NULL) {
            //1.若当前结点左孩子节点left为NULL
            if (current->left == NULL) {
                res.push_back(current->val);
                current = current->right; 
            } else {
                prevNode = current->left;
                while (prevNode->right != NULL && prevNode->right != current) {
                    prevNode = prevNode->right;                    
                }
                if (prevNode->right == NULL) {
                    prevNode->right = current;
                    current = current->left;                
                } else {
                    //说明之前的线索已建立，可输出结点；
                    //线索要删除，不然二叉树的结构一直处于被改变的状态，对于其他的操作会造成错乱。
                    prevNode->right = NULL;
                    res.push_back(current->val); 
                    current = current->right;                                     
                }               
            }  
         }
        return res;
    }
};
