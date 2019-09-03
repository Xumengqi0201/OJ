#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B, D;
	stack <int> s;
	cin >> A >> B >> D;
	long long sum = A + B; //sum,q定义为长整型，否则可能越界
	do {
		int r = sum % D;
		s.push(r);
		sum /= D;
	} while (sum !=0 );

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}