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
    vector<vector<int>> levelOrder(Node* root) {
        queue <Node*> q;
        vector <vector<int> > res;
       	if (root)	q.push(root);

        while (!q.empty()){
        	int size = q.size();
        	vector <int> level;
        	while(size){//记录当前队列的size
        		Node *tmp = q.front();
        		level.push_back(tmp->val);
        		q.pop();
        		vector <Node*> v = tmp->children;
        		for (int i = 0; i < v.size();i++){
        			q.push(v[i]);
        		} 
        		size--;
        	}
        	res.push_back(level);
        	level.clear();
        }
        return res;
    }
};
//这是在二叉树层序遍历的基础上改进的一道题，原理一样借助Queue遍历