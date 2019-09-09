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
private:
	void addPath(TreeNode* root, vector <int> path, vector<vector<int>> &ans, int sum, int expectNumber){
    	if (root == NULL)	return;
    	path.push_back(root->val);
    	sum += root->val;
    	if (sum == expectNumber && !root->left && !root->right){
    		ans.push_back(path);
    		return;
    	}
    	addPath(root->left, path, ans, sum, expectNumber);
    	addPath(root->right, path, ans, sum, expectNumber);
    }
    //把cmp声明为static类型
    static bool cmp(vector <int> &x, vector <int> & y){
    	return x.size() > y.size();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector <vector <int> > ans;
    	vector <int> path;
    	int sum = 0;
    	addPath(root, path, ans, sum, expectNumber);
    	sort(ans.begin(), ans.end(), cmp);
    	return ans;
    }
};