class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map <char, string> hash1;
        unordered_map <string, char> hash2;
        stringstream in(str);
        int i = 0;
        for(string substr; in >> substr; i++){
        	int cnt1 = hash1.count(pattern[i]);
        	int cnt2 = hash2.count(substr);
        	if (cnt1 == 0 && cnt2 == 0){
        		hash1[pattern[i]] = substr;
        		hash2[substr] = pattern[i];
        	}
        	else if (cnt1 + cnt2 == 1){
        		return false;
        	}
        	else if (hash1[pattern[i]] != substr || hash2[substr] != pattern[i]){
        		return false;
        	}

        }
        if (i != pattern.size())	return false; //注意ｉ必须要到最后一个位置，有可能str就一个单词
        return true;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Word Pattern.
*/