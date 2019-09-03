#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	可以打印所有的最短路径
*/
#define MAXN 501
#define INF 0x3fffffff

int graph[MAXN][MAXN];
int weight[MAXN], dist[MAXN], visited[MAXN];
int n, m, src, dest;
int max_rescue = 0, cnt_path = 0;

vector <vector<int>> all_path, adlist;
vector<int> tmp_path, path;
void Dijkstra(int vertex);
void DFS(int v);
int cal_rescue();

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0);

	fill (graph[0], graph[0]+ MAXN, INF);
	fill(dist, dist+MAXN, INF);
	cin >> n >> m >> src >> dest;
	adlist.resize(n);
	all_path.resize(n);
	for (int i = 0; i < n; i++){
		cin >> weight[i];
	}
	int v1, v2, l;
	for (int i = 0; i < m; i++){
		cin >> v1 >> v2 >> l;
		graph[v1][v2] = graph[v2][v1] = l;
		adlist[v1].push_back(v2);
		adlist[v2].push_back(v1);
	}

	Dijkstra(src);
	tmp_path.push_back(dest);
	DFS(dest);
	cout << cnt_path << ' ' << max_rescue;

	return 0;
}

void Dijkstra(int vertex){
	dist[vertex] = 0;
	while (1){
		int mid = -1, min_dist = INF;
		for (int v = 0; v < n; v++){
			if (visited[v] == false && dist[v] < min_dist){
				mid = v;
				min_dist = dist[v];
			}
		}
		if (mid == -1)  break;
		visited[mid] = 1;

		for (int i = 0; i < adlist[mid].size(); i++){
			int next = adlist[mid][i];
			if (visited[next] == false){
				if (dist[mid]+graph[mid][next] < dist[next]){
					dist[next] = dist[mid]+graph[mid][next];
					all_path[next].clear();
					all_path[next].push_back(mid);
				}
				else if (dist[mid]+graph[mid][next] == dist[next]){
					all_path[next].push_back(mid);
				}
			}
		}

	}
}

void DFS(int v){
	if (v == src){
		cnt_path++;
		int tmp_rescue = cal_rescue();
		if (max_rescue < tmp_rescue){
			path = tmp_path;
			max_rescue = tmp_rescue;
		}
		return;
	}

	for (int i = 0; i < all_path[v].size(); i++){
		int next = all_path[v][i];
		tmp_path.push_back(next);
		DFS(next);
		tmp_path.pop_back();
	}

}

int cal_rescue(){
	int cnt = 0;
	for (int i = 0; i < tmp_path.size(); i++){
		int v = tmp_path[i];
		cnt += weight[v];
	}
	return cnt;

}