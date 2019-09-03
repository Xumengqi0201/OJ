#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	int ID_Number, Virtue_Grade, Talent_Grade;
	Student(int id , int v , int t)
	{
		ID_Number = id;
		Virtue_Grade = v;
		Talent_Grade = t;
	}
};


bool cmp(Student &s1 , Student &s2)
{
	int sum1 = s1.Virtue_Grade + s1.Talent_Grade;
	int sum2 = s2.Virtue_Grade + s2.Talent_Grade;
	if (sum1 != sum2) 
		return sum1 > sum2;
	else if (s1.Virtue_Grade != s2.Virtue_Grade)
		return s1.Virtue_Grade > s2.Virtue_Grade;
	else 
		return s1.ID_Number < s2.ID_Number;
}

void showstu(vector <Student> &vec)
{
	sort(vec.begin() , vec.end() , cmp);
	int len = vec.size();
	for (int i = 0 ; i < len ; i++)
	{
		cout << vec[i].ID_Number << ' ' << vec[i].Virtue_Grade << ' ';
		cout << vec[i].Talent_Grade << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector <Student> sages, noblemen, foolmen, rest;
	int n, low, high;
	int id , v_grade, t_grade;
	int cnt = 0;
	cin >> n >> low >> high;

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> id >> v_grade >> t_grade;
		Student s(id , v_grade , t_grade);
		if (v_grade >= low && t_grade >= low)
		{
			cnt++;
			if (v_grade >= high && t_grade >= high)
			{
				sages.push_back(s);
			}
			else if (v_grade >= high && t_grade < high)
			{
				noblemen.push_back(s);
			}
			else if (v_grade < high && t_grade < high && v_grade >= t_grade)
			{
				foolmen.push_back(s);
			}
			else
			{
				rest.push_back(s);
			}
		}
	}
	

	cout << cnt << '\n';
	showstu(sages);
	showstu(noblemen);
	showstu(foolmen);
	showstu(rest);

	return 0;

}