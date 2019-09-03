#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int checksum[11] = { 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2 };//把X用10代替
const int weightList[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

bool checkid(const string &id) {
	bool res = true;
	//1.check isdigit
	for (int i = 0; i < 17; i++) {
		if (isdigit(id[i]) == false) {
			res = false;
		}
	}
	//2.check z
	if (res == true) {
		int s = 0;
		for (int i = 0; i < 17; i++) {
			int num = id[i] - '0';
			s += weightList[i] * num;
		}
		int z = s % 11;
		if (id[17] == 'X') {
			if (checksum[z] != 10) {
				res = false;
			}
		}
		else if (checksum[z] != id[17]-'0') {
			res = false;
		}
	}

	return res;
}
int main() {
	int n;
	cin >> n;
	string id;
	bool all_passed = true;

	for (int i = 0; i < n; i++)
	{
		cin >> id;
		if (checkid(id) == false) {
			all_passed = false;
			cout << id << '\n';
		}
	}

	if (all_passed == true) {
		cout << "All passed\n";
	}

	return 0;
}