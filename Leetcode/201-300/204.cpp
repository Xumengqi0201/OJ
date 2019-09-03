class Solution {
public:
    int countPrimes(int n) {
        int sum = 0;
        for (int i = 2; i <=n ; i++){
        	if (isprime(i))	sum++;
        }
        return sum;
    }
    bool isprime(int n){
    	int up = sqrt(n);
    	bool flag = true;
    	for (int i = 2; i <= up; i++){
    		if (n % i == 0){
    			flag = false;
    			break;
    		}
    	}
    	return flag;
    }
};