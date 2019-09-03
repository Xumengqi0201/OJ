# include <iostream>
# include <string>
# include <sstream>

using namespace std;

string num_str(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string A,res;
	int B，r=0,len=A.size();
	cin>>A>>B;
	for (int i=0;i<len;i++){
		int a=A[i]-'0'+r*10;
		int q=a/B;
		r=a%B;
		res.push_back(num_str(q));
	}

	if (res[0]!='0'||res.size()==1)
		cout<<res;
	else
		cout<<&res[1];

	return 0;


}