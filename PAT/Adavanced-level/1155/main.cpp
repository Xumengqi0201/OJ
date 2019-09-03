#include <iostream>
#include <vector>

using namespace std;

int tree[1008] = { 0 };
vector <int> res;

bool MaxHeap(int n);
bool MinHeap(int n);
void print_paths();
void dfs(int root, int n);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
	}
	/*	1. paths from root to leaf
		2. all the paths in the right subtree must be printed before those in the left subtree
	*/
	dfs(1, n);
	if (MaxHeap(n) == true) {
		cout << "Max Heap\n";
	}
	else if (MinHeap(n) == true) {
		cout << "Min Heap\n";
	}
	else {
		cout << "Not Heap\n";
	}

	return 0;
}

bool MaxHeap(int n) {
	bool ismaxheap = true;
	for (int i = 1; i <= n; i++) {
		int parent = i;
		int left = 2 * i;
		int right = left + 1;
		if (left <= n && tree[parent] < tree[left])
		{
			ismaxheap = false;
			break;
		}
		if (right <= n && tree[parent] < tree[right])
		{
			ismaxheap = false;
			break;
		}
	}

	return ismaxheap;
}

bool MinHeap(int n) {
	bool isminheap = true;
	for (int i = 1; i <= n; i++) {
		int parent = i;
		int left = 2 * i;
		int right = left + 1;
		if (left <= n && tree[parent] > tree[left])
		{
			isminheap = false;
			break;
		}
		if (right <= n && tree[parent] > tree[right])
		{
			isminheap = false;
			break;
		}
	}

	return isminheap;
}

void print_paths() {
	int len = res.size();
	for (int i = 0; i < len; i++) {
		cout << res[i];
		if (i != len - 1) {
			cout << ' ';
		}
	}
	cout << '\n';
}
