/*
	slide window 
	设置两个下标i和j
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bool ch_map[256] = {0};

       	for (int i = 0, j = 0; i < s.size() && j < s.size() ; ){
       		if (ch_map[s[j]] == 0){
       			ch_map[s[j]] = 1;
       			j++;
       			ans = max(j-i, ans);
       		}else{
       			ch_map[s[i]] = 0;
       			i++;
       		}
       	}
        return ans;
    }
};