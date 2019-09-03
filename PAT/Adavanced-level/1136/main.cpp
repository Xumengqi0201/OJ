#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
	必须采取字符串相加的形式对两个数相加，否则会大数溢出，因为题目中说了每个数的位数不会超过1000

*/
//字符串形式的数字相加，避免大数溢出
string add(string &s1 , string &s2)
{
	string res = s1;
	int carry = 0;
	int len = s1.size();
	for (int i = len - 1 ; i >= 0 ; i--)
	{
		res[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
		carry = (s1[i] - '0' + s2[i] - '0' + carry ) / 10;
	}
	if (carry > 0)
	{
		/*
			1. "+"将两个字符串连接起来 
			2.eg. res = "123" ,res+"1" = "1231" , "1"+res = "1123" 
		*/
		res = "1" + res; 
	}
	return res;
}

string rev(string n)
{
	reverse(n.begin() , n.end()); //algorithm库中的reverse函数可以直接对string翻转
	return n;
}

int main()
{
	string n;
	cin >> n;
	if (rev(n) == n)
	{
		cout << n << " is a palindromic number." << '\n';
		return 0;
	}

	for (int i = 0 ; i < 10 ; i++)
	{
		string rev_n = rev(n);
		string sum = add(rev_n , n);
		cout << n << " + " << rev_n << " = " << sum << '\n';
		if (rev(sum) == sum )
		{
			cout << sum << " is a palindromic number." << '\n';
			return 0;
		}
		n = sum;
	}
	cout << "Not found in 10 iterations." << '\n';

	return 0;
}