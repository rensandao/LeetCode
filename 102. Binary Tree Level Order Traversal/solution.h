/****************************************************************
source: 
Author: rensandao
Date: 2018-12-14
****************************************************************/ 
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//method0
//error code
/*
有问题的思路：
完全不知道要用queue。但是逻辑上知道，每一层的数据可以保存在容器vlevel里面，然后循环再对vlevel每一层的结点再判断输出，压入；但实现代码较复杂。
考虑到每次循环，vlevel的数据需要清空，还得需要一个备用容器。这还是这是结点指针。对于数据的存储也得考虑个容器，还得备份。这都用多少个容器了。
直到看到queue，才再一次感受到数据结构的巧妙之处。这应该就是最底层的轮子了。你自己造轮子还是太嫩，得记住它再多用它。
*/
vector<vector<int>> levelOrder0(TreeNode* root) {
    if(!root)  return{};
    vector<vector<int>> res;
    vector<TreeNode*> vec_ptr;
    vec_ptr.push_back(root);
    
    while (vec_ptr.size()!=0) {
        vector<TreeNode*> vec_ptr2;
        vector<int> vec1;
        for (vector<TreeNode*>::iterator it = vec_ptr.begin(); it != vec_ptr.end(); it++) {
            if ((*it)->left){
                int val1 = ((*it)->left)->val;
                vec_ptr2.push_back(*it);
                vec1.push_back(val1);
            }   
            if ((*it)->right)  {
                int val2 = ((*it)->right)->val;
                vec1.push_back(val2); 
                vec_ptr2.push_back(*it);
            }
        }
        res.push_back(vec1);
        
        vec_ptr.erase(vec_ptr2.begin(), vec_ptr2.end());
        vec_ptr.insert(vec_ptr.begin(), vec1.begin(), vec1.end());
        
       // vec_ptr2.erase(vec_ptr2.begin(), vec_ptr2.end());
        //vec1.erase(ve)   
    }
    return res;   
}

/*
思路1：queue这种结构，单方向向前推动的（如食堂排队打饭），不像栈来回折腾（容易让人生闷气）。
queue很好解决一段段，一层一层向前推进，从而符合层序遍历的方式。

reference: LeetCode AC第一档答案。
*/
//level order traversal using queue
//mehtod1
vector<vector<int>> levelOrder1(TreeNode* root) {
	vector<vector<int>> res;
	queue<TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) {
		TreeNode *vlevel;
		int qlength = q.size();
		//由于在迭代循环过程中，队列是有进有出的，所以size在变动；因为不能放在for循环条件里面。 
		for (int i=0; i<qlength; i++) {
			TreeNode *t= q.front();
	   		q.pop();
	   		vlevel.push_back(t->val);
			
			if (t->left)  q.push(t->left);
			if (t->right)  q.push(t->right);   	
		}   
		res.push_back(vlevel); 
	}
	return res;
}


/*
思路2：递归调用
对于每一层的结点及所在层数flag，递归循环保存在每一层的数据，并且直接在vector<vector<int>> res中操作。这个下标直接操作的方法倒是没碰到，但显然不错。
reference: Leetcode sample 0 ms submission
*/
//level order traversal using recursive iteration 
//recursive
//method2
vector<vector<int>> levelOrder2(TreeNode* root) {
	if(!root) return{};
	vector<vector<int>> res;
	levelOrderRecursive(root, 1, res);
	return res;
}

void levelOrderRecursive(TreeNode *temp, int level, vector<vector<int>> &res) {
	//res内的vector个数正好代表了有几层。如果进入下一层，则在res中先初始化一组空vector，以便后续push_back
	if (res.size() < level)  res.push_back({});  //c++11: result.emplace_back(std::vector<int>());
	res[level-1].push_back(temp->val);
	
	if (temp->left)  levelOrderRecursive(temp->left, level+1, res);
	if (temp->right)  levelOrderRecursive(temp->right, level+1, res);	
}

        
