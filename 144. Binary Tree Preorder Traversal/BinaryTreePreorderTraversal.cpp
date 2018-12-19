
/****************************************************************
source: 
Author: rensandao
First Creation: 2018-12-08
Reference:
https://github.com/haoel/leetcode/blob/master/algorithms/cpp/binaryTreePreorderTraversal/binaryTreePreorderTraversal.cpp
****************************************************************/ 
#include<stdio.h>
#include<stdlib.h> // recommend c++ writing format. libray: malloc, free, rand，etc
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

typedef int ElemType;

struct TreeNode{
	ElemType val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(size_t x): val(x), left(NULL), right(NULL){}	//initialization
};

//preorder Traversal using stack
//method1
vector<int> preorderTraversalM1(TreeNode* root) {
	/*iterative solution using stack method.
	The function of stack is store the pointer value temporarily,
	and deal with left and right child tree order.
	For preorder, we wish to print the sort result from the root to left tree, 
	and the right tree last.
	So with stack, we can push right child pointer first and then left one. When
	poping, left goes first and then the right. The problem sovled.    */
	
    stack<const TreeNode*> stack;
    vector<int> result;
	
    // or use if(root != NULL) 
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

//preorder Traversal using stack
//method2
/*
思路：
1.判断当前结点是否为空；
如果不为空，先压栈，同时输出数据。当前结点更新为左孩子结点。
如果为空，则说明栈顶结点是叶子结点，由于刚刚已经输出过数据，所以先弹出；
			取上上个结点，再更新当前结点为其右孩子

分析：已经保存的数据仍会被压入栈中，然后在出栈。 
*/
vector<int> preorderTraversal2(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	TreeNode *temp = root;
	
	while (!st.empty() || temp) {
		if (temp) {
			st.push(temp);
			res.push_back(temp->val);
			temp = temp->left;			
		} else {
			TreeNode *t = st.top();
			st.pop();
			temp = t->right;
		}
	}	
	return res;
}


/*
181219
思路3： morris算法

*/
//method3,using morris algorithm. Space complexity： O(1)
vector<int> preorderTraversal3(TreeNode* root) {
	
	
	
	vector<int> res;
}



//create binary tree by tranfering value
TreeNode* CreateBiTree(){   
	TreeNode *T;
	ElemType ch;
	cin>>ch;
			
	if(0 == ch) 	 
		T = NULL;
	else{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		if(!T)
			cout<<"error, fail to mallocate memory!"<<endl;
		T->val = ch;
		T->left = CreateBiTree();
		T->right = CreateBiTree();			
	}			
	return T; //
}			

//print tree -preorder
void printTree(TreeNode* root){
	if(root){
		cout<< root->val <<" ";
		
		printTree(root->left);
		printTree(root->right);		
	}
}

//print result of vector
void printVec(vector<int> v){
	cout<< "The result of preorder traversal: " << endl; 
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}


int main(){
	
	/*  
        1. construct binary tree 
        2. print binary tree datas
        3. preorder traversal
        4. print the result
	*/
	cout<<"please input Binary tree nodes' datas：" << endl; 
	TreeNode* root1 = CreateBiTree();
	
	/*print tree*/
	cout << "print nodes:" <<endl; 
	printTree(root1);
	//preorder Traversal
	cout<< endl; 
	vector<int> v = preorderTraversalM1(root1);
	//print result
	printVec(v);
	cout<<endl;
	
	return 0;
}
