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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)	return false;
        stack <TreeNode*> s;
        TreeNode *p = root;
        vector <int> tree;
        while(!s.empty() || p){
        	while (p){
        		s.push(p);
        		p = p->left;
        	}
        	p = s.top();
        	s.pop();
        	tree.push_back(p->val);
        	p = p->right;
        }
        //双指针，二分法的变体哈哈，果然比原来快好多呀
        int l = 0, r = tree.size()-1;
        while (l < r){
        	int sum = tree[l] + tree[r];
        	if (sum == k)	 return true;
        	else if (sum < k)	l++;
        	else r--;
        }
        return false;
    }
};
