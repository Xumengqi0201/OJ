class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())	return false;
        char table[26] = {0};
        for (int i = 0; i < s.size(); i++){
        	table[s[i]-'a']++;
        	table[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++){
        	if (table[i] != 0)	return false;
        }
        return true;
    }
};
//Anagram : 将组成一个词或短句的字母重新排列顺序，原文中所有字母的每次出现都被使用一次，这样构造出另外一些新的词或短句。