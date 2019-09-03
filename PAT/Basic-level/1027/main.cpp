#include <iostream>

using namespace std;

int main() {
	int N;
	char ch;
	cin >> N >> ch;
	int rnd = -1, total_star;
	do {
		rnd++;
		total_star = 2 * rnd*rnd + 4 * rnd + 1;
	} while (total_star <= N);
	rnd--;  //最长的一行有2*rnd+1个*
	int left = N - 2 * rnd*rnd - 4 * rnd - 1;

	for (int i = rnd, maxline = 2 * rnd + 1; i >= 0; i--) {
		int space = (maxline - 2 * i - 1) / 2;
		while (space > 0) {
			cout << ' ';
			space--;
		}
		for (int j = 0, s = 2 * i + 1; j < s; j++) {
			cout << ch;
		}
		cout << "\n";
	}

	for (int i = 1, maxline = 2 * rnd + 1; i <= rnd; i++) {
		int space = (maxline - 2 * i - 1) / 2;
		while (space > 0) {
			cout << ' ';
			space--;
		}
		for (int j = 0, s = 2 * i + 1; j < s; j++) {
			cout << ch;
		}
		cout << "\n";
	}
	
	cout << left;

	return 0;
}