#include <iostream>
#include <vector>
using namespace std;

int tree[1005] = {0};
vector <int> treelist;

bool MaxHeap (int n);
bool MinHeap (int n);
void postorder(int root,int n);

int main(){
	int m , n;
	cin >> m >> n;
	for (int i = 0 ; i < m ; i++){
		for (int j = 1 ; j <= n ; j++){
			cin >> tree[j];
		}
		
		if (MaxHeap(n) == true){
			cout << "Max Heap\n";
		}
		else if (MinHeap(n) == true){
			cout << "Min Heap\n";
		}
		else{
			cout << "Not Heap\n";
		}

		treelist.resize(0); //保证treelist为空
		postorder(1,n);

		//输出节点值，注意行末不得有多余空格
		for (int i = 0; i<n ; i++){
			cout<<treelist[i];
			if (i != n){
				cout <<' ';
			}
		}
		cout <<'\n';
	}
	return 0;
}

bool MaxHeap (int n){
	bool res = true;
	for (int i = 1; i <=n ; i++){
		int parent = i;
		int left = 2*i;
		int right = 2*i+1;
		if (left <= n && tree[parent] < tree[left]){
			res = false;
			break;
		}
		if (right <= n && tree[parent] < tree[right]){
			res = false;
			break;
		}
	}
	return res;	//父节点的值大于等于子节点的值
}

bool MinHeap (int n){
	bool res = true;
	for (int i = 1; i <=n ; i++){
		int parent = i;
		int left = 2*i;
		int right = 2*i+1;
		if (left <= n && tree[parent] > tree[left]){
			res = false;
			break;
		}
		if (right <= n && tree[parent] > tree[right]){
			res = false;
			break;
		}
	}
	return res;	//父节点的值小于等于子节点的值
}

void postorder(int root,int n){	//后续遍历：先遍历左子树，再遍历右子树，最后输出根节点的值
	if (root <= n){
		int left = 2*root;
		int right = 2*root+1;
		postorder(left,n);
		postorder(right,n);
		treelist.push_back(tree[root]); //visit root
	}
}