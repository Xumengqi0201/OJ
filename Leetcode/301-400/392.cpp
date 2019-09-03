class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int i = 0;
    	for (int j = 0; j < t.size() && i < s.size(); j++){
    		if (s[i] == t[j])	i++;
    	}
        return i == s.size();
    }
};
/*
判断s是不是t的子串是比较简单的，但是如果t很长而且要多次判断不同的s是不是在t中
那么就不能这么做了。
需要建立一个hashmap，建立t中元素和位置对应的关系，由于可能有多个相同的元素，所以位置应该是一个有序数组
建立完hashmap后，需要二分搜索位置数组

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
    	unordered_map< char, vector<int> > hash;
    	int pre = -1; 
    	for (int i = 0; i < t.size(); i++){
    		hash[t[i]].push_back(i);
    	}
    	for (int i = 0; i < s.size(); i++){
    		//二分查找到第一个大于等于pre的位置left
    		int left = 0, right = hash[s[i]].size()-1;
    		while (left < right){
    			int mid = left + (right-left)/2;
    			if (hash[s[i]][mid] < pre)	left = mid+1;
    			else 	right = mid;
    		}
    		if (left >= hash[s[i]].size())	return false; //检查下标
    		
    		int tmp = hash[s[i]][left];
    		if (tmp < pre)	return false;
    		else if (tmp > pre)		pre = tmp;
    		else if (left+1 < hash[s[i]].size())	pre = hash[s[i]][left+1];
    		else return false;	
    	}
    	return true;
    }

};