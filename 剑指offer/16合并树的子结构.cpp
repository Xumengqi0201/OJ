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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	if (pRoot2 == NULL || pRoot1 == NULL)	return false;
    	return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

    }
    bool isSubtree(TreeNode *root1, TreeNode *root2){
		//	root2遍历结束了，返回true
    	if (root2 == NULL)	return true; 
    	//  root1结束了, root2还没结束,2肯定不是1的子树
    	if (root1 == NULL)	return false;
    	if (root2->val != root1->val)	return false;
    	return isSubtree(root1->left, root2->left) && isSubtree(root1->right, root2->right);

    }
};
/*
	判断B是不是A的子树且空树不是任何一个树的子树
	递归法，注意递归出口的顺序
*/
