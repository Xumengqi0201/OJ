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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
     	TreeNode *first = NULL, *pre = NULL;
     	bool isfirst = false;
     	stack <TreeNode*> s;
     	TreeNode *p = pRootOfTree;
     	while (p || !s.empty()){
     		while (p){
     			s.push(p);
     			p = p->left;
     		}
     		p = s.top();
     		s.pop();
     		if (isfirst == false){
     			isfirst = true;
     			first = p;
     			pre = p;
     		}
     		else{
     			p->left = pre;
     			pre->right = p;
     			pre = p;
     		}
     		p = p->right;

     	}
     	return first;
    }
};

/*
	输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
	
	利用stack中序遍历二叉树，设置pre,first 	





*/