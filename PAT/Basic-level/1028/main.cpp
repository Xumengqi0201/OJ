#include <iostream>
#include <string>

using namespace std;

class People {
public:
	string name;
	string birthday;
	People(string n, string b) {
		name = n;
		birthday = b;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, cnt = 0;
	cin >> N;
	People oldest("#", "2014/09/07"), youngest("#", "1814/09/05");

	for (int i = 0; i < N; i++) {
		string name, birthday;
		cin >> name >> birthday;
		if ((birthday > "1814/09/05") && (birthday < "2014/09/07")) {
			cnt++;
			People p(name, birthday);
			if (birthday > youngest.birthday) {
				youngest = p;
			}
			if (birthday < oldest.birthday) {
				oldest = p;
			}
		}

	}

	cout << cnt;
	if (cnt > 0)
		cout << ' ' << oldest.name << ' ' << youngest.name;
	return 0;

}