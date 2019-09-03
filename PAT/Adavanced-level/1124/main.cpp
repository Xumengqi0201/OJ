#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string namelist[1005];
unordered_map <string , bool> raffle_map;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	int m , n , s;
	cin >> m >> n >> s;
	bool has_winner = false;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> namelist[i];
	}
	for (int i = s ; i <= m ;)
	{
		if (i == s)
		{
			cout << namelist[i] << '\n';
			raffle_map[namelist[i]] = true;
			i += n;
			has_winner = true;
		}
		else
		{	//说明之前没有中奖
			if (raffle_map[namelist[i]] == false)
			{
				raffle_map[namelist[i]] = true;
				cout << namelist[i] << '\n';
				i += n;
			} 
			else  //说明这个人之前已经中奖了，向下找下一个中奖的人
			{
				i++;
			}
		}

	}

	if (!has_winner){
		cout << "Keep going..." << '\n';
	}

	return 0;
}