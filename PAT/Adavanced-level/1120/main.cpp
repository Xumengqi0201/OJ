#include <iostream>
#include <set>
#include <string>
using namespace std;

int sum_digits(string & number)
{
	int res = 0;
	int len = number.size();
	for (int i = 0; i < len; i++)
	{
		res += number[i] - '0';
	}
	return res;
}

int main()
{
	set<int> res;
	int n, sum, cnt = 0;
	string number;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		sum = sum_digits(number);
		res.insert(sum);
	}
	int len = res.size();
	cout << len <<'\n';
	for (set <int> ::iterator iter = res.begin(); iter != res.end(); iter++)
	{
		cout << *iter;
		if (cnt != len - 1)
		{
			cout << ' ';
		}
		cnt++;
	}
	cout << '\n';

	return 0;
}