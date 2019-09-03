#include <iostream>
#include <set>

using namespace std;
/*
	重载 < ,利用set会自动从小到大排序
*/


#define MAXN 50004
int cntlist[MAXN] = {0};

struct Ele
{
	int index, cnt;
	Ele (int i, int c){
		index = i;
		cnt = c;
	}
	Ele(){}
	bool operator < (const Ele& e) const{
		if (cnt != e.cnt)
		{
			return cnt > e.cnt;
		}
		else
		{
			return index < e.index;
		}
	}
};

int main()
{
	ios:: sync_with_stdio(false);
	cin.tie(0);

	int n, k, index;
	cin >> n >> k;
	set <Ele> s;
	for (int i = 0; i < n; i++){
		cin >> index;
		if (i != 0){
			cout << index <<":";
			int upbound = k < s.size() ? k : s.size();
			int count = 1;
			for (auto iter = s.begin(); iter != s.end() && count <= upbound; iter++, count++){
				cout << ' ' << iter->index;
			}
			cout <<'\n';
		}
		Ele tmp(index , cntlist[index]);
		auto iter = s.find(tmp);
		if (iter != s.end()){
			s.erase(tmp);
		}
		tmp.cnt++;
		s.insert(tmp);
		cntlist[index]++;
	}

	return 0;
}