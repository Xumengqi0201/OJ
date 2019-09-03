#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAXN 100004
/*
	1.这种题目基本都存在孤立节点和多条支链的情况，所以先把所有节点输入进来，再找出一条主链表
	2.按照分类要求，先用三个vector分别存储三种情况下的节点。
	3.把三个vector连接。
	4.anslist[i].addr anslist[i].data anslist[i+1].addr的形式输出
	5.最后一个节点单独考虑输出。
*/

struct Node{
	int addr, data, next;
};
Node nodelist[MAXN];
vector <Node> vec;


int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int fisrt_addr, n, k;
	cin >> fisrt_addr >> n >> k;
	int addr, data, next;
	for (int i = 0; i < n; i++){
		cin >> addr >> data >> next;
		nodelist[addr].addr = addr;
		nodelist[addr].data = data;
		nodelist[addr].next = next;
	}

	int now = fisrt_addr;
	while(now != -1){
		vec.push_back(nodelist[now]);
		now = nodelist[now].next;
	}
	vector <Node> res1, res2, res3; //按要求分类
	int len = vec.size();
	for (int i = 0; i < len; i++){
		if (vec[i].data < 0){
			res1.push_back(vec[i]);
		}
	}

	for (int i = 0; i < len; i++){
		if (vec[i].data >= 0 && vec[i].data <= k){
			res2.push_back(vec[i]);
		}
	}

	for (int i = 0; i < len; i++){
		if (vec[i].data > k){
			res3.push_back(vec[i]);
		}
	}
	//重新连接
	vector <Node> anslist;
	for (auto ele : res1){
		anslist.push_back(ele);
	}
	for (auto ele : res2){
		anslist.push_back(ele);
	}
	for (auto ele : res3){
		anslist.push_back(ele);
	}
	//输出结果,最后一个节点单独处理
	for (int i = 0; i < len-1; i++){
		cout << setw(5) << setfill('0') << anslist[i].addr <<' ';
		cout << anslist[i].data <<' ';
		cout << setw(5) << setfill('0') << anslist[i+1].addr << '\n';
	}

	cout << setw(5) << setfill('0') << anslist[len-1].addr <<' ';
	cout << anslist[len-1].data << ' ' << "-1" <<'\n';
	return 0;
}