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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return f(inorder, postorder, 0, inorder.size()-1,0, inorder.size()-1);
    }
    TreeNode* f(vector<int>& inorder, vector<int>& postorder, int iL, int iR, int pL,int pR){
        if (iL > iR ||pL >pR)  return NULL;
        int rootval = postorder[pR];
        int pos = 0;
        for (int i = iL; i <= iR; i++){
            if(inorder[i] == rootval)   
            {
                pos = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootval);
        root->left = f(inorder, postorder, iL, pos-1, pL, pL+pos-iL-1);
        root->right = f(inorder, postorder, pos+1, iR, pL+pos-iL, pR-1);
        return root;
    }
};
//中序+后序造树