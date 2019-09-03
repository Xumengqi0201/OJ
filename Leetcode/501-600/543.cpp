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
    int diameterOfBinaryTree(TreeNode* root) {
    	if (root == NULL)	return 0;	
    	//讲过root节点的最长路径是左子树的最大深度+右子树的最大深度
		int sum = maxDepth(root->left) + maxDepth(root->right);
		int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
		return max(sum, sub); 
		//最终结果就是取经过根节点的最长路径和它左右字数某节点的最长路径   	
    }
    int maxDepth(TreeNode *root){
    	if (root == NULL)	return 0;
    	return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
/*
	以上是自己写的代码，但是速度只打败了10%，怎么提升呢。。。。
	显然，运行速度慢的原因是有大量的重复计算,居然没超时，leetcode也是和友好了
	为了避免重复计算，用哈希表存储节点的最大深度
	以下是改进版本
*/

class Solution {
private:
	unordered_map <TreeNode*, int> hash;
public:
    int diameterOfBinaryTree(TreeNode* root) {
    	if (root == NULL)	return 0;	
    	//讲过root节点的最长路径是左子树的最大深度+右子树的最大深度
    	int leftsub, rightsub;
    	if(hash.find(root->left) != hash.end()){
    		leftsub = hash[root->left];
    	}
    	else{
    		leftsub = maxDepth(root->left);
    	}
    	if (hash.find(root->right) != hash.end()){
    		rightsub = hash[root->right];
    	}
    	else{
    		rightsub = maxDepth(root->right);
    	}
		int sum = leftsub +rightsub;
		int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
		return max(sum, sub); 
		//最终结果就是取经过根节点的最长路径和它左右字数某节点的最长路径   	
    }
    int maxDepth(TreeNode *root){
    	if (root == NULL)	return 0;
    	int l = maxDepth(root->left);
    	int r = maxDepth(root->right);
    	hash[root->left] = l;
    	hash[root->right] = r;
    	int ans = max(l, r) +1;
    	hash[root] = ans;
    	return ans;
    }
};
//改进了以后还是慢，不过比之前快了一倍，可以把ans作为全局变量
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        deep(root, ans);
        return ans;
    }
    
    int deep(TreeNode* root, int &ans){
        if(root == nullptr) return 0;
        else{
            int dl = deep(root->left, ans);
            int dr = deep(root->right, ans);
            ans = max(dl+dr, ans);//随时更新ans，蠢的不行，不需要重复计算了
            
            return max(dl, dr) + 1;
        }
    }
};