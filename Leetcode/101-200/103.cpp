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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector <vector<int>> res;
    	if (root == NULL)	return res;
    	vector <int> level;
    	queue<TreeNode*> q;
  		q.push(root);
  		while (!q.empty()){
  			int size = q.size();
  			while(size){
  				size--;
  			    TreeNode *p = q.front();
  				q.pop();
  				level.push_back(p->val);
  				if (p->left)		q.push(p->left);
  				if (p->right)		q.push(p->right);
  			}
  			res.push_back(level);
  			level.clear();
  		}

  		for (int i = 1; i < res.size(); i+=2){
  			reverse(res[i].begin(), res[i].end());
  		}
  		return res;
        
    }
};

/*
	zigzag遍历一棵树，最傻的方法是层序遍历一颗树，然后将其中的部分倒过来就行
	也可以用两个stack倒来倒去
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector <vector<int>> res;
    	if (root == NULL)	return res;
    	vector <int> level;
    	stack <TreeNode*> s1, s2;
  		s1.push(root);
  		while (!s1.empty() || !s2.empty()){
  			while (!s1.empty()){
  				TreeNode * p = s1.top();
  				s1.pop();
  				level.push_back(p->val);
  				if (p->left)	s2.push(p->left);
  				if (p->right)	s2.push(p->right);
  			}
  			//一定要加一个不为空的条件，否则结果中有空的数组
  			if (!level.empty())		res.push_back(level);
  			level.clear();
  			while (!s2.empty()){
  				TreeNode * p = s2.top();
  				s2.pop();
  				level.push_back(p->val);
  				if (p->right)	s1.push(p->right);
  				if (p->left)	s1.push(p->left);

  			}
  			if (!level.empty())		res.push_back(level);
  			level.clear();
  			
  		}

  		
  		return res;
        
    }
};