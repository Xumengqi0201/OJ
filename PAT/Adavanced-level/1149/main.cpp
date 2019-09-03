#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int N,M,id1,id2;
	cin >> N >> M;
	//用无序字典以领接表的形式存储图，key的类型是int，value的类型是vector<int>
	//20001:[20002,20003]
	unordered_map<int , vector<int>> graph;
	for (int i =0 ; i < N ; i++)
	{
		cin >> id1 >> id2;
		graph[id1].push_back(id2);  //id1是key,graph[id1]是vector，hash
		graph[id2].push_back(id1);  //id2是key
	}
	
	for (int i = 0 ; i < M ; i++ )
	{
		int k;
		vector <int> line;
		cin >> k;
		for (int j = 0 ; j < k ; j++)
		{
			cin >> id1;
			line.push_back(id1);
		}

		for(int j = 0 ; j < k ; j++)
		{
			int key = line[j];
			if (graph.find(key) != graph.end()) //line 中的id是graph中的key
			{
				vector <int> linevec = graph[key];
				for (int now = j+1 ; now < k ; now++){
					id1 = line[now];
					for (auto id2 : linevec)
					{
						if (id1 == id2){
							cout << "No\n";
							goto nextloop;
						}
					}
				}
			}

		}
		cout << "Yes\n";

	nextloop:
		continue;

	}	


	return 0;
}