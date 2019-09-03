#include <iostream>

using namespace std;
/*
	1.并查集解决这个问题
	2.因为题目说了鸟的id是连续的，如果没有说那么需要一个exis数组
	3.先初始化，即一个鸟的father就是自己。
	4.Union的原则是把father小的点作为father
	5.鸟的数量就是出现的鸟的最大id。树的数量就是father等于它自己的点的数量
	6.看两个鸟在不在一颗树上就是看两只鸟的father一不一样。
*/
#define MAXN 10002
int father[MAXN];

int findfather(int x){
	while (x != father[x]){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int fa = findfather(a);
	int fb = findfather(b);
	if (fa < fb){
		father[fb] = fa;
	}
	else{
		father[fa] = fb;
	}
}

int main()
{
	for (int i = 0; i < MAXN; i++){
		father[i] = i;
	}
	int n, k, a, b;
	int cnt_birds = 0, cnt_trees = 0;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> k >> a;
		cnt_birds = (cnt_birds > a ? cnt_birds : a);
		for (int j = 1; j < k; j++){
			cin >> b;
			cnt_birds = (cnt_birds > b ? cnt_birds : b);
			Union(a, b);
		}
	}

	for (int i = 1; i <=cnt_birds; i++){
		if (father[i] == i) cnt_trees++;
	}
	cout << cnt_trees << ' ' << cnt_birds << '\n';

	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> a >> b;
		if (findfather(a) == findfather(b)){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}

