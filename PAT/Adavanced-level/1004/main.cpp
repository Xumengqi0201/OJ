#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
	题目的意思是输出每一层的叶节点个数，关键是设计一个算法可以知道什么时候遍历到了下一层

	1.用BFS，借助queue层序遍历树，每一层统计有几个叶节点。（tree是一个特殊的图，所以代码里面将其写为graph）
	
	2.算法改编自浙大数据结构公开课：https://www.bilibili.com/video/av41229104/?p=73  ，陈老师讲的很好
	
	3.BFS中的level是没有必要出现的，但是为了让代码更清晰，在level变化的时候输出当前level的叶节点个数
	
	4.visited这个数组也是可以不必要设置的，但是为了让代码更加通用就保留了
	
	5.这个算法没有另外开辟空间存储每一个节点的layer，这样可以节省O(N)的空间（N是tree的节点数）
*/

int visited[104] = {0};
void BFS (int root , vector < vector<int> > &graph);

int main()
{
	int n,m,id,k,id1;
	// n: nodes ; m: non-leaf-nodes
	cin >> n >> m;
	vector < vector <int> > graph;
	graph.resize(n+1);  //重要,这样没有孩子的节点对应的vector是空
	//root的id从1开始
	for (int i = 0 ; i < m ;i++)
	{
		cin >> id >> k;
		for (int j = 0 ; j < k ; j++)
		{
			cin >> id1;
			graph[id].push_back(id1);
		}
	}

	int root = 01;//先把根节点是否是叶子节点的结果输出，考虑行末不能有多余的空格
	if ( n == 1)  //如果只有一个节点，那么第一层的non-leaf nodes的数量是1
	{
		cout << '1'; 
	}
	else{
		cout << '0';  //否则root node肯定不是non-leaf node ，即数量是0
		BFS(root,graph);
		cout << '\n';
	}

	return 0;
}

void BFS (int root , vector < vector<int> > &graph)
{
	visited[root] = 1;
	int count = 0 , level = 0;
	int last = root , vertex , tail;
	queue<int> q;
	q.push(root);

	while (q.size()!=0)
	{
		vertex = q.front();
		q.pop();
		vector <int > children = graph[vertex];//children是vertex这个parent node的所有孩子
		for (auto child : children) //child是vertex的每个孩子
		{
			if (visited[child] == 0)
			{
				visited[child] = 1;
				q.push(child);
				if (graph[child].size() == 0)//child is a leaf node
				{
					count++;
				}
				tail = child;  //tail保存的是当前遍历的最后一个节点（还木有进队）
			}
		}

		if (vertex == last)  //vertex = last的时候说明一层遍历完了，那么last需要更新为tail即当前遍历的最后一个节点
		{
			level++;  //level变化时而且队列不为空的时候 输出count
			last = tail;
			if(q.size()!= 0){
				cout << ' ' <<count;  //第一个count实际上是树的第二层的非叶节点个数
				count = 0;
			}
		}

	}
}