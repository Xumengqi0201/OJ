/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)   return 0;
        if (root->left == NULL && root->right == NULL)  return 1;
        if (root->left == NULL)   return minDepth(root->right)+1;
        if (root->right == NULL)   return minDepth(root->left)+1;
        int h1 = minDepth(root->left);
        int h2 = minDepth(root->right);
        return min(h1, h2)+1;
        
        
        
    }
};
/*
	求树的最小深度，首先不能直接复制最大深度的求法，最小深度有多种情况
	不是每一种情况都是左子树和右子树的较小深度+1，因为可能有的节点的子树为空



*/