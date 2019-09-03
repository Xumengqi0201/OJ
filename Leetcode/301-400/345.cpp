class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
        	if (isVowel(s[left]) && isVowel(s[right])){
        		swap(s[left++], s[right--]);
        	}
        	else if(isVowel(s[left])){
        		right--;
        	}
        	else{
        		left++;
        	}
        }
        return s;
    }
    bool isVowel(char ch){
    	return ch =='a' || ch == 'e' ||ch == 'i'|| ch == 'o' ||ch == 'u'||ch =='A' ||ch == 'E' ||ch == 'I'||ch == 'O'||ch =='U'; 
    }
};
//交换字符串中的元音字母：a,e,i,o,u还有大写