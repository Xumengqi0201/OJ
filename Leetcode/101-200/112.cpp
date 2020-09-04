/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
	判断从根节点到叶节点的路径中存不存在一条路径上的节点之和等不等于sum
	思路：
	1.用dfs的方法记录所有的root->leaf的路径，然后分别计算路径节点之和。
	2.思路和方法1一致，但是加了flag标记,只要找到一条满足要求的路径就返回而不用找出所有的根到叶的路径
	3.解法三和2一样不过写到一个函数中了
	
*/
//solution 1,垃圾
class Solution {
public:
	vector <vector<int>> allpath;
    bool hasPathSum(TreeNode* root, int sum) {
    	vector <int> path;
    	dfs(root, path);
    	bool flag = false;
    	for (int i= 0; i < allpath.size(); i++){
    		vector <int> tmppath = allpath[i];
    		int tmp = 0;
    		for (int j = 0; j < tmppath.size(); j++){
    			tmp += tmppath[j];
    		}
    		if (tmp == sum){
    			flag = true;
    			break;
    		}
    	}
    	return flag;
        
    }
    void dfs(TreeNode *root,vector<int> &path){
    	if (root == NULL)	return;
    	path.push_back(root->val);
    	if (root->left == NULL && root->right == NULL){
    		allpath.push_back(path);
    	}
    	if (root->left != NULL){
    		dfs(root->left, path);
    	}
    	if (root->right!= NULL){
    		dfs(root->right, path);
    	}
    	path.pop_back();
    }
};


//solution2
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag = false;
        dfs(root, sum, 0, flag);
        return flag;
        
    }
    void dfs(TreeNode* root, int sum, int cur, bool& flag){
        if (flag == true)   return;
        if (root == NULL)   return;
        cur += root->val;
        if (cur == sum){
            if (root->left == NULL && root->right == NULL){
                flag = true;
                return;
            }
        }
        if (root->left){
            dfs(root->left, sum, cur, flag);
        }
        if (root->right){
            dfs(root->right, sum, cur, flag);
        }
        
        
    }
};

//简洁且剪枝了

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if (root == NULL)  return false;
        if (root->left == NULL && root->right == NULL && root->val == sum)  return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
   
  
   
};

