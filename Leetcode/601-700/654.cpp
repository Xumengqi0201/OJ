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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		int left = 0, right = nums.size()-1;
		//注意right的赋值-1不能少
		TreeNode *root = buildTree(nums, left, right);
		return root;
    }

    TreeNode* buildTree(vector <int> &nums, int left, int right){
    	if (left > right)	return NULL;
    	int maxval = INT_MIN, pos;
		for (int i = left; i <= right; i++){
			if (nums[i] > maxval){
				maxval = nums[i];
				pos = i;
			}
		}
		TreeNode *root = new TreeNode(maxval);
		root->left = buildTree(nums, left, pos-1);
		root->right = buildTree(nums, pos+1, right);
		return root;
    }

};