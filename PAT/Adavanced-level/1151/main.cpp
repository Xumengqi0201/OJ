#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
	参考柳神
	1.不用buid tree,递归的找LCA。在inorder中
		a.如果一个节点在根节点的左边，一个节点在根节点的右边，那么LCA就是根节点。
		b.如果两个节点都在根节点的左边，那么到左子树上找。如果两个节点都在根节点的右边，到右子树上找。
		c.对于情况a，每个子树也是相同的。两个节点在某个子树的根节点的两边，子树的根节点就是LCA。
	2.不造树递归的话，必须用map记录在inorder中每个节点的位置。否则，每递归一次，就要遍历一次inorder和preorder找两个节点的位置。
*/
vector <int> in, pre;
unordered_map<int, int> treemap; 

void lca(int inL, int inR, int preRoot, int a, int b);

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);


	int m, n;
	cin >> m >> n;
	in.resize(n+1);
	pre.resize(n+1);
	for (int i = 1 ; i <= n; i++){
		cin >> in[i];
		treemap[in[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		cin >> pre[i];
	}
	int a, b;
	for (int i =0; i < m; i++){
		cin >> a >> b;
		if (treemap[a] == 0 && treemap[b] == 0){
			cout << "ERROR: " << a << " and " << b << " are not found.\n";
		}
		else if (treemap[a] == 0){
			cout << "ERROR: " << a << " is not found.\n";
		}
		else if (treemap[b] == 0){
			cout << "ERROR: " << b << " is not found.\n";
		}
		else{
			lca(1, n, 1, a, b);
		}
	}
	return 0;
}

void lca(int inL, int inR, int preRoot, int a, int b)
{
	if (inL > inR)  return;
	int inRoot = treemap[pre[preRoot]], in_a = treemap[a], in_b = treemap[b];
	if (in_a < inRoot && in_b > inRoot || in_a > inRoot && in_b < inRoot ){
		cout << "LCA of " << a << " and " << b <<" is "<< in[inRoot] << ".\n";
 	}
 	else if (in_a < inRoot && in_b < inRoot){
 		lca(inL, inRoot-1, preRoot+1, a, b);
 	}
 	else if (in_a > inRoot && in_b > inRoot){
 		lca(inRoot+1, inR, preRoot+1+inRoot-inL, a, b);
 	}
 	else if (in_a == inRoot){  //a是子树的根
 		cout << a << " is an ancestor of " << b << ".\n";
 	}
 	else if (in_b == inRoot){  //b是子树的根
 		cout << b << " is an ancestor of " << a << ".\n";
 	}
}