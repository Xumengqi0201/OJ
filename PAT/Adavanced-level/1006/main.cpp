#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
	string id;
	string sign_in_time;
	string sign_out_time;
};

int main()
{
	int m ;
	cin >> m;
	vector <Person> res;
	for (int i = 0 ; i < m ; i++)
	{
		Person p;
		cin >> p.id >> p.sign_in_time >> p.sign_out_time;
		res.push_back(p);
	}

	Person unlocked , locked;
	//unlocked sign-in-time最早，locked sign-out-time最晚
	unlocked.sign_in_time = "23:59:59";  //一天中最晚的时间，有时间比它早，更新
	locked.sign_out_time = "00:00:00";   //一天中最早的时间，有时间比它晚，更新

	for (int i = 0 ; i < m ; i++)
	{
		if ( unlocked.sign_in_time > res[i].sign_in_time )
		{
			unlocked = res[i];
		}

		if ( locked.sign_out_time < res[i].sign_out_time )
		{
			locked = res[i];
		}
	}

	cout << unlocked.id <<' ' << locked.id <<'\n';

	return 0;
}

