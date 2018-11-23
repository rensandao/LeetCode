### 描述
```
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
```

### 思路

181108 

考察二叉树的遍历问题。首先要对树和二叉树的概念要了解。其次对于树的抽象数据类型要知道怎么代码实现，比如树的存储结构问题。


* 递归解法


* 迭代解法（使用栈）
  

* Morris遍历
   
   Morris实现的机理类似于线索二叉树。


### 代码
* 使用栈进行迭代 181108
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        /*
        Iterative solution using stack method.
        The function of stack is store the pointer value temporarily,
        and deal with left and right child tree order.
        For preorder, we wish to print the sort result from the root to left tree, 
        and the right tree last.
        So with stack, we can push right child pointer first and then left one. When
        poping, left goes first and then the right. The problem solved.    
        */
        
        stack<const TreeNode*> stack;
        vector<int> result;
        /* if(root != NULL)   空指针是什么的？NULL表示法 null? */
        if(root) stack.push(root); 

        while(!stack.empty()){
            const TreeNode* temp = stack.top();
            stack.pop();
            result.push_back(temp->val);

            if(temp->right)  stack.push(temp->right);
            if(temp->left)   stack.push(temp->left);
        }	
        return result;
    }
};
```

* Morris遍历

```
void preorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                printf("%d ", cur->val);  // the only difference with inorder-traversal
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}
```






### 知识点
* 熟悉树和栈的定义、性质、作用和ADT等.
* 树的遍历：广度优先（BFS）和深度优先(DFS)
* 二叉树的遍历：前中后序
* 结构体指针
