#include <iostream>
#include <iomanip>
using namespace std;
/*
1.开一个大数组，把expo作为下标索引

2.设置max_expo,每输入一个expo，就更新max_expo。这样输出两个多项式相加的结果时，可以减少遍历次数

3.输入第二组数的时候，直接将对应的expo相加

4.按照格式输出系数不为0的项
*/
double poly[1005] = {0};

int main()
{
	int k1 , k2 , expo , max_expo = 0 , cnt = 0;
	double coeff;
	cin >> k1;
	for (int i = 0 ; i < k1 ; i++){
		cin >> expo >> coeff;
		poly[expo] = coeff;
		max_expo = max_expo > expo ? max_expo : expo;
	}
	cin >> k2;
	for (int i = 0 ; i < k2 ; i++){
		cin >> expo >> coeff;
		poly[expo] += coeff;
		max_expo = max_expo > expo ? max_expo : expo;
	}

	for (int i = 0 ; i <= max_expo ; i++){
		if( poly[i] != 0 ){
			cnt++;
		}
	}

	cout << cnt;
	if (cnt != 0){
		for (int i = max_expo ; i >= 0 ; i--){
			if( poly[i] != 0 ){
				cout << ' ' << i << ' ' ;
				cout<< fixed << setprecision(1) << poly[i];
			}
		}
	}


	return 0;
}