#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

/*
1.a,b根据题目给出的范围，a,b,c都在int型范围内
2.如果c是负数先输出符号，然后对c取绝对值;如果fabs(c)在1000以内直接输出，否则通过num_str()把数字转换为字符串处理
3.将数字的长度对3取余，先把第一个commmas之前的字符串输出，用substr
4.之后每三个数字就输出子串，数字尾巴的commas不输出。

*/
string num_str(int n) {
	stringstream ss;
	string res;
	ss << n;
	ss >> res;
	return res;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

-	int a, b;
	cin >> a >> b;
	int c = a + b;
	if (c < 0) {
		cout << '-';
	}
	c = fabs(c);
	if (c < 1000)
	{
		cout << c;
	}
	else
	{
		string str = num_str(c);
		int len = str.size();
		int first_commas = len % 3;
		if (first_commas == 0)
		{
			first_commas = 3;
			string sub = str.substr(0, 3);
			cout << sub << ',';
		}
		else
		{
			string sub = str.substr(0, first_commas);
			cout << sub << ',';
		}
		/*
		-eg：999,999
		1.先输出“999,” 
		2.start = 3,3+2 <6,接下来的子串的最后一个字符的下标索引要小于len
		3.每输出一个子串，i+3，即下一个子串首字母的起始位置。
		*/

		for (int i = first_commas; i + 2 < len; i+=3)
		{
			string sub = str.substr(i, 3);
			cout << sub;
			if ((i + 2) != len - 1) {
				cout << ',';
			}
		}


	}


	return 0;
}