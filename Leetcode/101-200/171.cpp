class Solution {
public:
    int titleToNumber(string s) {
    	int res = 0;
    	for (int i  = s.size()-1; i >=0; i--){
    		int j = s.size()-1-i;
    		res += pow(26, j)*(s[i]-'A'+1);

    	}


    	return res;
        
    }
};