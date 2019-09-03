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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        vector <int> level;
        queue <TreeNode*> q;
        if (root == NULL)	return res;
        q.push(root);
        while (!q.empty()){
        	//用size记录当前层有多少节点数量
        	int size = q.size();
        	while (size){
        		TreeNode * t = q.front();
        		q.pop();
        		level.push_back(t->val);
        		if (t->left)	q.push(t->left);
        		if (t->right)	q.push(t->right);
        		size--;
        	}
        	res.push_back(level);
        	level.clear();
        }


        return res;
    }
};

/*
	层序遍历一颗树，每层的数放到一个vector中
	借助queue

*/