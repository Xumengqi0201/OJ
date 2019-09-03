#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int number){
	bool res=true;
	for (int i=2;i<=sqrt(number);i++){
		if (number%i==0){
			res=false;
			break;
		}
	}

	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M,N,num=1;
	cin>>M>>N;

	int cnt=0;
	while(cnt<M){
		num++;
		if (isprime(num)){
			cnt++;
		}
	}

	for (cnt=0;cnt<N-M+1;){
		if (isprime(num)){
			cnt++;
			cout<<num;
			if (cnt!= N-M+1){
				if (cnt%10!=0)
					cout<<' ';
				else 
					cout<<endl;
			}
		}
		num++;
	}

	return 0;
}