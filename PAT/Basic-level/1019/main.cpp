# include <iostream>
# include <algorithm>
# include <functional>

using namespace std;

void print_digit(int digit[]) {
	for (int i = 0; i < 4; i++)
	{
		cout << digit[i];
	}
}

int arr_num(int digit[])
{
	int res = 0;
	for (int i = 0, base = 1000; i < 4; i++, base /= 10)
	{
		res += base * digit[i];
	}
	return res;
}

void num_arr(int n, int digit[])
{
	for (int i = 3; i >= 0; i--)
	{
		int tmp = n % 10;
		n /= 10;
		digit[i] = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int number, digit[4];
	cin >> number;
	num_arr(number, digit);
	if ((digit[0] == digit[1]) && (digit[1] == digit[2]) && (digit[2] == digit[3]))
	{
		print_digit(digit);
		cout << " - ";
		print_digit(digit);
		cout << " = 0000";
	}
	else if(number==6174)
	{
		cout << "7641 - 1467 = 6174";
	}
	else
	{
		while (number != 6174) {
			sort(digit, digit + 4, greater<int>());
			print_digit(digit);
			cout << " - ";
			int num1 = arr_num(digit);

			sort(digit, digit + 4, less<int>());
			print_digit(digit);
			cout << " = ";
			int num2 = arr_num(digit);

			number = num1 - num2;
			num_arr(number, digit);
			print_digit(digit);
			cout << endl;
		}
	}
	return 0;
}