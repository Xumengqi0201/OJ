# include <iostream>
# include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,M;
	vector <int> vec;
	cin>>N>>M;
	for (int i=0;i<N;i++){
		int num;
		cin>>num;
		vec.push_back(num);
	}

	M=M%N;  //实际移动
	for (int i=N-M;i<N;i++)//start从N-M处开始
		cout<<vec[i]<<' ';
	for (int i=0;i<N-M;i++){
		cout<<vec[i];
		if (i!=N-M-1)
			cout<' ';
	}
	return 0;

}