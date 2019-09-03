class Solution {
public:
    int longestPalindrome(string s) {
       	unordered_map < char, int > hash;
       	int res = 0;
       	bool flag = false;
        for (auto ch : s)	hash[ch]++;
        unordered_map <char, int> :: iterator iter;
    	for (iter = hash.begin(); iter != hash.end(); iter++){
    		if (iter->second % 2 == 0)	res += iter->second;
    		else {
    			res += iter->second-1;
    			flag = true;
    		}
    		
    	}
    	//这一行写的好聪明哈哈，如果有奇数最后再补上1就行了
    	return res+flag;
    }
};