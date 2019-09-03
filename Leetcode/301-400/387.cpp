class Solution {
public:
    int firstUniqChar(string s) {
        int table[26] = {0};
        int index;
        for (int i = 0; i < s.size(); i++){
        	table[s[i]-'a'] ++;
        }
        for (int i = 0; i < s.size(); i++){
        	if (table[s[i]-'a'] == 1){
        		return i;
        	}
        }
        return -1;
    }
};//

//easy的题也不能一次写对，sad