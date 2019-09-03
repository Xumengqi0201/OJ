class Node{
public:
    int val;
    Node *next;
    Node(int val){
        Node::val = val;
        next = NULL;
    }
};
class MinStack {
private:
    Node * Top;
    Node *min;
public:
    /** initialize your data structure here. */
    MinStack() {
        Top = NULL;
        min = NULL;  
    }
    
    void push(int x) {
        Node *p = new Node(x);
        if (Top == NULL){
            Top = p;
            min = p;
        }
        else{
            Top->next = p;
            Top = p;
        }

        if (min->val >= x){ //stack先进后出，一个元素比最小值大，那么它也是先pop出去，对最小值是没有影响的
            min->next = p;
            min = p;
        }

    }
    
    void pop() {
        if (Top == NULL)    return;
        if (min->val == Top->val){
            Node *q = min;
            min = min->next;
            delete q;
        }
        Node *p = Top;
        Top= Top->next;
        delete p;
    }
    
    int top() {
        if (Top == NULL)    return -1;
        return Top->val;
    }
    
    int getMin() {
        if (Top == NULL)    return -1;
        return min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->Top();
 * int param_4 = obj->getMin();
 */