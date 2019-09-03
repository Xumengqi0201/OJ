#include <iostream>
#include <unordered_map>

using namespace std;
/*
	1.这一题和1151类似，只是1151是一颗普通二叉树，这是一颗BST。
	2.使用map记录一个node有没有在tree中出现过
	3.当两个节点都出现的时候，找LCA
	4.遍历一次preorder，找到第一个在两个节点值中间的节点。再分类讨论。
	
	a.如果两个节点一个比根节点大一个比根节点小，那么LCA显然是根节点。这个规则对于每一个子树都是成立的。
	b.preorder的特点是根左右，那么找到的第一个节点符合在两个节点值中间的一定是一个LCA。
	c.和1151的递归过程是一样的，1151也是分别到左子树和右子树递归。只是这是一颗BST。
*/

int pre[10002] = {0};
unordered_map <int, bool> treemap;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++){
		cin >> pre[i];
		treemap[pre[i]] = true;
	}
	int a, b;
	for (int i = 0 ; i < m ; i++){
		cin >> a >> b;
		if (treemap[a] == false && treemap[b] == false){
			cout << "ERROR: " << a << " and " << b <<  " are not found.\n";
		}
		else if (treemap[a] == false){
			cout << "ERROR: " << a << " is not found.\n";
		}
		else if (treemap[b] == false){
			cout << "ERROR: " << b << " is not found.\n";
		}
		else{
			int j;
			for (j = 0; j < n; j++){
				if (pre[j] >= a && pre[j] <= b || pre[j] >= b && pre[j] <= a){
					break;
				}
			}
			if ( pre[j] > a && pre[j] < b || pre[j] > b && pre[j] < a){
				cout << "LCA of " << a << " and " << b <<  " is " << pre[j] << ".\n";
			}
			else if (pre[j] == a){
				cout << a << " is an ancestor of " << b << ".\n";
			}
			else if (pre[j] == b){
				cout << b << " is an ancestor of " << a << ".\n";
			}
		}

	}


	return 0;
}