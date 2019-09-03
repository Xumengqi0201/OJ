/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector <int> res;
    	inorder(root, res);
    	return res;
        
    }
    void inorder(TreeNode* root, vector<int> & res){
    	if (root!= NULL){
    		inorder(root->left, res);
    		res.push_back(root->val);
    		inorder(root->right, res);
    	}
    }
};
/*
	中序遍历一棵树,思路：
	1.递归，没啥写的
	2.借助stack,根据左根右的访问顺序，一直push到一个节点没有左孩子，然后访问它
	  但是它可能有右孩子，所以把右孩子入栈，一直到整个stack空


*/
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector <int> res;
		if (root == NULL)	return res;
		stack <TreeNode*> s;
		TreeNode *p = root;
		while( p || !s.empty()){
			while(p){
				s.push(p);
				p = p->left;
			}
			if (!s.empty()){
				p = s.top();
				res.push_back(p->val);
				s.pop();
				p = p->right;
			}
		}
		return res;
	}
};