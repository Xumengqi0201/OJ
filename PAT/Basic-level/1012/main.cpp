#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a[5] = { 0,0,0,0,0, };
	int N = 0;
	bool exist[5] = { false,false,false,false,false, };
	int sign2 = 1, cnt4 = 0;

	cin >> N;
	for (int c = 0; c < N; c++) {
		int i = 0;
		cin >> i;
		if (i % 5 == 0) {
			if (i % 2 == 0) {
				exist[0] = true;
				a[0] += i;
			}
		}

		else if (i % 5 == 1) {
			exist[1] = true;
			a[1] += sign2 * i;
			sign2 = -sign2;
		}

		else if (i % 5 == 2) {
			exist[2] = true;
			a[2]++;
		}

		else if (i % 5 == 3) {
			exist[3] = true;
			a[3] += i;
			cnt4++;
		}
		else if (i % 5 == 4) {
			exist[4] = true;
			if (i > a[4])
				a[4] = i;
		}
	}

	a[3] = a[3] / cnt4;
	for (int i = 0; i < 5; i++) {
		if (exist[i] == true) {
			if (i == 3)
				cout << fixed << setprecision(1) << a[i];
			else
				cout << fixed << setprecision(0) << a[i];
		}
		else
			cout << 'N';
		if (i != 4)
			cout << ' ';
	}

	return 0;
}
