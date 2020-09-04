class Solution {
public:
	void replaceSpace(char *str,int length) {
		if (str == NULL)		return;
		int cnt = 0;//space数量
		//c字符串以'\0'结尾
		for (int i = 0; str[i] != '\0'; i++){
			if (str[i] == ' ')	cnt++;
		}
		int newlength = length + 2*cnt;
		for (int i = length-1, j = newlength-1; i >=0 &&j >=0;){
			if (str[i] != ' '){
				str[j--] = str[i--];
			}
			else{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
				i--;
			}
		}
	}
};
/*
	双指针法
	要求：把c字符串中的空格替换成%20
	正常想法：遇到空格用 '%20'替换，这需要将后面所有的字符移动两位，这种算法的复杂度O(N*N);
	所以肯定是不行的，所以调整思路：
	1.计算替换后的字符串的长度，一个空格就要多两个字符，所以新字符串长度等于原字符串长度+2*空格数
	2.两个指针i和j分别指向原来字符串最后一个位置和新字符串最后一个位置，再迁移

	注意j>=i，所以不存在字符覆盖的问题
	改进后的复杂度：O(n)	

*/
