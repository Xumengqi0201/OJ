#include <iostream>
#include <algorithm>

using namespace std;

# define MaxN 202

int graph[MaxN][MaxN], vertex_list[MaxN];
/*
	1.Not a Clique：集合中存在两个点不能直接连通
	2.Not Maximal：集合中所有的点两两直接连通，但是集合外至少存在一个点和集合中的所有点两两连通
		设置一个hash数组，把集合中的点都标志1，那么在hash值为0的点中遍历看是否存在一个点和给定集合中的所有点两两直接连通
	3.不是这两种情况就是Yes
*/

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int nv, m, v1, v2;
	cin >> nv >> m;
	for (int i = 0 ; i < m ; i++){
		cin >> v1 >> v2;
		graph[v1][v2] = graph[v2][v1] = 1;
	}

	int k, vertex_cnt; 
	cin >> k;
	for (int i = 0 ; i < k ; i++){
		int hash[MaxN] = {0};
		int isClique = 1, isMaximal = 1;

		cin >> vertex_cnt;
		for (int j = 0 ; j < vertex_cnt ; j++){
			cin >> vertex_list[j];
			hash[vertex_list[j]] = 1;
		}
		for (int j = 0 ; j < vertex_cnt ; j++ ){
			for (int l = j+1 ; l < vertex_cnt ; l++){
				v1 = vertex_list[j] , v2 = vertex_list[l];
				if(graph[v1][v2] == 0){
					isClique = 0;
					cout << "Not a Clique\n";
					break;
				}
			}
			if (isClique == 0) break;
		}

		if (isClique == 0) continue;  //nice

		for (int j = 1; j <=nv; j++){
			if (hash[j] == 0){  //j不在给定的vertex set中
				for (int l = 0 ; l < vertex_cnt ; l++){
					v1 = vertex_list[l];
					if (graph[v1][j] == 0) break; 
					//j这个点和集合中的所有点都相邻
					if (l == vertex_cnt-1) isMaximal = 0;
				}
			}
			//每一个j处理完以后都查看一下isMaximal
			if (isMaximal == 0) {
				cout << "Not Maximal\n";
				break;
			}
		}		
		if (isMaximal == 1) cout <<"Yes\n";

	}

	return 0;

}
