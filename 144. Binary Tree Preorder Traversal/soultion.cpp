
/****************************************************************
source: 
Author: rensandao
Date: 2018-12-08

Reference:
https://github.com/haoel/leetcode/blob/master/algorithms/cpp/binaryTreePreorderTraversal/binaryTreePreorderTraversal.cpp
****************************************************************/ 

#include<stdio.h>
#include<stdlib.h> /* recommend c++ writing format. libray: malloc, free, rand,*/
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
vector<int> preorderTraversal(TreeNode* root){
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

//#2: create binary tree by tranfering value
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
	vector<int> v = preorderTraversal(root1);
	//print result
	printVec(v);
	cout<<endl;
	
	return 0;
}

