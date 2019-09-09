/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector <int> ans;
    	queue <TreeNode *> q;
    	if (root)	q.push(root);
    	while (!q.empty()){
    		int size = q.size();
    		while (size){
    			TreeNode *p = q.front();
    			q.pop();
    			ans.push_back(p->val);
    			if (p->left)	q.push(p->left);
    			if (p->right)	q.push(p->right);
    			size--;
    		}
    	}
    	return ans;
    }
};