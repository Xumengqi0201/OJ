class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <1)	return false;
        while (num != 1){
        	if (num % 4 != 0)	return false;
        	num = num / 4;
        }
        return true;
    }
};
/*
判断是不是4的幂，
第一种纯粹是数学的方法，
第二种是从计算机性能来考虑的,除以4相当于右移2位，但是不能丢掉低位，所以先和3做位与
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
    	if (num < 1)	return false;
        while (!(num&0x3)){
        	num = num >> 2;
        }
        if (num == 1)	return true;
        return false;
    }
};