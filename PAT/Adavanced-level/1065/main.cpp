#include <iostream>

using namespace std;
/*
	1.a > 0 && b > 0 && sum <= 0 : a+b上溢
	2.a < 0 && b < 0 && sum >= 0 : a+b下溢
	3.a和b异号，sum肯定不会溢出，此时判断sum和c谁大就好
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long a,b,c,sum;
	int t;
	cin >> t;
	for (int i = 0 ; i < t ; i++)
	{
		cin >> a >> b >> c;
		sum = a+b;
		cout << "Case #" << i+1 <<": ";
		if (a > 0 && b > 0 && sum <= 0){
			cout << "true\n";
		}
		else if (a < 0 && b < 0 && sum >= 0){
			cout << "false\n";
		}
		else if (sum >c){
			cout << "true\n";
		}
		else{
			cout << "false\n";
		}
	}

	return 0;
}

