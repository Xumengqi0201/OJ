#include <iostream>
#include <vector>

using namespace std;
/*
	1.preorder+inorder造树
	2.后续遍历的结果放在一个vector中，最后输出vector中的第一个元素
	3.这一题因为只要输出后续遍历的第一个节点。所以，只需要遍历完左子树，并且遍历到左子树的最后一个节点就是后续遍历输出的第一个节点。
	4.看main2.cpp
*/

struct Node
{
	int val;
	Node *left, *right;
	Node(int v){
		val = v;
		left = right = NULL;
	}
};

Node * inpre(int inL, int inR, int preL, int preR);
void postTrav(Node *root);

int n;
vector <int> preorder, inorder, postorder;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	preorder.resize(n);
	inorder.resize(n);
	for (int i = 0 ; i < n ; i++){
		cin >> preorder[i];
	}
	for (int i = 0 ; i < n ; i++){
		cin >> inorder[i];
	}

	Node *root = inpre(0, n-1, 0, n-1);
	postTrav(root);
	cout << postorder[0] << '\n';

	return 0;
}

Node * inpre(int inL, int inR, int preL, int preR){
	if (preL > preR)  return NULL;

	int val = preorder[preL], mid;
	Node *root = new Node(val);
	for ( mid = inL ; mid <= inR ; mid++){
		if (inorder[mid] == val)	break;
	}

	root->left = inpre(inL, mid-1, preL+1, preL+mid-inL);
	root->right = inpre(mid+1, inR, preL+mid-inL+1, preR);
	/*
		也可以按照下面这样写，这样就不需要后续遍历了。
		cout << root->val << '\n';
		exit(0);                 -->直接跳出程序。节省运行时间
	*/
	return root;
}

void postTrav(Node * root){
	if (root != NULL){
		postTrav(root->left);
		postTrav(root->right);
		postorder.push_back(root->val);
	}
}

