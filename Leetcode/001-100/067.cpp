class Solution {
public:
    string addBinary(string a, string b) {
       int carry = 0;//carry一般用来表示进位
       int i = a.size()-1, j = b.size()-1;
       string res = "";
       while(i >=0 || j >= 0)
       {
       		//如果i小于0，说明a已经遍历结束了，剩下的当成0处理。不一定要把两个字符串先设成一样长
       		int p = i >= 0 ? a[i--]-'0' : 0;
       		int q = j >= 0 ? b[j--]-'0' : 0;
       		int sum = p+q+carry;
       		res = to_string(sum%2) + res;//sum对2取余数是当前位置的数字
       		carry = sum /2;//sum对2取商是进位
       		//这里余数和商不太容易想清楚，其实和十进制是一样的
       }

       if (carry == 1)	res = '1' + res;
       return res;
    }
};
