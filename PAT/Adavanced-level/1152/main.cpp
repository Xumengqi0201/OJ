#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

bool isprime(int n){
	bool res=true;
	int end=sqrt(n);
	for (int i=2;i<=end;i++){
		if (n%i==0){
			res=false;
			break;
		}
	}

	return res;
}

int str_to_num(string s){
	stringstream ss;
	ss<<s;
	int res;
	ss>>res;
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len,k;
	bool find =false;
	cin>>len>>k;
	string s;
	cin>>s;
	
	int end=len-k;
	for (int i=0;i<=end;i++){
		string sub = s.substr(i,k);
		int num = str_to_num(sub);
		if (isprime(num)){
			cout<<sub<<'\n';
			find=true;
			break;
		}
	}

	if (find==false){
		cout<<"404\n";
	}


	return 0;
}