#include <iostream>
#include <cmath>

using namespace std;

/*
	1.题目说输入的数是正整数，所以注意输入的数有可能是1,单独处理。
	2.循环终止的时候应当是n变为1的时候
	3.每一次输出p和k后，注意把k置0。接着找下一个可以被n整除的素数。
*/

bool isprime(int num){
	bool res = true;
	int up = sqrt(num);
	for (int i = 2; i <= up; i++){
		if(num % i == 0){
			res = false;
			break;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	cout << n << "=";
	if (n == 1) cout << "1";
	else{
		bool isstart = false;
		int p = 2, k = 0;

		while(n != 1){
			while (n % p == 0){
				n /= p;
				k++;
			}
			if (k != 0){  //k = 0的话说明p不可以被n整除，直接找下一个可以被n整除的p。
				if (isstart) cout << "*" << p;
				if (isstart == false){
					isstart = true;
					cout << p;
				}
				if (k != 1)  cout << "^" << k;
				k = 0;  //k置0
			}

			do{
				p++;
			}while (isprime(p) == false);
		}
	}
	
	return 0;
}