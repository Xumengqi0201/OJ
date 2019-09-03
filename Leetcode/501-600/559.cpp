/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
    	/* binary tree:maxDepth
    	if (root == NULL)	return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
		*/

		if (root == NULL)	return 0;
		int maxSubtree = 0;
		for (int i = 0; i < root->children.size(); i++){
			int depth = maxDepth(root->children[i]);
			if (depth > maxSubtree )	maxSubtree = depth;
		}
		return maxSubtree+1;
		//递归，结果等于子树的最大深度+1，在二叉树的基础上改写的
    }
};
//后来一想可以层序遍历，记录层数就行了
class Solution {
public:
    int maxDepth(Node* root) {
    	int ans = 0;
    	queue <Node *> q;
    	if (root)	q.push(root);
    	while (!q.empty()){
    		int size = q.size();
    		while (size){
    			Node *p = q.front();
    			q.pop();
    			for (int i = 0; i < p->children.size(); i++){
    				if (p->children[i] != NULL)		q.push(p->children[i]);
    			}
    			size--;
    		}
    		ans++;
    	}
    	return ans;
    }
};