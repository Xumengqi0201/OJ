
/*
	1.设置两个指针i和j，j-i+1是字符串的长度
	2.设置一个数组book[256](asc有256个字符)来记录当前的字符之前有没有出现过
	3.设置maxlen来保存最大子串的长度，对每个字符都要判断有没有出现过。如果出现过，
	说明需要将i的位置往后挪，并更新一下最大长度。
	4.对于当前出现过的字符有两种可能：
		a.他和s[i]相等，那么把i的位置向后挪一位即可
		b.和s[i]不相等，那么肯定和子串之间的某一个字符相等。从i向后找直到s[i]!=s[j]
		  并修改一下s[i]的标记位
	5.不能直接返回maxlen，有可能遍历过程中maxlen一直没有得到更新（字符串的每个字符都不一样）
	所以跳出循环后需要更新maxlen。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j= 0, maxlen = 0;
        char book[256] = {0};
        while(j < s.length){
        	if (book[s[j]] == 1){
        		//substring遇到出现过的字符更新最大长度
        		maxlen = max(maxlen, j-i);
        		while(s[i] != s[j]){
        			book[s[i]] = 0;
        			i++;
        		}
        		i++;
        	}
        	else{
        		book[s[j]] = 1;
        	}

        	j++;
        }

        return max(maxlen,j-i);
    }
};