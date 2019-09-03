#include <iostream>

using namespace std;


int main()
{
	int Floor[104] = {0};
	int n , sum = 0;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> Floor[i];
	}

	for (int i = 1 ; i <= n ; i++)
	{
		int next = Floor[i] - Floor[i-1];
		if (next > 0){
			sum += 6*next + 5;
		}
		else{
			sum += -4*next + 5;
		}
	}

	cout << sum <<'\n';

	return 0;
}