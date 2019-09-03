class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if ( n <= 0)	return false;
        while (n > 2){
        	if (n % 2 != 0)		return false;
        	n = n/2;
        }
        return true;
    }
};
//判断是不是2的幂，考虑0和负数的情况。