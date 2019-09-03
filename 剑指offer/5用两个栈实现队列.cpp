class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
    	/*
			如果s2为空，那么把s1的元素全部push到s2中
			如果s2不为空了，执行s2 pop
			否则返回-1，表明两个栈都是空的状态

			分析pop，只要s2不为空，那么pop的时间复杂度是O(1)

    	*/
    	if (stack2.empty()){
    		while (!stack1.empty()){
    			stack2.push(stack1.top());
    			stack1.pop();
    		}
    	}
    	if (!stack2.empty()){   	
    		int node = stack2.top();
    		stack2.pop();
    		return node;
    	}
    	return -1;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


/*
	用两个栈来实现一个队列，完成队列的Push和Pop操作。
	思路：降低Push和Pop的时间复杂度，这是栈最常用的两个操作
	leetcode原题
*/