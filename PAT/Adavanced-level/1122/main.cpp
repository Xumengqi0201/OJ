#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 202
#define INF 0x3fffffff

int graph[MAXN][MAXN];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	fill(graph[0], graph[0]+MAXN, INF);
	int n, m, v1, v2;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> v1 >> v2;
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	int q, num;
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> num;
		vector <int> vec(num);
		unordered_set <int> query;
		bool flag = true;
		for (int j = 0; j < num; j++){
			cin >> vec[j];
			query.insert(vec[j]);
		}

		for (int j = 0; j < num-1; j++){
			v1 = vec[j], v2 = vec[j+1];
			if (graph[v1][v2] != 1){
				flag = false;
				break;
			}
		}

		if (num != n+1 || vec[0] != vec[num-1] || query.size() != n)  flag = false;
		
		if (flag == false)  cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}