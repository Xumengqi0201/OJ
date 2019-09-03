/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
class Solution {
public:
    int reverse(int x) {
        int result=0;
        while(x!=0){
	        int tmp1=result<<3;
	        int tmp2=result<<1;
	        int tmp=tmp1+tmp2;
	        result=tmp+x%10;
	        if ((x>0&&(tmp1<0||tmp2<0||tmp<0||result<0))||(x<0&&(tmp1>0||tmp2>0||tmp>0||result>0)))
	            return 0;
	        x=x/10;
    	}
        return result;
    }
};