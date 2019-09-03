# include <iostream>
# include <sstream>
# include <string>
using namespace std;

int str_num(string s){//字符串转为数字
	stringstream ss;
	ss<<s;
	int res;
	ss>>res;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string mystr,tmp;
	int start=1;
	getline(cin,mystr);
	stringstream ss(mystr);

	while(!ss.eof()){
		getline(ss,tmp,' ');
		int coef=str_num(tmp);
		getline(ss,tmp,' ');
		int expo = str_num(tmp);

		if (coef*expo){
			if (start==0)
				cout<<' ';
			else
				start=0;
			cout<<coef*expo<<' '<<expo-1;
		}
	}

	if (start)
		cout<<"0 0";

	return 0;
}