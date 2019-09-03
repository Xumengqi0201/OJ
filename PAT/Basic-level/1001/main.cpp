# include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n = 0, count = 0;
	cin >> n;
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2;
		else
			n = (3 * n + 1) / 2;

		count++;
	}

	cout << count;



}