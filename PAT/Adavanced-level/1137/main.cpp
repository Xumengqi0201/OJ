#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

/*
	定义一个结构体，把Gmid和Gfinal都初始化为-1；定义一个unsordered_map <string,struct>存储结果
	1.第一轮全部输入的是Gp；第二轮输入的是Gmid；第三轮输入的是Gfinal。
	2.用map存储 所有 输入的信息
	3.遍历map符合条件的放到一个vector中，注意要对G四舍五入。然后排序，最后输出
*/
struct Student
{
	string id;
	int Gp =-1 , Gmid = -1, Gfinal = -1, G;
};

bool cmp(Student &s1 , Student &s2)
{
	if (s1.G != s2.G)
		return s1.G > s2.G;
	else 
		return s1.id < s2.id;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	unordered_map <string , Student> stumap;
	int Gp, Gmid, Gfinal; string id;
	int p, m, n;
	cin >> p >> m >>n;
	for (int i = 0 ; i < p ; i++)
	{
		cin >> id >> Gp;
		stumap[id].id = id;
		stumap[id].Gp = Gp;	
	}

	for (int i = 0 ; i < m ; i++)
	{
		cin >> id >> Gmid;
		stumap[id].id = id;
		stumap[id].Gmid = Gmid;
	}

	for (int i = 0 ; i < n ; i++)
	{
		cin >> id >> Gfinal;
		stumap[id].id = id;
		stumap[id].Gfinal = Gfinal;
	}

	vector <Student> anslist;
	double tmp;
	for (auto k : stumap)
	{
		Student s = k.second;
		if (s.Gp < 200)	continue;

		if (s.Gmid > s.Gfinal){ 
			s.G = tmp = 0.4*s.Gmid + 0.6*s.Gfinal;
			if (tmp - s.G >= 0.5){ 
				s.G++;
			}
		}
		else{
			s.G = s.Gfinal;
		}
		if (s.G >= 60){
			anslist.push_back(s);
		}
	}

	sort(anslist.begin() , anslist.end() , cmp);
	int len = anslist.size();
	for (int i = 0; i < len; i++)
	{
		Student s = anslist[i];
		cout << s.id << ' ' << s.Gp << ' ' << s.Gmid; 
		cout << ' ' << s.Gfinal << ' ' << s.G << '\n';
	}

	return 0;
}