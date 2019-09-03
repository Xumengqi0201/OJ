# include <iostream>
# include <sstream>
# include <string>
using namespace std;

string num_str(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

int main(){
	int n;
	cin>>n;
	string str = num_str(n);
	int str_len=str.size();
	if (str_len==3){
		int bai=str[0]-'0';
		for (int i=0;i<bai;i++)
			cout<<'B';
		int shi=str[1]-'0';
		for (int i=0;i<shi;i++)
			cout<<'S';
	}

	else if (str_len==2){
		int shi=str[0]-'0';
		for (int i=0;i<shi;i++)
			cout<<'S';
	}

	int ge=str.back()-'0';
	for (int i=1;i<=ge;i++)
		cout<<i;

	return 0;
	
}