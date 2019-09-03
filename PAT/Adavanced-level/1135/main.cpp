#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
/*
	1.这道题目的意思是给定的BST，判断其是不是一颗红黑树。（所以给定的一定是一个二叉树）
	2.第一步build tree。BST的特点是左子树的node都比根节点小，右子树的节点都比根节点大。
	所以在给定的前序遍历下，节点值比根节点值小的都在左子树上，递归的造树即可。
	3.判断根节点是不是黑色节点。
	4.判断红色节点的孩子是不是都是黑色节点。
	4.判断一个节点的黑高度是否相同。


*/
#define MAXN 32
struct Node
{
	int val;
	Node * left , *right;
	Node(int v){
		val = v;
		left = right = NULL;
	}
	Node(){}
};

int nodelist[MAXN] = {0};

Node * build(int preL, int preR);
bool judge1(Node *root); //red node的孩子要么为空要么是黑节点
bool judge2(Node *root); // 每一个节点到叶节点的黑高度相同
int getnum(Node *root);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	for (int i = 0; i < k; i++){
		int n;
		cin >> n;
		for (int j = 0; j < n ; j++){
			cin >> nodelist[j];
		}
		Node *root = build(0 , n-1);
		if (nodelist[0] <0 || judge1(root) == false || judge2(root) == false){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}	

	return 0;
}


Node* build(int preL, int preR){
	if (preL > preR)  return NULL;
	int val = nodelist[preL];
	Node *root = new Node(val);
	int mid;
	for (mid = preL ; mid <= preR ; mid++){
		if (abs(nodelist[mid]) > abs(val))  break;
	}
	root->left = build(preL+1 , mid-1);
	root->right = build(mid , preR);
	return root;
}

bool judge1(Node *root){
	if (root == NULL)  return true; //递归出口
	if (root->val < 0){
		if (root->left != NULL && root->left->val < 0)  return false;
		if (root->right != NULL && root->right->val < 0)  return false;
	}
	return judge1(root->left) && judge1(root->right);
}

int getnum(Node *root){
	if (root == NULL)  return 0;
	int l = getnum(root->left);
	int r = getnum(root->right);
	return root->val > 0 ? max(l,r)+1 :  max(l,r);
}

bool judge2(Node *root){
	if (root == NULL)  return true;
	int l = getnum(root->left);
	int r = getnum(root->right);
	if (l != r)  return false;
	return judge2(root->left) && judge2(root->right);
}

