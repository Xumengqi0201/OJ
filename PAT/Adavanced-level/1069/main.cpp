#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	1.给定的数字按照non-increasing拍序，再按照non-decreasing排序。将两次排序得到后的数字相减，直到得到6174
	2.需要两个int和string相互转化的函数，方便调用sort排序。
	3.即使输入的是6174，也要进行7641 - 1467 = 6174。所以应该用do-while循环
	4.如果运算结果是0，直接跳出循环(对应四个数字都相同的情况)
	5.注意输出的数字全是4位的，不全的用0补全
	6.如果输入的数字不是4位，要用stringstream 将其设置为4位
*/


string int_str(int n){
	stringstream ss;
	ss << setw(4) << setfill('0') << n; 
	//if 输入的是1 ，那么对应的字符串应该是0001 
	return ss.str();
}

int str_int (string &n){
	stringstream ss;
	ss << n;
	int res;
	ss >> res;
	return res;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n1, n2, tmp;
	string s;
	cin >> s;
	stringstream ss;
	ss << setw(4) << setfill('0') << s;
	ss >> s;
	do{
		string s1 = s;
		string s2 = s;
		sort(s1.begin() , s1.end() , greater<char>());
		n1 = str_int(s1);
		sort(s2.begin() , s2.end() , less<char>());
		n2 = str_int(s2);
		tmp = n1 - n2;
		cout << s1 << " - " << s2 << " = ";
		cout << setw(4) << setfill('0') << tmp << '\n';
		if (tmp == 0) break;
		s = int_str(tmp);
	}while (tmp != 6174);

	return 0;

}