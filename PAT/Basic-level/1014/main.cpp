# include <iostream>
# include <string>
# include <cctype>

using namespace std;

bool isday(char ch){
	return ch>='A' && ch<='G';
}

bool ishour(char ch){
	return ch>='A' && ch<='N' || isdigit(ch);
}

bool isletter(char ch){
	return islower(ch)||isupper(ch);
}

int main(){
	string s1,s2,s3,s4;
	const string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	bool isfind_week=false;
	cin>>s1>>s2>>s3>>s4;


	int len1=s1.size();
	int len2=s2.size();
	int len3=s3.size();
	int len4=s4.size();

	for (int i=0;i<len1 && i<len2;i++){
		if (s1[i]==s2[i]){
			if ( isday(s1[i])&&(isfind_week==false) ){
				int tmp=s1[i++]-'A'; //[i++]关键，否则的话下一个if在当前就成立了
				cout<<week[tmp]<<" ";
				isfind_week=true;
			}

			if (ishour(s1[i]) && isfind_week==true){
				if (isdigit(s1[i]))
					cout<<'0'<<s1[i]<<":";
				else
					cout<<s1[i]-'A'+10<<":";
				break;
			}
		}
	}

	for (int i=0;i<len3 && i<len4;i++){
		if (s3[i]==s4[i]){
			if (isletter(s3[i] )){
				if (i<10)
					cout<<'0';
				cout<<i;
				break;
			}
		}
	}

	return 0;
}