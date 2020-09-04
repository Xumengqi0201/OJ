/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

/*
  求字符串的最长回文子串
  1.DP:
  if p[i][j] = 1, then s[i...j] is palindrome
  if p[i+1][j-1] = 1 && s[i] == s[j], then p[i][j] = 1
  base:
  	 p[i][i] = 1;
  	 p[i][i+1] = 1 if s[i] = s[i+1];


*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "")    return "";
        bool **dp = new bool*[s.size()];
        for (int i = 0; i < s.size(); i++){
            dp[i] = new bool[s.size()];
            memset(dp[i], 0, s.size()*sizeof(bool));
        }
        
        for (int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        for (int i = 0; i < s.size()-1; i++){
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        //前面考虑了长度为1和2的回文串，下面从长度为3的开始考虑
        
        for (int len = 3; len <= s.size(); len++){
            for (int i = 0; i < s.size()-len+1; i++){
                int j = i+len-1;
                if (dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                }
            }
        }
               
        
        
        int maxlen = 0, start;
        for (int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if (dp[i][j] == 1){
                    if (j-i+1 > maxlen){
                        maxlen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxlen);
        
        
        
    }
};

/*
2.中心扩散 O（N2）
class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "")    return "";
        int maxlen = 0, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
           	//每次扩散有两种方法，以i为中心或者以i，i+1为中心
           	int l1 =  center(s, i, i);
            int l2 = center(s, i ,i+1);
            int len1 = 2*(i-l1)+1;
            int len2 = 2*(i-l2)+2;
            if (maxlen < len1){
                maxlen = len1;
                start = l1;
            }
            if (maxlen < len2){
                maxlen = len2;
                start = l2;
            }
            
        }
        
        return s.substr(start, maxlen);
    }
    int center(const string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return left+1;
    }
};

*/