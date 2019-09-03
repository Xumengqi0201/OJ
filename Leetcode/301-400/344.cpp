class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        for (; left < right; left++, right--){
        	char tmp = s[left];
        	s[left] = s[right];
        	s[right] = tmp;
        }
    }
};