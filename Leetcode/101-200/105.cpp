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
        return f(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        
    }
    TreeNode* f(vector<int> &preorder, vector<int> & inorder, int pL, int pR, int iL, int iR){
        if (pL > pR)  return NULL;
        int rootval = preorder[pL];
        int pos;
        for (pos = iL; pos <= iR; pos++){
            if (inorder[pos] == rootval)
                break;
        }
        TreeNode *root = new TreeNode(rootval);
        root->left = f(preorder, inorder, pL+1,  pos-iL+pL, iL, pos-1);
        root->right = f(preorder, inorder, pos-iL+pL+1, pR, pos+1, iR);
        return root;
    }
};
/*
	给定preorder和inorder造树，递归,确定左子树和右子树的范围以及根节点的位置
*/