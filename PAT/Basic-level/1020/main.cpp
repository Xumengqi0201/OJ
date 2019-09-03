#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Mooncake {
	double inventory;
	double total_price;
	double price;
};

bool cmp(const Mooncake &a, const Mooncake &b) {//对struct中个某个变量排序
	return (a.price > b.price);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	double D,total_gains = 0;
	vector <Mooncake> vec;
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		Mooncake cake;
		cin >> cake.inventory;
		vec.push_back(cake);
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i].total_price;
	}
	for (int i = 0; i < N; i++)
	{
		vec[i].price = vec[i].total_price / vec[i].inventory;
	}

	sort(vec.begin(), vec.end(), cmp);//将月饼单价从大到小排序，优先用单价高的月饼
	for (int i = 0; i < N; i++)
	{
		if (D >= vec[i].inventory)
		{
			D -= vec[i].inventory;
			total_gains += vec[i].total_price;
		}
		else  //总需求量已经小于当前这一类月饼的库存，那么总收益应该是剩下的总需求*单价
		{
			total_gains += D * vec[i].price;
			break;
		}
	}
	cout << fixed<<setprecision(2)<<total_gains;
	return 0;
}