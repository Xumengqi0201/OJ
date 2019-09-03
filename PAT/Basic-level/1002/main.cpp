# include <iostream>
# include <cmath>
# include <string>
# include <vector>
using namespace std;

int main(){
	const string arr[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string number;
	int sum=0;
	vector <int> vec;

	cin>>number;
	int str_len=number.size();
	for (int i=0;i<str_len;i++){
		sum += (number[i]-'0');
	}


	while(sum!=0){
		digit= sum%10;
		vec.push_back(digit);
		sum = sum/10;
	}

	for (vector <int>::iterator iter = vec.end(); iter !=vec.begin();){
		cout<<arr[*(--iter)];
		if (iter!=vec.begin())
			cout<<' ';
	}

	return 0;
}
