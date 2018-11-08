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
考察二叉树遍历：先根遍历。基本技能：熟悉树和栈的ADT.
* recursive solution
* Iterative solution using stack
* Morris traversal


### 代码
* 使用栈进行迭代
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
        poping, left goes first and then the right. The problem sovled.    
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





### 知识点
* 二叉树的遍历
