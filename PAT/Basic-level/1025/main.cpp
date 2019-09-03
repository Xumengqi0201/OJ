#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define MAXSIZE 100008//不能只开100000，有可能某个节点的地址正好是100000，越界

using namespace std;

struct Node
{
	int addr, next_addr;
	int data;
	void set(int a, int b, int c){
		addr = a;
		data = b;
		next_addr = c;
	}
};

Node node_array[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int first_addr,N,K;
	vector <Node> vec;
	cin>>first_addr>>N>>K;

	for (int i=0;i<N;i++)
	{
		int addr,data,next_addr;
		cin>>addr>>data>>next_addr;
		node_array[addr].set(addr,data,next_addr); //节点地址作为下标索引，把它放在对应位置上
	}

	int next=first_addr;
	while (next!=-1){   //把在主链条中的节点放在vec中,地址就是下标索引
		Node tmp = node_array[next];  
		vec.push_back(tmp);
		next = tmp.next_addr;
	}

	int len=vec.size();  
	int rnd=len/K;  //一共rnd组，每组都需要翻转K个节点，最后不到K个节点不翻转
	for (int i=0;i<rnd;i++)
	{
		int start=K*i;
		int left = start;
		int right =start+K-1;
		while (left<right)
		{
			swap(vec[left],vec[right]);
			left++;
			right--;
		}
	}  
	//翻转位置即可，不需要把每个节点的next_addr也修改了，输出的时候输出当前节点的addr,data和下一个节点的addr

	len=vec.size()-1;
	for (int i=0;i<len;i++)
	{
		Node tmp1=vec[i];
		Node tmp2= vec[i+1];
		cout<<setfill('0')<<setw(5)<<tmp1.addr;
		cout<<' '<<tmp1.data<<' ';
		cout<<setfill('0')<<setw(5)<<tmp2.addr<<'\n';
	}

	cout<<setfill('0')<<setw(5)<<vec[len].addr;
	cout<<' '<<vec[len].data;
	cout<<" -1\n";

	return 0;
}
