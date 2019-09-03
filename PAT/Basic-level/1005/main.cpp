# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct Num{
	int num;
	bool iskey=true;
};

bool function(int i,int j){
	return (i>j);
}

int main(){
	int K;
	vector <Num> vec;
	cin>>K;
	
	for(int i=0;i<K;i++){
		Num tmp;
		cin>>tmp.num;
		vec.push_back(tmp);
	}

	for (int i=0;i<K;i++){
		if (vec[i].iskey==false)
			continue;
		int digit=vec[i].num;
		while(digit != 1){
			if (digit%2==0)
				digit/=2;
			else
				digit=digit*3+1;
			for (int j=0;j<K;j++){
				//输入的数字都不相同，找到之后跳出当前循环
				if (vec[j].num==digit){
					vec[j].iskey=false;
					break;
				}
			}
		}
	}

	vector <int> num_array;  //存放关键数字
	for (int i=0;i<K;i++){
		if (vec[i].iskey==true)
			num_array.push_back(vec[i].num);
	}

	sort(num_array.begin(),num_array.end(),function);
	for (vector <int>::iterator iter = num_array.begin();iter != num_array.end();){
		cout<<*iter++;
		if (iter != num_array.end())
			cout<<' ';
	}

	return 0;
}