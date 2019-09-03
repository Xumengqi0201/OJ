/*
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int strs_size=strs.size();

        if (strs_size==0)
        	return prefix;
        else if(strs.size()==1)
        	return strs[0];

        int min_size=strs[0].size();//找出strs中的最短string的length，否则接下来还要重复遍历
        char tmp;
        for (int i=0;i<strs_size;i++){
        	if (strs[i].size()<min_size)
        		min_size=strs[i].size();
        }

        for (int j=0;j<min_size;j++){
        	tmp=strs[0][j];
        	for (int i=1;i<strs_size;i++){
        		if(strs[i][j]!=tmp)
        			return prefix;
        	}
        	prefix.push_back(tmp);
        }
        return prefix;
    }
};