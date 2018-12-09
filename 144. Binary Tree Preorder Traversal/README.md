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

1.树的遍历是怎么样的？可以图示演绎。

	答：遍历的定义是什么? 百度百科：所谓遍历，是指沿着某条搜索路线，依次对树中每个结点均做一次且仅做一次访问。
	
	树的遍历策略可以从整体上按照：优先从上到下或者优先从左到右。 专业名词叫：深度优先搜索(DFS)、广度优先搜索(BFS)
	
	其中深度优先遍历又可以分为三种，就是我们通常所说的：先序、中序和后序。（以根结点相对左右孩子的先、中、后的遍历顺序划分） 

1.1 常用的遍历算法用的是递归，那么递归时间空间复杂度是多少？有什么不足的吗？ 

	复杂度分析：
	
	 O(n*logn)  线性对数  如何推导呢？？ 
	
	算法优点：
	
		1）简洁。二叉树前中后序遍历算法中，递归的实现明显要比循环简单得多。
		
	缺点：
		1）递归由于是函数调用自身，而函数调用是有时间和空间消耗的，每一次函数调用，都需要在内存栈中分配空间
		以保存参数、返回地址以及临时变量，而往栈中压入数据和弹出数据也同样都需要时间。-->效率 
		
		2）递归中很多计算都是重复的，由于其本质是把一个问题分解成两个或者多个小问题，多个小问题若存在相互重叠的部分，
		则存在重复计算，如Fibonacci斐波那契数列的递归实现。-->效率
		
		3）调用栈可能会溢出，每一次函数调用会在内存栈中分配空间，而每个进程的【栈的容量】是有限的，当调用次数太多时，
		会超出栈的容量，从而导致栈溢出。-->性能（安全性） 
	
	综上分析，可以采用别的算法来改进。 
	
	那么，如何想到利用栈？morris? 

2.想想栈的定义及相关性质及应用，能不能直接想到或挖掘到什么信息？

	没有的话，从头开始看栈的知识点；
	
	有的话，有哪些? 
	
	1) 栈的一个性质是先进后出FILO，这个性质可以用来处理顺序的问题。有时候挺巧妙。
	
	2）标准库中栈的类<stack>,类成员函数之一std::stack::top，是指向栈顶元素的指针。实际上top()是调用底层容器的
	
	back函数返回值，即指针。 
	
					   
	若采用栈的话，那么第一点是利用栈的FILO实现二叉树的先中后序的顺序问题；第二，压入或者弹出的数据是结点的指针。
	
	因为本身树的结构定义了各结点通过指针来关联。关键在算法的逻辑怎么组织了。   

         1
        / \
       2  5    
      /\ 	
     3 4

	先序算法：
	
	1.大循环条件是什么？第一想到利用指针为空的条件，但不可能，指针是否为空只能用来判断下一个结点是否存在的问题。
	
	  考虑采用别的条件，利用栈的数目，栈存放的是指针也即地址，只要有地址说明遍历没有结束。大循环是负责什么时候
	  
	  遍历结束的问题。 
	  
	2.判断root是否为空，若为空则无效，若不为空，则继续；
	
	3.当前结点的数据输出，（同时当前结点更新为新一结点）而栈的操作，实际上是弹出栈顶数据。
	
	  考虑先序输出优先左结点，其次右结点。整体也是先根点左侧部分，再右侧部分。但利用栈的性质LIFO,先右结点入栈，再左结点。 

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
        /* if(root != NULL)   NULL表示法 null? */
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
