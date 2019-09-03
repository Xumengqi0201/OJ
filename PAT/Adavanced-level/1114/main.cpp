#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MAXSIZE 10000

struct Family{
	int id, size = 0, M = 0, Area = 0;
	double AVG_sets, AVG_area;
}famlist[MAXSIZE];

struct Node{
	int id, Father, Mother, k;
	int Child[6];
	int M_estate, Area;
}nodelist[MAXSIZE];

int father[MAXSIZE] = {0};
bool visited[MAXSIZE] = {0};


int findfather(int x){
	while (x != father[x]){
		x = father[x];
	}
	return x;
}
void Union(int id1, int id2){
	int fa = findfather(id1);
	int fb = findfather(id2);
	if (fa < fb){  //用最小的id作为父节点
		father[fb] = fa;
	}
	else{
		father[fa] = fb;
	}
}

bool cmp(Family &x, Family &y){
	if (x.AVG_area != y.AVG_area){
		return x.AVG_area > y.AVG_area;
	}
	else{
		return x.id < y.id;
	} 
}

int main(){
	ios ::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0 ; i < MAXSIZE ;i++){
		father[i] = i;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n ; i++){
		Node tmp;
		cin >> tmp.id >> tmp.Father >> tmp.Mother >> tmp.k;
		visited[tmp.id] = 1;
		if (tmp.Father != -1){
			Union(tmp.id, tmp.Father);
			visited[tmp.Father] = 1;
		}
		if (tmp.Mother != -1){
			Union(tmp.id, tmp.Mother);
			visited[tmp.Mother] = 1;
		}

		for (int j = 0; j < tmp.k; j++){
			cin >> tmp.Child[j];
			Union(tmp.id, tmp.Child[j]);
			visited[tmp.Child[j]] = 1;
		}
		cin >> tmp.M_estate >> tmp.Area;
		nodelist[i] = tmp;
	}

	for (int i = 0; i < MAXSIZE ; i++){
		if (visited[i] == 1){
			int fa = findfather(i);
			famlist[fa].size++;
		}
	}

	for (int i = 0; i < n; i++){
		int fa = findfather(nodelist[i].id);
		famlist[fa].id = fa;
		famlist[fa].M += nodelist[i].M_estate;
		famlist[fa].Area += nodelist[i].Area;
	}

	vector <Family> anslist;
	for (int i = 0; i < MAXSIZE; i++){
		if (famlist[i].size != 0){
			famlist[i].AVG_sets = 1.0*famlist[i].M / famlist[i].size;
			famlist[i].AVG_area = 1.0*famlist[i].Area / famlist[i].size;
			anslist.push_back(famlist[i]);
		}
	}
	sort(anslist.begin(), anslist.end(), cmp);

	int len = anslist.size();
	cout << len << '\n';
	for (int i = 0; i < len; i++){
		cout << setw(4) << setfill('0') << anslist[i].id << ' ';
		cout << anslist[i].size << ' ';
		cout << fixed << setprecision(3) << anslist[i].AVG_sets << ' ';
		cout << fixed << setprecision(3) << anslist[i].AVG_area <<'\n';
	}

	return 0;
}