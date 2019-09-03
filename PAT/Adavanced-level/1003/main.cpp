#include <iostream>
#include <algorithm>

using namespace std;

#define INF 0x3fffffff 

int rescues[504], graph[504][504], dist[504], num[504], w[504];
bool visit[504];  //全局变量初始化为0
/*
	1.num存储的是从src到某一个顶点的最短路径的数量
	2.w存储的是从src到某一个顶点最多的救援队数量
	3.Dijkstra算法
	4.参考柳神
*/
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n, m, src, dest;
	cin >> n >> m >> src >> dest;
	fill(graph[0] , graph[0]+504*504 , INF);  //二维数组的初始化
	fill(dist , dist+504 , INF);
	//输入每个城市的救援队数量
	for (int i = 0 ; i < n ; i++)
	{
		cin >> rescues[i];
	}

	//build graph，weight全部初始化为INF，防止给的路径的权重是0
	int v1 , v2 , weight;
	for (int i = 0 ; i < m ; i++){
		cin >> v1 >> v2 >> weight;
		graph[v1][v2] = graph[v2][v1] = weight;
	}
	//Dijkstra算法
	dist[src] = 0;
	w[src] = rescues[src];
	num[src] = 1;
	while(1){
		int mid = -1 ,min = INF;
		for (int i = 0 ; i < n ; i++){
			if (visit[i] == false && dist[i] < min){
				mid = i;
				min = dist[i];
			}
		}

		if (mid == -1) break;
		visit[mid] = true;
		for (int v = 0 ; v < n ; v++){
			if (visit[v] == false && graph[mid][v] != INF){
				if (graph[mid][v] + dist[mid] < dist[v]){
					dist[v] = graph[mid][v] + dist[mid];
					//mid是v的前一个节点，如果更新了最短路径，说吗到v的最短路径数量肯定等于到mid的最短路径数量
					num[v] = num[mid]; 
					//到v的救援队数量显然等于到w的救援队数量加上城市v自己的救援队数量
					w[v] = w[mid] + rescues[v];
				}
				else if (graph[mid][v] + dist[mid] == dist[v]){
					//1.相等说明之前已经访问过v了，这次这是从另外一条路径访问v
					//1.那么到v的shortest path数量必然等于num[v] + num[mid]
					num[v] += num[mid];
					//保持w中存储的是可以搜集的最多的救援队数量
					if (w[mid] + rescues[v] > w[v]){
						w[v] = w[mid] + rescues[v];
					}
				}
			}
		}
	}

	cout << num[dest] << ' ' << w[dest] << '\n';
	return 0;
}