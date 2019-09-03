class Solution {
public:
    string convertToTitle(int n) {
    	string res = "";
    	while (n){
    		char ch = (n-1) % 26 +'A';
    		res  = ch + res;
    		n = (n-1) /26;
    	}
        return res;
    }
};