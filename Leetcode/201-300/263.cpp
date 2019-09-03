class Solution {
public:
    bool isUgly(int num) {
        while(num >= 2){
        	if (num % 2 == 0)	num /= 2;
        	else if (num % 3 == 0)	num /=3;
        	else if (num % 5 == 0)	num /= 5;
        	else return false;
        	
        }
        return num == 1;
    }
};
//这么简单的题居然开始做错了，猪脑子，呜呜～～