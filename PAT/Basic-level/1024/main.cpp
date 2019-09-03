#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int str_num(string str) {
	stringstream ss;
	ss << str;
	int n;
	ss >> n;
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int E, E_location;
	cin >> s;

	int len = s.size();
	if (s[0] == '-') {
		cout << '-';
	}
	for (int i = 0; i < len; i++) {
		if (s[i] == 'E') {
			E_location = i;
			string sub_str = s.substr(i + 1); //从'E'开始往后的子串
			E = str_num(sub_str);
			break;
		}
	}

	if (E == 0) {
		cout << s.substr(1, E_location - 1);
	}
	else if (E < 0) {
		E = -E;
		E--;
		cout << "0.";
		for (int i = 0; i < E; i++) {
			cout << '0';  //前面输出E-1个0
		}
		for (int i = 1; i < E_location; i++) {
			if (s[i] == '.') {
				continue;  //输出符号位后面的数字，遇到`.`跳过，因为前面已经输出了小数点
			}
			cout << s[i];
		}
	}
	else
	{
		for (int i = 1; i < E_location; i++) {
			if (s[i] == '.') {
				continue;
			}
			cout << s[i];
			if (i == (E+2) && (i!=E_location-1)) {
				cout << '.';  //如果所有的数字都输出了，小数点不用输出；否则小数点在E+2的位置输出
			}
		}

		int up = E - E_location + 3;
		for (int i = 0; i < up; i++) {
			cout << '0';
		}

	}

	return 0;
}