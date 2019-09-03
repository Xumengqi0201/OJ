class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
      	for (int i = 0; i < s.size(); i++){
      		if (isupper(s[i])){
      			s[i] = tolower(s[i]);
      		}
      	}
      	while (i <= j){
      		bool flag1 = islower(s[i]) || isdigit(s[i]);
      		bool flag2 = islower(s[j]) || isdigit(s[j]);
      		if (flag1 && flag2){
      			if (s[i] != s[j])	return false;
      			i++;
      			j--;
      		}
      		else if (flag1){
      			j--;
      		}
      		else if (flag2){
      			i++;
      		}
      		else{
      			i++;
      			j--;
      		}
      	}
        return true;
    }
};