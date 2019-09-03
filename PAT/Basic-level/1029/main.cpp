#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	int charmap[100] = { 0 };
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	for (int i=0;i<len2;i++){
		char ch =toupper(s2[i]);
		charmap[ch]++;
	}
	for (int i=0;i<len1;i++){
		char ch =toupper(s1[i]);
		if (charmap[ch]==0){
			cout<<ch;
			charmap[ch]++;
		}
	}
	
	return 0;
}