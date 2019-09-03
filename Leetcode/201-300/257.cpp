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
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> v;
    	if (root == NULL)	return v;
    	string s = "";
    	path(root, s, v);
    	return v;
        
    }
    void path(TreeNode *root, string s, vector <string> &res){
    	if (root->left == NULL &&root->right == NULL){
    		res.push_back(s+to_string(root->val));
    	}
    	if (root->left){
    		path(root->left, s+to_string(root->val)+"->", res);
    	}
    	if (root->right){
    		path(root->right, s+to_string(root->val)+"->", res);
    	}

    }

};