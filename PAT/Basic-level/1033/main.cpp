#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int symbol[100] = { 0 };
	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	int len1 = s1.size();
	int len2 = s2.size();

	if (len1 == 0) {
		cout << s2;
	}

	else {
		for (int i = 0; i < len1; i++)
		{
			char ch = s1[i];
			if ( islower(ch) )
			{
				ch = toupper(ch);
			}
			symbol[ch] = 1;   //坏掉的字符标 1 
		}

		bool hasoutput = false;
		for (int i = 0; i < len2; i++)
		{
			char ch = s2[i];
			if (islower(ch)) {  //小写字母转化为大写字母判断
				char tmp = toupper(ch);
				if (symbol[tmp] == 1) {
					continue;
				}
			}
			else if (isupper(ch) && symbol['+'] == 1) //key没坏的情况下是大写字母，还要判断上档键有没有坏
			{
				continue;
			}
			else if (symbol[ch]) { //要么是大写字母要么是字符，直接下标判断
				continue;
			}
			cout << ch;
			hasoutput = true;
		}

		if (hasoutput == false) {
			cout << '\n';
		}

	}

	return 0;
}