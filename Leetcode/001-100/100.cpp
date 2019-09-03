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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	queue <TreeNode*> queue1, queue2;
    	if (p!=NULL)	 queue1.push(p);  
    	if (q!=NULL)	 queue2.push(q);
    
    	while (!queue1.empty() && !queue2.empty()){
    		TreeNode *t1 = queue1.front();
    		queue1.pop();
    		TreeNode *t2 = queue2.front();
    		queue2.pop();

    		if (t1->val != t2->val)		return false;
    		if (t1->left)	queue1.push(t1->left);
    		if (t2->left)	queue2.push(t2->left);
    		if (queue1.size()!= queue2.size())	return false;
    		if (t1->right)	queue1.push(t1->right);
    		if (t2->right)	queue2.push(t2->right);
    		if (queue1.size()!= queue2.size())	return false;
    		
    	}
    	return queue1.size() == queue2.size();
        
    }
};
/*
	判断两棵树是不是相同的树
    1.借助queue，当然也可以借助stack对两棵树进行层序遍历
	2.用递归的方法
    3.借助queue，但是只要一个queue，一次pop两个元素
    三种方法中，第三种是对第一种的改进，没有区分空节点

*/

//solution 2
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (p  && q ){
    		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    	}
    	return p == NULL  && q == NULL;
    	//不满足两个节点都不为空的话，那么必须同时到达空节点才保证正确
        
    }
};


//solution 3
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       queue<TreeNode*> treeq;
       treeq.push(p),treeq.push(q);
       while (!treeq.empty()){
            TreeNode *t1 = treeq.front();
            treeq.pop();
            TreeNode *t2 = treeq.front();
            treeq.pop();

            if (t1 == NULL && t2 == NULL)     continue;
            if (t1 == NULL|| t2 == NULL)    return false;
            if (t1->val  != t2->val)       return false;
            treeq.push(t1->left);
            treeq.push(t2->left);
            treeq.push(t1->right);
            treeq.push(t2->right);
       }
       return true;  //在while中没有返回false，说明返回了true
        
    }
};