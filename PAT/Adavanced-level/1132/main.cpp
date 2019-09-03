#include <iostream>
#include <string>

using namespace std;

bool isvalid(string & number){
	bool res = false;
	int len = number.size();
	int k = len / 2;
	int a = 0 , b = 0 , n = 0;
	for (int i = len-1 , base = 1 ; i >= k ; i-- , base*=10)
	{
		b += (number[i]-'0')*base;
	}
	for (int i = k - 1 , base =1 ; i >= 0 ; i-- , base*=10)
	{
		a += (number[i]-'0')*base;
	}

	n = a;
	for (int i = 0 ; i < k ; i++)
	{
		n *=10;
	}
	n += b;
	int tmp = a*b;
	if ( tmp != 0 && n%tmp == 0){
		res = true;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	string number;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> number;
		if (isvalid(number)){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}