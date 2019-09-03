# include <iostream>
# include <cmath>
using namespace std;

bool isprime(int num) {
	bool res = true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			res = false;
			break;
		}
	}
	return res;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, cnt = 0;
	cin >> N;
	for (int num = 2; num <= N - 2; num++) {
		if (isprime(num) && isprime(num + 2))
			cnt++;
	}
	cout << cnt;

	return 0;


}