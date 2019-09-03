/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	return buildTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
    TreeNode * buildTree(vector <int> &pre, vector <int> & in, int preL, int preR, int inL, int inR){
    	if (preL > preR || inL > inR)	return NULL;
    	int rootVal = pre[preL];
    	int pos = 0;
    	for (int i = inL; i <= inR; i++){
    		if (in[i] == rootVal){
    			pos = i;
    			break;
    		}
    	}
    	int lsize = pos-inL, rsize = inR-pos;
    	TreeNode *root = new TreeNode(rootVal);
    	root->left = buildTree(pre, in, preL+1, preL+lsize, inL, pos-1);
    	root->right = buildTree(pre, in, preL+lsize+1,preR, pos+1, inR);
    	return root;	
    }
};
//给定BST的前序和中序，建造一颗树