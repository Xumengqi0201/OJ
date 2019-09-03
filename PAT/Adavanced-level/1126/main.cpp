#include <iostream>
#include <vector>

using namespace std;
/*
	Eulerian和semi-Eulerian的前提是连通图，所以要判断一下这个图是不是连通图。

*/
vector <vector<int>> graph;
bool visited[501] = {0};
int con_cnt = 0;

void dfs(int v){  //判断连通图，如果con_cnt == n连通；否则不连通
	visited[v] = 1;
	con_cnt++;
	for (int i = 0; i < graph[v].size(); i++){
		if ( visited[graph[v][i]] == false ){
			dfs(graph[v][i]);
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n, m, v1, v2;
	cin >> n >> m;
	graph.resize(n+1);

	for (int i = 0 ; i < m ;i++){
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		cout << graph[i].size();
		if (graph[i].size() % 2 != 0){
			cnt++;
		}
		if (i != n)  cout << ' ';
	}
	cout <<'\n';

	if (con_cnt == n){
		if (cnt == 0)  cout << "Eulerian\n";
		else if (cnt == 2)  cout  << "Semi-Eulerian\n";
		else cout << "Non-Eulerian\n";
	}
	else{  
		cout <<"Non-Eulerian\n";
	}

	return 0;
}