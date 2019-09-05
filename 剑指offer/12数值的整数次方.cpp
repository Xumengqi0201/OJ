class Solution {
public:
    double Power(double base, int exponent) {
    	if (base == 0)	return 0;
    	if (exponent == 0)	return 1;
    	double ans = 1.0;
    	int exp = abs(exponent);
    	for (int i = 1; i <= exp; i++){
    		ans *= base;
    	}
    	if (exponent < 0)	ans = 1/ ans;
    	return ans;	
    }
};
/*
	给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
	保证base和exponent不同时为0

	最直观的方法就是第一种
	第二种是经典快速幂

*/
class Solution {
public:
    double Power(double base, int exponent) {
    	int exp = abs(exponent);
    	double ans = 1;
    	while (exp){
    		if (exp & 1)  ans *= base;//exp是奇数
    		base *= base;
    		exp >>= 1;
    	}
    	if (exponent < 0)	ans = 1/ans;
    	return ans;
    }
};