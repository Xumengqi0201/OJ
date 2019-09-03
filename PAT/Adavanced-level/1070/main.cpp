#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;
/*
	大部分测试案例都对的时候，要么边界问题要么类型问题
*/

struct Mooncake
{
	double inventory;  //inventory and prices 都要定义为double类型
	double prices;
};

bool cmp(Mooncake &m1 , Mooncake &m2)
{
	return (m1.prices/m1.inventory > m2.prices/m2.inventory);
}

int main()
{
	int n;
	double max_demand;
	cin >> n >> max_demand;
	vector <Mooncake> moonlist(n);
	for (int i = 0 ; i < n ; i++)
	{
		cin >> moonlist[i].inventory;
	}
	for (int i = 0 ; i < n ; i++)
	{
		cin >> moonlist[i].prices;
	}

	double total_profit = 0;
	sort(moonlist.begin() , moonlist.end() , cmp);
	for (int i = 0 ; i < n ; i++)
	{
		Mooncake m = moonlist[i];
		if (max_demand - m.inventory >= 0){
			max_demand -= m.inventory;
			total_profit += m.prices;
		}
		else{
			total_profit += max_demand * m.prices / m.inventory;
			break;
		}
	}

	cout << fixed << setprecision(2) << total_profit;

	return 0;
}