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
    TreeNode* deleteNode(TreeNode* root, int key) {
    	bool flag = false;
        TreeNode *parent = NULL, *p = root;
        while(p){
        	if (p->val == key){
        		flag = true;
        		break;
        	}
        	else if (p->val < key){
        		parent = p;
        		p = p->right;
        	}
        	else {
        		parent = p;
        		p = p->left;
        	}
        }
        if (flag == false)	return root;

        TreeNode *q = p->right;
        while ( q && q->left){
        	q = q->left;
        }
        //q是找到p的右子树的最左边的叶节点
        if (q != NULL){
        	q->left = p->left;
        	p->left = NULL;//开始这一行忘了，最后的判断就有问题啦
        }
        if (p != root){
        	if(parent ->left == p){
        		if (p->right != NULL)	parent->left = p->right;
        		else	parent->left = p->left;
        	}
        	else{
        		if (p->right != NULL)	parent->right = p->right;
        		else	parent->right = p->left;
        	}
        }
        else{
        	//此时BST已经重构过了，所以直接返回左右孩子非空的一个
        	if (p->left == NULL){
        		root = p->right;
        	}
        	else{
        		root = p->left;
        	}
        }

        delete p;
        return root;
        
    }
};
/*

	delete a node in BST
	思路：
	1.利用BST的特点找指定的节点，因为要删除节点所以需要一个parent来记录指定节点的父节点
	2.如果没找到直接返回root，如果找到了见3.
	3.已经找到节点，删除节点后需要重新构造一个BST，只要把p的左子树接到p的右子树的最左边的叶节点上
	4.最后要判定一下p是不是root，如果是root那么要改变root的值否则重构就好了

	这一题开始没想清楚还在分类讨论（是不是叶节点啥的）我晕，其实左右子树 为空只是一种特殊的情况啦
	最后终于ac了，呜呜

*/