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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)   return true;
        int h1 = height(root->left);
        int h2 = height(root->right);
        if (abs(h1-h2) >1)  return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    int height(TreeNode *root){
        if (root == NULL)   return 0;
        return max(height(root->left), height(root->right))+1;
    }
};
/*
	判断一棵树是不是平衡树
*/