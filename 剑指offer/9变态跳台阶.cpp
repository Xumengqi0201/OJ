class Solution {
public:
    int jumpFloorII(int number) {
    	if (number == 0)	return 0;
    	return pow(2, number-1);
    }
};
/*
	特殊的DP
	f(n) = f(0)+ f(1)+f(2) +......f(n-1)
	f(n-1) = f(0) + f(1)+f(2)+......f(n-2)

	f(n) = 2*f(n-1)
	.
	.
	.
	f(2) = 2*f(1)
	f(1) = 1
	f(0) = 0
	
	所以f(n) = pow(2,n-1) n!=0
		f(0) = 0
*/