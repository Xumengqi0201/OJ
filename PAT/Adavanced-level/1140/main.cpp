#include <iostream>
#include <string>

using namespace std;

string get_next(string &s){
	string res;
	int len = s.size();
	int i,j;
	for (i = 0 ; i < len ; i = j){
		char ch = s[i];
		int cnt =1;
		for (j = i+1 ; j < len ; j++){
			if (ch == s[j]){
				cnt++;
			}
			else{
				break;
			}
		}
		res.push_back(ch);
		char c_cnt = cnt + '0';
		res.push_back(c_cnt);
	}
	return res;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int digit , n;
	cin >> digit >> n;
	string s , next;
	char di = digit + '0';
	s.push_back(di);


	for (int i = 1 ; i < n ; i++)
	{
		next = get_next(s);
		s = next;
	}

	if (n == 1){
		next = s;
	}

	cout << next << '\n';

	return 0;
}