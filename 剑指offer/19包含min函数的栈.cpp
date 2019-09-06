class Solution {
private:
	stack <int >s1, s2;
public:
    void push(int value) {
 		s1.push(value);
 		if (s2.empty() || s2.top() >= value){
 			s2.push(value);
 		}
    }
    void pop() {
        if (!s1.empty()){
        	if (s1.top() == s2.top()){
        		s2.pop();
        	}
        	s1.pop();
        }
    }
    int top() {
        return s1.empty() ? -1 : s1.top();
    }
    int min() {
        return s2.empty() ? -1 : s2.top();
    }
};
/*
	第一种方法需要一个辅助栈，额外的空间多一些
	
*/
class Solution {
private:
struct Node{
	int val;
	Node *next;
	Node(int v){
		val = v;
		next = NULL;
	} 
};

Node *top = NULL, *min = NULL;
public:
    void push(int value) {
 		Node *p = new Node(value);
 		if (top == NULL){
 			top = p;
 			min = p;
 		else{
 			p->next = top; 
 			top = p;
 			if (value <= min->val){
 				min->next = p;
 				min = p;
 			}
 		}
    }
    void pop() {
        if (top == NULL)	return;
        Node *p = top;
        if (top->val == min->val)	min = min->next;
        top = top->next;
        delete p;
    }

    int top() {
        return top == NULL ? -1 : top->val;
    }
    int min() {
        return min == NULL ? -1 : min->val;
    }
};