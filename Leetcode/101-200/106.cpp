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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int li, int ri, int lp, int rp){
        if (lp > rp || li > ri)	return NULL;
        TreeNode * root = new TreeNode(postorder[rp]);
        int root_l = 0;
        for (int i = li; i <= ri; i++){
            if (inorder[i] == root->val){
                root_l = i;
                break;
            }
        }
        root->left = build(inorder, postorder, li,root_l-1,lp,lp+root_l-1-li);
        root->right = build (inorder, postorder,root_l+1,ri, lp+root_l-li ,rp-1);

        return root;
    }
};
//中序+后序造树