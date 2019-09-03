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
    int findSecondMinimumValue(TreeNode* root) {
    	if (root->left == NULL)		return -1;
    	queue <TreeNode*> q;
    	q.push(root);
    	int res = root->val;
    	bool flag = false;
    	while (!q.empty()){
    		int size = q.size();
    		while (size){
    			TreeNode *p = q.front();
    			q.pop();
    			if (!flag && p->val > res){
    				res = p->val;
    				flag = true;
    				//记录有没有节点的val比根节点的val大
    			}
    			if (p->val != root->val && flag && res > p->val){
    				res = p->val;
    			}
    			//如果flag == true说明已经更新过res了，接下来只要找比res小的但是不等于root->val的值
    			if (p->left){
    				q.push(p->left);
    				q.push(p->right);
    			}
    			size--;
    		}
    	}
    	if (flag)	return res;
    	return -1;
    }
};

/*
	在一个非空的二叉树中找第二小的节点值，该二叉树中的每一个节点值都小于等于它左右孩子的节点值
	而且一个节点要么同时有左右孩子要么没有孩子

	以上写法的速度打败了100%的解法，时间复杂度为O(h)

	最蠢的写法就是把二叉树遍历结果放在一个vector中然后排序，找出第二小的数
	当然了这样写肯定是不行的
	
	结合这个二叉树的特点，我们层序遍历这棵树。
	思考一下这个第二小的值有什么特点：1.root->val肯定是最小的2.第二小的肯定和最小值不同
	所以，flag是一个用来记录这棵树中有没有和最小值不同的值，如果没有返回-1
	如果有，那么在更新res的时候需要注意当前节点的值不能和最小值相同

*/
