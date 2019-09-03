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
    vector<int> findMode(TreeNode* root) {
    	vector <int> ans;
    	int cnt = 1, val = 0, maxcnt = 0;
        TreeNode *p = root, *pre = NULL;
    	stack <TreeNode*> s;
    	//借助stack中序遍历，开始设的pre= 0是不严谨的
    	while (!s.empty() || p){
    		while (p){
    			s.push(p);
    			p = p->left;
    		}
    		p = s.top();
    		s.pop();

    		if (pre){ //说明已经遇到了一个节点
    			if (p->val == pre->val)	cnt++;
    			else  cnt = 1;
    		}
    		if (cnt >= maxcnt){
    			if (cnt > maxcnt)	ans.clear();
    			ans.push_back(p->val);
    			maxcnt = cnt;
    		}
    		pre = p;
    		p = p->right;
    	}
    	return ans;
    }
};
//O(1)空间复杂度
