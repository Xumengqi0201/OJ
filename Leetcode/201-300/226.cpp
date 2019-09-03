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
    TreeNode* invertTree(TreeNode* root) {
    	if (root == NULL)	return NULL;
    	TreeNode *tmp = root->right;
    	root->right = invertTree(root->left);
    	root->left = invertTree(tmp);	
        return root;
    }
};
//invert a binary tree ,这一题写的太完美了，哈哈！