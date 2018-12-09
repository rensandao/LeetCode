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

181209

1. 树的遍历是怎么样的？可以图示演绎。

答: 遍历的定义是什么? 百度百科：所谓遍历，是指沿着某条搜索路线，依次对树中每个结点均做一次且仅做一次访问。

树的遍历分为三种：以根节点相对位置，分为先序、中序和后序。 

1.1 常用的遍历算法用的是递归，那么递归时间空间复杂度是多少？有什么不足的吗？ 

2. 想想栈的定义及相关性质及应用，能不能直接想到或挖掘到什么信息？
	
	没有的话，从头开始看栈的知识点；
	
	有的话，有哪些? 
	
	1) 栈的一个性质是先进后出FILO，这个性质可以用来处理顺序的问题。 
	
	2) 标准库中栈的类<stack>,类成员函数之一std::stack::top，是指向栈顶元素的指针。
	   
	   实际上top()是调用底层容器的back函数的结果，即指针。 
   

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

* Morris遍历181123

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur_node = root, *prev_node;
        
        while(cur_node != NULL){
            if(cur_node->left == NULL){
                result.push_back(cur_node->val);
                cur_node = cur_node->right;                
            }
            else{
                //寻找cur_node的前驱结点
                prev_node = cur_node->left;
                while(prev_node->right != NULL && prev_node->right != cur_node)
                    prev_node = prev_node->right;
                
                if(prev_node->right == NULL){
                    result.push_back(cur_node->val);
                    prev_node->right = cur_node;
                    cur_node = cur_node->left;                    
                }
                //表示prev_node->right == cur_node;
                else{
                    //表明之前已经生成线索,则删除线索
                    //result.push_back(cur_node->val);
                    prev_node->right = NULL; // 如果不设置为NULL，则循环不能继续
                    cur_node = cur_node->right;                                      
                }                   
            }
        }  
        return result;
    }
};
```


### 知识点
* 熟悉树和栈的定义、性质、作用和ADT等.
* 树的遍历：广度优先（BFS）和深度优先(DFS)
* 二叉树的遍历：前中后序
* 结构体指针
