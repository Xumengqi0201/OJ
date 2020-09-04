/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)   return NULL;
        queue <Node *> q;
        q.push(node);
        unordered_map <Node *, Node*> m;
        Node *copy = new Node(node->val, {});
        m[node] = copy;
        while(!q.empty()){
            Node *t = q.front();q.pop();
            if (t == NULL)  continue;
            for (Node *p : t->neighbors){
                if (m.find(p) == m.end()){
                    m[p] = new Node(p->val, {});
                    q.push(p);
                }
                m[t]->neighbors.push_back(m[p]);
            }
        }
        return copy;
        
    }
};
//DFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)    return NULL;
        if (m.find(node) != m.end())    return m[node];
        Node* node_copy = new Node(node->val, {});
        m[node] = node_copy;
        for (Node *n : node->neighbors){
            node_copy->neighbors.push_back(cloneGraph(n));
        }
        return node_copy;
        
    }
private:
    unordered_map <Node*, Node*> m;
};