#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1001
/*
	1.有向图的拓扑排序，用邻接表存储图，用in_degree存储每个vertex的入度
	2.判断给定的序列是不是拓扑排序，每一个顶点的入度都是0就可以了。但是每遍历一个顶点，就要把和它相邻的顶点的入度减去1.
	这会改变入度数组。所以没判断一次，就要对入度做一次备份。
*/

int in_degree[MAXN], backup[MAXN], topo[MAXN];

int main(int argc, char const *argv[])
{
	ios :: sync_with_stdio(false);
	cin.tie(0);


	int n, m, v1, v2;
	cin >> n >> m;
	vector <vector<int>> graph(n+1);
	for (int i = 0; i < m; i++){
		cin >> v1 >>v2;
		graph[v1].push_back(v2);
		in_degree[v2]++;
	}
	int q;
	cin >> q;
	vector <int> ans;
	for (int i = 0; i < q; i++){
		bool flag = true;
		for (int j = 1; j <= n; j++){
			backup[j] = in_degree[j];
		}
		for (int j = 1; j <= n; j++){
			cin >> topo[j];
		}
		for (int j = 1; j <= n; j++){
			int now = topo[j];
			if (backup[now] != 0){
				flag = false;
				break;
			}
			for (int k = 0; k < graph[now].size(); k++){
				int next = graph[now][k];
				backup[next]--;
			}
		}
		if (flag == false)  ans.push_back(i);
	}

	int len = ans.size();
	for (int i = 0; i < len; i++){
		cout << ans[i];
		if (i != len-1)  cout << ' ';
	}

	return 0;
}