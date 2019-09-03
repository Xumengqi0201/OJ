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
	
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri) {
     	if (lp > rp	)	return NULL;
     	TreeNode *root = new TreeNode(preorder[lp]);
     	int root_l = 0;
     	for (int i = li; i <= ri; i++){
     		if (inorder[i] == root->val){
                root_l = i;
                break;
            }
     	}
     	int leftsize = root_l - li;
     	int rightsize = ri- root_l;
     	root->left = build(preorder, inorder, lp+1, lp+leftsize,li, li+leftsize);
     	root->right = build(preorder, inorder, lp+leftsize+1,rp, root_l+1, ri);
    	
    	return root;
    }
};

/*
	给定preorder和inorder造树，递归,确定左子树和右子树的范围以及根节点的位置
*/