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
    int getMinimumDifference(TreeNode* root) {
        vector <int> BST;
        preorder(root, BST);
        int dif = INT_MAX;
        for (int i = 0; i < BST.size()-1; i++){
        	int tmp = BST[i+1]-BST[i];
        	if (tmp < dif){
        		dif = tmp;
        	}
        }
        return dif;

    }
    void preorder(TreeNode* root, vector <int> &v){
    	if (root){
    		preorder(root->left, v);
    		v.push_back(root->val);
    		preorder (root->right, v);
    	}
    }
};
/*
	BST中求出任意两个节点的最小差值的绝对值
	开始还想了半天，后来明白这是一个BST鸭，
	所以只需要前序遍历BST，把节点值存到一个vector中，
	遍历结束vector就是一个从小到大排好序的数组
	再计算相邻两个数之间的差值并求出最小值即可

*/