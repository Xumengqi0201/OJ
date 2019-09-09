class Solution {
private:
	void dfs(vector <string> &ans, int start, string &str){
		if (start >= str.size()){
			ans.push_back(str);
		}
		for (int i = start; i < str.size(); i++){
			if (i != start && str[start] == str[i])   continue;
			swap(str[start], str[i]);
			dfs(ans, start+1, str);
			swap(str[start], str[i]);
		}
	}
public:
    vector<string> Permutation(string str) {
        vector <string> ans;
        if (str == "")	return ans;
        dfs(ans, 0, str);
        return ans;
    }
};
/*
	全排列字符串，字符串中可能有重复的字符
	第一种方法是对的，但是牛客变态的要求结果和它一样
	所以只能修改一下
	
	用例:
	abc

	对应输出应该为:

	["abc","acb","bac","bca","cab","cba"]

	你的输出为:

	["abc","acb","bac","bca","cba","cab"]



*/

class Solution {
private:
	void dfs(vector <string> &ans, int start, string str, string tmp){
		if (start == str.size()){
			ans.push_back(tmp);
			return;
		}
		for (int i = start; i < str.size(); i++){
			//一层一个字符只能用一次
			if (i != start && str[start] == str[i])   continue;
			swap(str[start], str[i]);
			tmp += str[start];
			dfs(ans, start+1, str, tmp);
			tmp.pop_back();
		}
	}
public:
    vector<string> Permutation(string str) {
        vector <string> ans;
        if (str == "")	return ans;
        string tmp = "";
        dfs(ans, 0, str, tmp);
        return ans;
    }
};