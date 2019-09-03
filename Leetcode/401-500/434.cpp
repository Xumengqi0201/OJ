class Solution {
public:
    int countSegments(string s) {
  		int cnt = 0, up = s.size()-1;
  		for (int i = 0; i < up; i++){
  			if (s[i] != ' ' && s[i+1] == ' ')	cnt++;
  		}
  		//上一个字符不为空且下一个字符为空，说明前面有一个segment
  		//如果最后一个字符不为空，那么segment的数量还要再加1
  		if (s.size() && s[up] != ' ')	cnt++;
  		return cnt;      
    }
};