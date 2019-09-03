#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

/*
	1.两类人是单身狗：没有couple的人和couple不在guests里面的人
	2.三个数组couple存储这个人的对象，exist存储guests里面有没有出现过，guests存储来宾的id。
	3.把couple全部初始化为-1，因为一个人的id可能是00000
	4.遍历guests数组，如果它的couple为-1，说明它没有伴侣。如果他的伴侣没有出现，那么他也是单身狗
	5.对ans排序输出即可。
*/

int couple[100000];
int guests[100000];
bool exist[100000];

int main(int argc, char const *argv[])
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int id1, id2;
	fill(couple, couple+100000, -1);
	for (int i = 0; i < n; i++){
		cin >> id1 >> id2;
		couple[id1] = id2;
		couple[id2] = id1;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		/* code */
		cin >> guests[i];
		exist[guests[i]] = 1;
	}
	vector <int> ans;
	for (int i = 0; i < m ;i++){
		if (couple[guests[i]] == -1 || exist[couple[guests[i]]] == 0) //这个不在couple里面
			ans.push_back(guests[i]);
	}

	sort(ans.begin(), ans.end());
	int len = ans.size();
	cout <<len <<'\n';
	for (int i = 0; i < len ;i++){
		cout << setw(5) << setfill('0') << ans[i];
		if (i != len - 1)  cout << ' ';
	}
    //cout << '\n'  加上这一行这一题是错的，如果有格式错误把加上的回车去掉试试看
	return 0;
}