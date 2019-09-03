#include <iostream>
#include <vector>

using namespace std;

vector <int> preorder , inorder;
int n;

void inpre(int inL, int inR, int preL, int preR);

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	preorder.resize(n);
	inorder.resize(n);
	for (int i = 0; i < n; i++){
		cin >> preorder[i];
	}
	for (int i = 0; i < n; i++){
		cin >> inorder[i];
	}
	inpre(0, n-1, 0, n-1);
	return 0;
}

void inpre(int inL, int inR, int preL, int preR){
	if (inL > inR)  return;
	int mid, val = preorder[preL];
	for (mid = inL ; mid <= inR ; mid++){
		if (inorder[mid] == val)  break;
	}
	inpre(inL, mid-1, preL+1, preL+mid-inL);
	inpre(mid+1, inR, preL+mid-inL+1, preR);
	//递归到最左边直接输出结果并直接跳出程序。
	cout << inorder[inL] <<'\n';
	exit(0);
}
