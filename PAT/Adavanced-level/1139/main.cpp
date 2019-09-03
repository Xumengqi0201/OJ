#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
/*
	坑好多啊，这一题，写到后面忘了前面，菜鸡自述
	1.每个人的id唯一，符号仅仅代表性别。
	2.如果用把id设为int型，那么无法判断-0000和0000的性别，所以用string存储id
	3.用邻接表存储一个人的所有 [同性] 朋友，用邻接矩阵存储朋友关系。
	4.找到A的所有同性朋友，找到B的所有同性朋友，如果二人的朋友是一对pair。那么把他们放到ans中。最后排序输出。
	5.用string中的stoi将string转为正数(stoi只能转正数，不能转成小数)
	6.如果A的朋友恰好是B 那么舍弃这个结果；相应的如果B的朋友恰好是A，舍弃这个结果。（很奇怪，因为A和B 肯定是异性，所以不知道为啥，不然两个case不过）
	7.要输出4位的id，补全0
	8.最重要的，这一题不能用二维数组存储图，否则内存会超，最后一个测试case显示运行超时。
	所以用一个无序map存储。

*/

unordered_map <int , bool> adgraph;
unordered_map < int , vector<int> > adlist;

struct node{
	int a , b;
	node (int a , int b){
		node :: a = a;
		node :: b = b;
	}
	node(){}
};

bool cmp(node x, node y){
	if (x.a != y.a)  return x.a < y.a;
	else  return x.b < y.b;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string id1, id2;
	int v1, v2;
	for (int i = 0; i < m; i++){
		cin >> id1 >> id2;
		int v1 = abs(stoi(id1));
		int v2 = abs(stoi(id2));
		if (id1.size() == id2.size()){//说明是同性朋友，因为题目说明了按照四位id输入
			adlist[v1].push_back(v2);
			adlist[v2].push_back(v1);
		}
		adgraph[v1*10000+v2] = adgraph[v2*10000+v1] = true; //因为v1和v2是一个四位数，[]中的表达式对于不同的v1和v2一定是不同的。
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> v1 >> v2;
		vector <node> ans;
		v1 = abs(v1);
		v2 = abs(v2);
		int len1 = adlist[v1].size();
		int len2 = adlist[v2].size();
		for (int j = 0; j < len1 ; j++){
			for (int l = 0; l < len2 ; l++){
				int k1 = adlist[v1][j];
				int k2 = adlist[v2][l];
				if (k1 == v2 || k2 == v1)  continue;
				if (adgraph[k1*10000+k2] == true){
					node tmp(k1, k2);
					ans.push_back(tmp);
				}
			}
		}
		sort(ans.begin() , ans.end() , cmp);
		int len = ans.size();
		cout << len << '\n';
		for (int j = 0 ; j < len ; j++){
			cout << setw(4) << setfill('0') << ans[j].a << ' ';
			cout << setw(4) << setfill('0') <<ans[j].b << '\n';
		}

	}




	return 0;
}