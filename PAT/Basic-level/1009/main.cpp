# include <iostream>
# include <string>
# include <sstream>
# include <stack>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack <string> sta;
	string mystr;
	getline(cin,mystr);
	stringstream ss(mystr);

	while(!ss.eof()){
		getline(ss,mystr,' ');
		sta.push(mystr);
	}

	cout<<sta.top();
	sta.pop();
	while(!sta.empty()){
		cout<<' '<<sta.top();
		sta.pop();
	}

	return 0;
}