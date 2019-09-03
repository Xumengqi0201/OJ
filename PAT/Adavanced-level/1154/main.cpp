#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
	思路

*	1.题目的意思是如果满足一条边的两个顶点的颜色各不相同，那么计算输出图中颜色的种数；否则输出“No”；

*	2.用邻接表的形式存储graph,用无序集合unordered_set统计颜色种数s,set是有序集合，排序操作速度变慢。

*	3.把graph定义成全局变量，这样graph存储在heap中。考虑到顶点数多的时候，局部变量存储在stack中，旧的编译器可能会溢出。

*/

vector <vector<int>> graph;
vector <int> colorlist;

bool isvalid(int n) {
	bool res = true;
	for (int i = 0; i < n; i++)
	{
		for (int j : graph[i])
		{
			if (colorlist[i] == colorlist[j])
			{
				res = false;
				break;
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	colorlist.resize(n);

	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);//邻接表的形式存储graph
		graph[v2].push_back(v1);
	}

	int k;
	cin >> k;

	for (int now = 0; now < k; now++)
	{
		for (int v=0;v<n;v++)
		{
 			cin >> colorlist[v];
		}
		if (isvalid(n))
		{
			unordered_set<int> s;
			for (auto v : colorlist)
			{
				s.insert(v);
			}
			int cnt = s.size();//无序set，比有序set速度更快
			cout << cnt << "-coloring\n";
		}

		else
		{
			cout << "No\n";
		}
	}

	return 0;
}