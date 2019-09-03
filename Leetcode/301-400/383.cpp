class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> hash;
        for (auto ch : magazine)	hash[ch]++;
        for (auto ch : ransomNote){
        	//这一行还是写的很不错的
        	if (--hash[ch] < 0)	return false;
        }
        return true;
    }
};
//easy