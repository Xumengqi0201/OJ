#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int segment[10001] = {0};
/*
	1.两段绳子打结以后长度是原来的一半，这条新的绳子和其他绳子一起又可以组成新的绳子
	2.可以发现，越早打结的绳子对折的次数越多。所以为了让最后的绳子最长，要先选短的绳子打结
	3.先把绳子长度排序。每打结一次，就把长度之和除以2
	4.最后把浮点数取整，因为题目说是不超过绳子长度的最大正数，所以向下取整就可以。

*/

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res;
	for (int i = 0; i < n; i++){
		cin >> segment[i];
	}
	sort(segment, segment+n);
	double res1 = segment[0];
	for (int i = 1; i < n; i++){
		res1 = (res1 + segment[i])/2;
	}
	res = res1;
	cout << res;
	return 0;
}