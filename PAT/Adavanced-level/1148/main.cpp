#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int player[108] = { 0 };
bool isvalid(int wolv1, int wolv2, int player_cnt);
bool islying(int id, int wolv1, int wolv2);

int main()
{
	int player_cnt;
	bool has_solution = false;
	cin >> player_cnt;

	for (int i = 1; i <= player_cnt; i++)
	{
		cin >> player[i];
	}

	for (int i = 1; i < player_cnt; i++)
	{
		for (int j = i + 1; j <= player_cnt; j++)
		{
			if (isvalid(i, j, player_cnt) == true)  //i,j是狼人的id
			{
				cout << i << ' ' << j << '\n';
				has_solution = true;
				break;
			}
		}
		if (has_solution == true)
		{
			break;
		}
	}

	if (has_solution == false) {
		cout << "No Solution\n";
	}

	return 0;
}

bool islying(int id, int wolv1, int wolv2)
{
	bool res = true; //撒谎
	int info = player[id];
	if (info < 0) {
		if (fabs(info) == wolv1 || fabs(info) == wolv2) {
			res = false; //没撒谎
		}
	}
	else {
		if (info != wolv1 && info != wolv2) {
			res = false; //没撒谎
		}
	}
	return res;
}

bool isvalid(int wolv1, int wolv2, int player_cnt) //id1和id2中有一个撒谎，剩下的都是人，且其中有一个在撒谎
{
	bool res = false;
	vector <int> lie;
	for (int i = 1; i <= player_cnt; i++)
	{
		if (islying(i, wolv1, wolv2) == true)
		{  //第i个player在撒谎
			lie.push_back(i);
		}
	}
	if (lie.size() == 2) {
		if (lie[0] == wolv1 && lie[1] != wolv2) {  //wolv1<wolv2
			res = true;
		}
		else if (lie[0] != wolv1 && lie[1] == wolv2) {
			res = true;
		}
		else if (lie[0] == wolv2) {
			res = true;
		}
	}

	return res;

}