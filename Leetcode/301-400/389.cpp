class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26] = {0};
        char res;
        for (int i = 0; i < s.size(); i++)	hash[s[i]-'a']++;
        for (int i = 0; i < t.size(); i++){
        	if (--hash[t[i]-'a'] < 0){
        		res = t[i];
        		break;
        	}
        }
        return res;
    }
};