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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL|| root == p|| root == q)	return root; 
        //root == NULL means a brunch search is over.
        TreeNode *left = lowestCommonAncestor(root->left, p , q);
        TreeNode *right = lowestCommonAncestor(root->right, p ,q);
        if (left && right)	return root;
        return left ? left : right; //不满足上一个条件，说明p和q在左子树或者右子树中
    }
};
/*
	找一颗二叉树的两个节点的LCA，不能利用BST的性质，只能在二叉树中搜索两个节点
*/