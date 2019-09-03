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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)	return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

    }
    int sumUp(TreeNode* root, int pre, int sum){
    	if (!root)	return 0;
    	int cur = pre + root->val;
    	return (cur == sum) + sumUp(root->left, cur, sum) + sumUp(root->right, cur, sum);
    }

};

/*
	我的思路和这个差不多，但是真是没办法实现出来
	关键是sumUp函数需要一个pre参数，记录之前路径的和
	两个递归函数，实际上是对每一个节点都dfs了

*/