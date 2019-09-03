#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Digit
{
	int num;
	int cnt;
};

bool cmp(const Digit &d1,const Digit &d2)
{
	return (d1.num < d2.num);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string N;
	char arr[10]={0,0,0,0,0,0,0,0,0,0};
	vector <Digit> vec;
	cin>>N;
	int size= N.size(),vec_len=0;
	for (int i=0;i<size;i++)
	{
		int tmp = N[i]-'0';
		arr[tmp]++;
	}
	for (int i=0;i<10;i++)
	{
		if (arr[i])
		{
			Digit tmp;
			tmp.num=i;
			tmp.cnt=arr[i];
			vec.push_back(tmp);
			vec_len++;
		}
	}

	sort( vec.begin(),vec.end(),cmp );
	for (int i=0;i<vec_len;i++)
	{
		cout<<vec[i].num<<":"<<vec[i].cnt<<endl;
	}

	return 0;
}