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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return buildBST(nums, 0, nums.size()-1);
        
    }

    TreeNode *buildBST(vector<int>&nums, int left, int right){
    	if (left > right)	return NULL;
    	int mid = (left+right)/2;
    	TreeNode *root = new TreeNode(nums[mid]);
    	root->left = buildBST(nums, left, mid-1);
    	root->right = buildBST(nums, mid+1, right);
    	return root;
    }
};

/*
	给定升序序列建立二叉平衡树
	height balanced tree:左子树和右子树都是BST，左右子树的高度差不超过1
	一个一个节点的插入显然需要很多的旋转操作，所以开始就定好每一个节点的左右子树区间、
	保证中间的数是根节点，递归的建立左右子树即可
*/