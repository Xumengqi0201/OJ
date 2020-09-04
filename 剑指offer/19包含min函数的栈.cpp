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
s2 最小元素栈
