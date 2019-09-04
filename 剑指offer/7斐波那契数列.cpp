class Solution {
public:
    int Fibonacci(int n) {
    	if (n <= 1)		return n;
    	int *fib = new int[n+1];
    	fib[0] = 0, fib[1] = 1;
    	for (int i = 2; i <= n; i++){
    		fib[i] = fib[i-1] + fib[i-2];
    	}
    	int ans = fib[n];
    	delete []fib;
    	return ans;
    }
};
//求斐波那契数列，只要不智障的用递归就行了