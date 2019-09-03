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
    int kthSmallest(TreeNode* root, int k) {
        vector <int> in;
        int ele = 0;
        inorder(root, in);
        for (int i = 0; i <in.size(); i++){
        	if (i == k-1){
        		ele = in[i];
        		break;
        	}
        }
        return ele;
    }
    void inorder(TreeNode *root, vector<int> &in){
    	if (root){
    		inorder(root->left, in);
    		in.push_back(root->val);
    		inorder(root->right, in);
    	}
    }
};
/*
	找出二叉树第K小的元素，中序遍历二叉树元素放到vector中，再遍历vector即可。
	可以用非递归的形式得到inorder的结果。

*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> s;
        TreeNode *p = root;
   		int cnt = 0, ele = 0;
        while (!s.empty() || p){
        	while (p){
        		s.push(p);
        		p = p->left;
        	}
        	p = s.top();
        	cnt++;
        	if (cnt == k){
        		ele = p->val;
        		break;
        	}
        	s.pop();
        	p = p->right;
        }
        return ele;
    }
 
};