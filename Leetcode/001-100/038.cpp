class Solution {
public:
    string countAndSay(int n) {
    	string s1 = "1", s2 = "1";
    	for (int i = 1; i < n; i++)
    	{
    		s2 = gen_string(s1);
    		s1 = s2;
    	}
        return s2;
    }
    string gen_string(string s){
    	string res;
    	for (int i = 0, j = 0; j < s.size();){
    		while (s[i] == s[j]){
    			j++;
    		}
    		res.push_back(j-i+'0');
    		res.push_back(s[i]);
    		i = j;
    	}
    	return res;
    }
};