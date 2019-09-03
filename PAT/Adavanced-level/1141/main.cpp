#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
1.用unordered_map把school_name作为key，对应的School结构体作为value

2.所有输入的school_name中的字符都要利用tolower()转换为小写

3.结构体School成员total_score用double类型定义，最后用int()强制转换得到总分的正数部分

4.最后把schoolmap中的value存到vector中，按照排序规则对vector排序

5.输出，注意排名的调整
*/

struct School
{
	string name;
	double total_score = 0;   //最后要把doublescore转换为int
	int cnt = 0;
};

string School_to_lower (string &school_name)
{
	int len = school_name.size();
	for (int i = 0; i < len ; i++)
	{
		school_name[i] = tolower(school_name[i]);
	}
	return school_name;
}

bool cmp(School s1,School s2){
	if (s1.total_score != s2.total_score){
		return s1.total_score > s2.total_score;
	}
	else if (s1.cnt != s2.cnt){
		return s1.cnt < s2.cnt;
	}
	else{
		return s1.name < s2.name;
	}
}

int main()
{
	int n;
	cin >> n;
	unordered_map < string , School > schoolmap;

	for (int i = 0 ; i < n ; i++)
	{
		string id , school_name;
		int score;
		cin >> id >> score >> school_name;

		school_name = School_to_lower(school_name);
		schoolmap[school_name].name = school_name;
		schoolmap[school_name].cnt++;
		//ScoreB/1.5 + ScoreA + ScoreT*1.5
		char ch = id[0];
		if (ch == 'A'){
			schoolmap[school_name].total_score += score;
		}
		else if (ch == 'B'){
			schoolmap[school_name].total_score += score/1.5;
		}
		else if (ch == 'T'){
			schoolmap[school_name].total_score += score*1.5;
		}
	}

	vector <School> res;
	for (auto kv : schoolmap){
		//取total_score的整型部分
		kv.second.total_score = int (kv.second.total_score);
		res.push_back(kv.second);
	}

	sort(res.begin() , res.end() , cmp);
	int len = res.size();
	int rank = 1;
	cout << len << '\n';
	cout << rank << ' ' << res[0].name << ' ';
	cout << res[0].total_score << ' ' << res[0].cnt << '\n';

	for (int i = 1; i < len ; i++){
		if (res[i].total_score != res[i-1].total_score){
			rank = i+1;
		}
		cout <<rank << ' ' << res[i].name <<' ';
		cout <<res[i].total_score << ' ' << res[i].cnt << '\n';
	}



	return 0;
}