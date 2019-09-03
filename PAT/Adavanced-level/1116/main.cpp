#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
	int id = -1;
	string award;
	bool has_checked = false;
};

bool isprime(int n)
{
	bool res = true;
	int upbound = sqrt(n);
	for (int i = 2 ; i <= upbound ; i++)
	{
		if (n % i == 0)
		{
			res = false;
			break;
		}
	}
	return res;
}

Student stulist[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		Student s;
		cin >> s.id;
		if (i == 0)
		{
			s.award = "Mystery Award";
		}
		else if (isprime(i+1))
		{
			s.award = "Minion";
		}
		else
		{
			s.award = "Chocolate";
		}
		stulist[s.id] = s;
	}

	int k ,id;
	cin >> k;
	for (int i = 0 ; i < k ; i++)
	{
		cin >> id;
		cout << setfill('0') << setw(4) << id << ": ";
		if (stulist[id].id == -1)
		{
			cout << "Are you kidding?";
		}
		else if (stulist[id].has_checked == false)
		{
			cout << stulist[id].award;
			stulist[id].has_checked = true;
		}
		else if (stulist[id].has_checked == true)
		{
			cout << "Checked";
		}
		cout << '\n';
	}

	return 0;
}