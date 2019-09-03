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
	int height = 0;
    bool isBalanced(TreeNode* root) {
    	if (root == NULL){
    		height = 0;
    		return true;
    	}

    	bool leftBal = isBalanced(root->left);
    	int leftheight = height;
    	bool rightBal = isBalanced(root->right);
    	int rightheight = height;

    	height = max(leftheight, rightheight)+1;
    	if (abs(leftheight-rightheight) > 1)	return false;

    	return leftBal && rightBal;
        
    }

};
/*
	判断一棵树是不是平衡树
*/