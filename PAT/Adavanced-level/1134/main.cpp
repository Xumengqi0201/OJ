#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector<int> > edge_of_vertex;   
vector <bool> visited_edge;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;  //n：顶点数；m：边数
	cin >> n >> m;
	edge_of_vertex.resize(n);
	visited_edge.resize(m);

	// vertex_id
	int v1, v2;
	for (int edge_id = 0; edge_id < m; edge_id++)
	{
		cin >> v1 >> v2;
		edge_of_vertex[v1].push_back(edge_id); //edge的编号由输入的顺序决定
		edge_of_vertex[v2].push_back(edge_id);
	}

	//图存储：这一题主要是存储边
	// 8:[0,1,3,4,7]  即顶点8和第0,1,3,4,7条边相连。
	// 所以如果输入的vertice set中有8，那么把边0，1 ，3 ，4 ，7全部标志为true；
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int nv;  //number of vertices
		cin >> nv;
		bool isvalid = true;
		fill(visited_edge.begin(), visited_edge.end(), false);

		for (int j = 0; j < nv; j++) {
			cin >> v1;
			vector <int> vid_edge = edge_of_vertex[v1];  //和顶点v1相连的edge的编号
			for (auto edge_id : vid_edge) {
				visited_edge[edge_id] = true;     //将这些边全部标志位true，即可以通过这个顶点访问这条边
			}
		}

		for (auto sign : visited_edge) {  //如果visited_edge数组中还有值为false说明还有边没有被访问到，这个set就不满足条件
			if (sign == false) {
				isvalid = false;
				break;
			}
		}

		if (isvalid == true) {  //根据访问结果输出Yes 或者 No
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}

	}


	return 0;
}
