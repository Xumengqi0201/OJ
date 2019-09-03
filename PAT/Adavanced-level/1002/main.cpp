#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct polynum {
	int expo;  //指数
	double coeff;	//系数
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k1, k2, i, j;
	cin >> k1;
	vector <polynum> poly1, poly2, res;
	for (i = 0; i < k1; i++)
	{
		polynum tmp;
		cin >> tmp.expo >> tmp.coeff;
		poly1.push_back(tmp);
	}

	cin >> k2;
	for (i = 0; i < k2; i++)
	{
		polynum tmp;
		cin >> tmp.expo >> tmp.coeff;
		poly2.push_back(tmp);
	}
	//多项式按照指数的降序排列
	for (i = 0, j = 0; i < k1 && j < k2;)
	{
		
		if (poly1[i].expo > poly2[j].expo) {
			res.push_back(poly1[i]);
			i++;  //poly1的某一项数字指数大于poly2的某一项数字指数,那么下标移动poly1的下一项
		}
		else if (poly1[i].expo < poly2[j].expo) {
			res.push_back(poly2[j]);
			j++;
		}
		else {
			double coeff_sum = poly1[i].coeff + poly2[j].coeff;
			if (coeff_sum != 0) {  //指数相同系数不为0的项放到res中
				polynum tmp;
				tmp.expo = poly1[i].expo;
				tmp.coeff = coeff_sum;
				res.push_back(tmp);
			}//两组多项式的索引都向后移动一位
			i++;
			j++;
		}
	}

	for (; i < k1; i++) {
		res.push_back(poly1[i]);
	}
	for (; j < k2; j++) {
		res.push_back(poly2[j]);
	}

	int len = res.size();
	cout << len ;
	if (len != 0){
		for (i = 0; i < len; i++) {
			cout << ' ' << res[i].expo << ' ';
			cout << fixed << setprecision(1) << res[i].coeff;
		}
	}

	return 0;
}