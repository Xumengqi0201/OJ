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
    bool isSymmetric(TreeNode* root) {
    	if (root == NULL)	return 	true;
    	return check(root->left, root->right);
        
    }
    bool check(TreeNode *p, TreeNode *q){
    	if (p && q){
    		return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    	}
    	return p == NULL && q == NULL;
    }
};
/*
	判断树是不是镜像对称，
	1.最简单的解法还是递归和上一道判断两棵树是不是相同类似
		判断方法：对于每一个相应位置的节点是不是相等，而且一个节点的左孩子应该等于对应节点的右孩子
		一直递归到leaf node返回即可	
	2.借助队列，和层序遍历类似，和100判断两颗树相同类似
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (root == NULL){
    		return true;
    	}
    	queue <TreeNode*> q;
    	q.push(root->left), q.push(root->right);
    	while (!q.empty()){
    		TreeNode *t1 = q.front();
    		q.pop();
    		TreeNode *t2 = q.front();
    		q.pop();
    		if (t1 ==NULL && t2 == NULL){
    			continue;
    		}
    		if (t1 == NULL || t2 == NULL){
    			return false;
    		}
    		if (t1->val != t2->val){
    			return false;
    		}
    		q.push(t1->left);
    		q.push(t2->right);
    		q.push(t1->right);
    		q.push(t2->left);
    	}
        return true;
    }
   
};
