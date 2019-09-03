class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s.size() != t.size())	return false;
    	char chmaps[260] = {0}, chmapt[260] = {0};
    	for (int i = 0; i < s.size(); i++){
    		if (chmaps[s[i]] == 0 && chmapt[t[i]] == 0){
    			chmaps[s[i]] = t[i];
    			chmapt[t[i]] = s[i];
    		}
    		else if (chmaps[s[i]] == t[i] && chmapt[t[i]] == s[i])
    		{
    			continue;
    		}
    		else{
    			return false;
    		}

    	}
    	return true;
        
    }
};
//两张表一一对应，常用的256个字符