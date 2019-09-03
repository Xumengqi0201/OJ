/*
  注意，不能遇到' '就跳出，如果' '在最后一位，还要找前面的' '
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = s.size()-1; i >= 0; i--){
            if (s[i] == ' ' && cnt == 0)	continue;
            if (s[i] == ' ') break;
            cnt++;
        }

        return cnt;

    }
};