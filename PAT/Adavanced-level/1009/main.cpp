#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Polyele
{
	int expo = 0;
	double coef = 0;
};
/*
	1. 两个多项式项的指数最多都是1000，所以二者相乘项指数最多是2000

	2. 存放结果的直接开一个大数组，用expo下标作为索引，对应的内容作为系数，每次计算都在前一项的基础上加上当前系数
*/

double reslist[2004] = {0};

int main()
{
	int k1;
	cin >> k1;
	vector <Polyele> Polylist1;
	for (int i = 0 ; i < k1 ; i++)
	{
		Polyele tmp;
		cin >> tmp.expo >> tmp.coef;
		Polylist1.push_back(tmp);
	}

	int k2 , expo;
	double coef;
	cin >> k2;
	for (int i = 0 ; i < k2 ; i++)
	{
		cin >> expo >> coef;
		for (int j = 0 ; j < k1 ; j++)
		{
			reslist[expo + Polylist1[j].expo] += coef * Polylist1[j].coef;
		}
	}

	int cnt = 0;
	for (int i = 0 ; i <=2000 ; i++)
	{
		if (reslist[i] != 0){
			cnt++;
		}
	}

	cout << cnt;
	for (int i = 2000 ; i >= 0; i--)
	{
		if (reslist[i] != 0){
			cout << ' ' << i << ' ';
			cout << fixed << setprecision(1) << reslist[i];
		}
	}
	cout << '\n';

	return 0;
}