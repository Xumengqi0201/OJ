class Solution {
public:

	bool isHappy(int n) {
	    int cnt = 0;
	    int sum = 0;
	    while (cnt <= 10) {
	        while (n) {
	            sum = sum + (n % 10) * (n % 10);
	            n = n / 10;
	        }
	        if (sum == 1) return true;
	        n = sum;
	        cnt++;
	        sum = 0;
	    }
	    return false;
	}

};