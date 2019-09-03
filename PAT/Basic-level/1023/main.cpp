#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	if (arr[0] == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] != 0)
			{
				for (int j = 0; j < arr[i]; j++)
				{
					cout << i;
				}
			}
		}
	}
	else
	{
		for (int i = 1; i < 10; i++)
		{
			if (arr[i] != 0)//找到第一个不是0的数
			{
				cout << i;  //输出这个数
				arr[i]--;
				for (int j = 0; j < arr[0]; j++)
				{
					cout << '0'; //输出剩下的0
				}
				arr[0] = 0;
				for (int j = 0; j < arr[i]; j++)
				{
					cout << i; //输出剩下的这个数
				}
			}
		}

	}

	return 0;
}