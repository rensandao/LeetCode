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
vector<vector<int>> levelOrder(TreeNode* root) {
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



//level order traversal using queue
//mehtod1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    }
};
