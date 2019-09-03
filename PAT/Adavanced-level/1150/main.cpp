#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

#define INF 0x3fffffff
#define MaxN 204
/*
	1.not a cycle :
		a.输入的city中存在相邻的顶点不能直接到达(NA,不输出path_len)
		b.第一个city不等于最后一个city(输出path_len)
		c.没有遍历所有的vertex,set size小于城市的数量(path_len)

	2.接下来判断是不是 simple cycle
		在满足is cycle的情况下，如果遍历的city数量大于总的city数量+1，说明不是symple cycle
	
	3.用min_dist和path_id保存最短路长和最短的路的编号
	
	4.输出的最短路长是cycle里面的最短路程
*/
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int graph[MaxN][MaxN], path_list[MaxN];
	int n, m, k, mindist = INF, path_id;
	fill(graph[0] , graph[0]+MaxN*MaxN , INF);
	cin >> n >> m;
	int v1, v2, weight;
	for (int i = 0 ; i < m ; i++)
	{
		cin >> v1 >> v2 >> weight;
		graph[v1][v2] = graph[v2][v1] = weight;
	}

	cin >> k;
	bool has_shortpath = false;
	for (int i = 1 ; i <= k ; i++)
	{
		unordered_set <int> s;
		int city_cnt , path_len = 0;
		bool iscycle = true;

		cin >> city_cnt;
		cout << "Path " << i << ": ";
		for (int j = 0 ; j < city_cnt ; j++)
		{
			cin >> v1;
			path_list[j] = v1;
			s.insert(v1);
		}
		
		for (int j = 0 ; j < city_cnt-1 ; j++)
		{
			v1 = path_list[j] , v2 = path_list[j+1];
			if (graph[v1][v2] == INF){
				iscycle = false;
				break;
			}
			path_len += graph[v1][v2];
		}

		if (iscycle == false){
			cout << "NA (Not a TS cycle)\n";
		}
		else if (path_list[0] != path_list[city_cnt-1] || s.size() != n){
			cout << path_len << " (Not a TS cycle)\n";
			iscycle = false;
		}
		else if (city_cnt > n+1){
			cout << path_len << " (TS cycle)\n";
			iscycle = true;
		}
		else{
			cout << path_len << " (TS simple cycle)\n";
			iscycle = true;
		}

		if (iscycle){
			has_shortpath = true;
			if (path_len < mindist){
				mindist = path_len;
				path_id = i;
			}
		}
	}

	if (has_shortpath){
		cout << "Shortest Dist(" << path_id << ") = " << mindist;
	}

	

	return 0;
}