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
	vector<int> path;
	vector< vector<int> > allpath;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)	return allpath;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL){
        	int tmp =0;
        	for(int i = 0; i < path.size(); i++){
        		tmp += path[i];
        	}
        	if (tmp == sum)	allpath.push_back(path);
        }

        if (root->left != NULL){
        	pathSum(root->left, sum);
        }
        if (root->right!= NULL){
        	pathSum(root->right, sum);
        }
        path.pop_back();
        return allpath;
    }
};

/*
	求所有root->leaf节点之和等于sum的路径
	思路：
	1.dfs递归的求出符合条件的路径
*/
