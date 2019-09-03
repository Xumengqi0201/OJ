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
    int sumOfLeftLeaves(TreeNode* root) {
    	if (root == NULL)	return 0;
    	//left leaf node
    	if (root->left && !root->left->left && !root->left->right)
    		return root->left->val + sumOfLeftLeaves(root->right);
    	return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
/*
左子叶的value之和，开始看成左孩子节点value之和，晕！！！
递归是最直观的写法，也可以借助stack和preorder的思想是一样的
*/


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
    	int sum = 0;
    	TreeNode *p = root;
    	stack < TreeNode* > s;
    	while (p || !s.empty()){
    		while (p){
    			s.push(p);
    			p = p->left;
    			if (p && !p->left && !p->right)
    				sum += p->val;
    		}
    		p = s.top();
    		s.pop();
    		p = p->right; //if p = null,那么就会不停的出栈直到一个右孩子不为空
    	}

    	return sum;
    }
};