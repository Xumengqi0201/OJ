class Solution {
public:
     int  NumberOf1(int n) {
         int flag = 1, ans = 0;
         while(flag){
         	if (n & flag)	ans++;
         	flag = flag << 1;
         }
         return ans;
     }
};
/*
	计算二进制数中1的个数，
	第一种方法是最直观的方法，要计算32次
	第二种就是找规律了，最优解法一般想不出来


*/
class Solution {
public:
     int  NumberOf1(int n) {
        int ans = 0;
        while(n){
        	ans++;
        	n = (n-1)&n; //会把整数最右边一个1变为0
       }
       return ans;
     }
};