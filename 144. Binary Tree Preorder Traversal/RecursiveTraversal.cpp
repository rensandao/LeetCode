// source : 
// Author: rensandao
// Date: 2018-12-08
 
/*********************************
1. 二叉树的遍历（先序）实现；
2. 181209关于递归遍历的实现代码中的问题：涉及逻辑性写代码；涉及全局变量和局部变量的作用域问题，对应解决方法； 
 
*********************************/ 
#include<cstdio>
#include<cstdlib> /* recommend c++ writing format. libray: malloc, free, rand,*/
#include<iostream>
#include<stack>  /* c++ container: stack*/
#include<vector>
using namespace std; /**/

typedef int ElemType;

struct TreeNode{
	ElemType val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(size_t x): val(x), left(NULL), right(NULL){}	//initialization
};

vector<int> res; 
//recursive traversal
vector<int> RecursiveTraversal(TreeNode *root){  //默认叶子结点左右孩子为NULL 
	//vector<int> res;
	
	//if(!root) cout<< "Null Node."<<endl; 
	
	//这里采用vector容器存放数据，但结果显示只输出一位数字；有什么问题？ 
	// 返回值是vector<int> ,而递归调用时，返回的值却没有赋给任何变量  
	if(root) {//这里的if(root)以及{}域可要可不要 
		res.push_back(root->val);
	
	//preorder
	/*思维：写到这步，应该要想到：
		1.判断是否有左孩子；若有，则递归调用本函数；若没有，则不调用；
		2.再判断是否有有孩子，递归调用同上。 
	*/ 
	/*
	测试出错：
	如果res定义在函数体内部，最终输出结果只有1个值。解决办法之一是将res定义全局变量，即放在函数体外。 
	这里递归结果返回值，没有变量接受；导致测试结构只输出根节点值1个。
	分析：
	导致vector输出1个值的原因，最大问题是由递归结构本身导致的，递归是调用自己，除了第一次，
	之后每一次调用，由于在函数体内声明的result的作用域问题，调用接受vector<int> result 数据即释放。
	解决的办法之一，是可以定义个全局变量，改变作用域范围。
	（ps:有什么不好？1.全局变量会破坏函数的封装性能。函数像是个黑匣子，一般通过函数形参和返回值进行输入输出，
	内部实现相对独立。2.使用全局变量就绕过这种机制进行处理，就破坏函数的独立性，使函数对全局变量产生依赖。也降低
	该函数的可移植性。3.可读性降低，不利于调试）
	改进的办法：将他们封装为一个类，作为成员变量和成员函数。 
	
	*/
		if(root->left) RecursiveTraversal(root->left);
		if(root->right) RecursiveTraversal(root->right);			 	
	} 
	return res;
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
	cout<< "先序遍历法，vector输出：" << endl; 
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	
	/*  1. construct binary tree 
		2. print binary tree datas
		3. preorder traversal
		4. print the result
	*/

	cout<<"请输入二叉树结点数据int型：" << endl; 
	TreeNode* root1 = CreateBiTree();
	
	/*print tree*/
	cout << "打印结点值:" <<endl; 
	printTree(root1);
	//preorder Traversal
	cout<< endl; 
	
	cout<<"Recursive method:" << endl;
	vector<int> v1 = RecursiveTraversal(root1);
	printVec(v1);
	cout<<endl;
	
	return 0;
}

