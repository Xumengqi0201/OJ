#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
/*
1.用struct Student存储id和score,N个Student和M个查询的case

2.查询有三种情况，分别是level，site和date，用三个函数实现。将对应的site和date信息作为字符串提取出来比对

3.对于第二种查询，用unordered_map存储site_id和对应的cnt。map无法对value排序，将map中的值存储到vec中按照规则排序。

*/
struct Student
{
	string id;
	int score;
};

struct Site
{
	string site_id;
	int count_stu;
	Site(string id, int cnt)
	{
		site_id = id;
		count_stu = cnt;
	}
};

void queries_1(vector <Student> & vec, string & term);
void queries_2(vector <Student> & vec, string & term);
void queries_3(vector <Student> & vec, string & term);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;  //n:有几个student，m有几个case
	cin >> n >> m;
	vector <Student> vec;
	for (int i = 0; i < n; i++) {
		Student s;
		cin >> s.id >> s.score;
		vec.push_back(s);
	}

	for (int i = 0; i < m; i++) {
		int Type;
		string Term;
		cin >> Type >> Term;

		cout << "Case " << i + 1 << ": " << Type << ' ' << Term << '\n';
		if (Type == 1) {
			queries_1(vec, Term);
		}
		else if (Type == 2) {
			queries_2(vec, Term);
		}
		else {
			queries_3(vec, Term);
		}
	}

	return 0;
}

int cmp1(Student s1, Student s2) {
	if (s1.score != s2.score) {
		return s1.score > s2.score;
	}
	else {
		return s1.id < s2.id;
	}
}
int cmp2(Site s1, Site s2) {
	if (s1.count_stu != s2.count_stu) {
		return s1.count_stu > s2.count_stu;
	}
	else {
		return s1.site_id < s2.site_id;
	}
}

void queries_1(vector <Student> & vec, string & term) {
	int len = vec.size();
	vector <Student> res;
	for (int i = 0; i < len; i++) {
		string id = vec[i].id;
		if (id[0] == term[0]) {
			res.push_back(vec[i]);
		}
	}

	if (res.size() == 0) {
		cout << "NA\n";
	}
	else {
		sort(res.begin(), res.end(), cmp1);
		for (auto stu : res) {
			cout << stu.id << ' ' << stu.score << '\n';
		}
	}

}

void queries_2(vector <Student> & vec, string & term) {
	int len = vec.size();
	int cnt = 0, sumscore = 0;
	for (auto stu : vec) {
		string site = stu.id.substr(1, 3);
		if (site == term) {
			cnt++;
			sumscore += stu.score;
		}
	}

	if (cnt == 0) {
		cout << "NA\n";
	}
	else {
		cout << cnt << ' ' << sumscore << "\n";
	}
}

void queries_3(vector <Student> & vec, string & term) {
	int len = vec.size();
	unordered_map <string, int > sitemap;
	for (auto stu : vec) {
		string date = stu.id.substr(4, 6);
		if (date == term) {
			string site_id = stu.id.substr(1, 3);
			sitemap[site_id]++;
		}
	}

	vector <Site> res;
	for (auto site : sitemap) {
		res.push_back(Site(site.first, site.second));
	}
	sort(res.begin(), res.end(), cmp2);

	if (res.size() == 0)
	{
		cout << "NA\n";
	}
	else {
		for (auto site : res) {
			cout << site.site_id << ' ' << site.count_stu << '\n';
		}
	}

}