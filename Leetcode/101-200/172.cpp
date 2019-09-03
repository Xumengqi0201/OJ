
class Solution {
public:
    int trailingZeroes(int n) {
    	int res = 0;
    	while (n){
    		int tmp = n/5;
    		res += tmp;
    		n = tmp;
    	}
    	
    	return res;
        
    }
};
/*
	求阶乘末尾0的个数，这一题千万不能先求阶乘，否则超时
	思路：0是由2×5产生的，一对2和5产生一个10，也就多一个0
		 2远远多于5，找出5的个数？？
*/