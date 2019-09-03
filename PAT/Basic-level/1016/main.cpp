# include <iostream>
# include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string A,B;
	int DA,DB,cnt1=0,cnt2=0;
	cin>>A>>DA>>B>>DB;
	int len1=A.size();
	int len2=B.size();

	for (int i=0;i<len1;i++){
		if ((A[i]-'0')==DA)
			cnt1++;
	}

	for (int i=0;i<len2;i++){
		if ((B[i]-'0')==DB)
			cnt2++;
	}

	int sum1=0,sum2=0;
	for (int i=0,base=1;i<cnt1;i++,base*=10)
		sum1+=DA*base;
	for (int i=0,base=1;i<cnt2;i++,base*=10)
		sum2+=DB*base;

	cout<<sum1+sum2;

	return 0;
}