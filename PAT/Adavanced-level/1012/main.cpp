#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
	int id , best;  //best最好排名对应的下标(0,1,2,3)
	//score[0]存放average，其他依次存放 C M E成绩
	int score[4] , rank[4]; 
	//rank[0]对应的'A'排名 ，rank[1]对应的'C'排名，rank[2]对应的'M'排名，rank[3]对应的'E'排名
};

Student stulist[2005];
//flag表明当期在对哪一个成绩排序
int exist[1000000] = {0} , flag = -1;

bool cmp(Student &s1 , Student &s2)
{
	return s1.score[flag] > s2.score[flag];
}

int main()
{
	int n , m;
	cin >> n >> m;

	for (int i = 0 ; i < n ; i++)
	{
		Student s;
		cin >> s.id >> s.score[1] >> s.score[2] >> s.score[3];
		s.score[0] = (s.score[1] + s.score[2] + s.score[3])/3;
		stulist[i] = s;  
	}

	for (flag = 0 ; flag <= 3 ; flag++)
	{
		sort(stulist , stulist+n , cmp);
		stulist[0].rank[flag] = 1;
		for (int i = 1 ; i < n ; i++)
		{
			stulist[i].rank[flag] = i+1;
			if (stulist[i].score[flag] == stulist[i-1].score[flag])
			{
				stulist[i].rank[flag] = stulist[i-1].rank[flag];
			}
		}
	}

	for (int i = 0 ; i < n ; i++)
	{
		int min = 0;
		for(int j = 1 ; j <=3 ;j++)
		{
			if ( stulist[i].rank[j] < stulist[i].rank[min] )
			{
				min = j;
			}
		}
		stulist[i].best = min;
	}

	/*
		1.给定一个id，对应的Student在stulist数组中的下标应该是：exist[s.id]-1
		2.快速查找，不用遍历stulist，hashing
		3.如果exist[s.id] == 0 ,则这个id无效，直接输出N/A
		注意：一定要在全部排好序以后再做这一步
	*/
	for (int i = 0 ; i < n ; i++)
	{
		exist[stulist[i].id] = i+1;
	}

	char order[4] = {'A' , 'C' , 'M' , 'E'};
	int query;
	for (int i = 0 ; i < m ; i++)
	{
		cin >> query;
		if (exist[query]){
			int tmp = exist[query] - 1;
			Student s = stulist[tmp];
			cout << s.rank[s.best] << ' ' << order[s.best];
			cout <<'\n';

		}
		else 
		{
			cout << "N/A\n";
		}
	}
	
	return 0;
}