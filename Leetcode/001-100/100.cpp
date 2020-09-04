/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
	判断两棵树是不是相同的树
    
	1.用递归的方法
    2.借助queue，但是只要一个queue，一次pop两个元素
    

*/

//solution 2
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)   return true;
        if (p == NULL || q == NULL)   return false;
        
        if (p->val != q->val)     return false;
        

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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