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
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
        
    }
private:
    void dfs(TreeNode *root, int sum) {
        if (root == NULL)   return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val){
            ans.push_back(path);
            
        }
        else{
            dfs(root->left, sum-root->val);
            dfs(root->right, sum- root->val);
        }
        path.pop_back();
  }
};