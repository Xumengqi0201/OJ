# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

struct Student
{
	int ID;
	int defen;
	int caifen;

};

bool cmp(const Student s1, const Student s2) {  //四类考生的排序规则相同，cmp函数作为sort()的参数
	int sum1 = s1.defen + s1.caifen;
	int sum2 = s2.defen + s2.caifen;
	if (sum1 != sum2)
		return (sum1 > sum2);
	else if (s1.defen != s2.defen)
		return (s1.defen > s2.defen);
	else
		return s1.ID < s2.ID;
}

void show(const vector<Student> vec) {
	int size = vec.size();
	for (int i = 0; i < size; i++)
		cout << vec[i].ID << ' ' << vec[i].defen << ' ' << vec[i].caifen << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, L, H, M = 0;
	vector <Student> vec1, vec2, vec3, vec4;
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++) {
		Student stu;
		cin >> stu.ID >> stu.defen >> stu.caifen;
		if (stu.defen >= L && stu.caifen >= L) {
			M++;
			if (stu.defen >= H && stu.caifen >= H)
				vec1.push_back(stu);
			else if (stu.defen >= H && stu.caifen < H)
				vec2.push_back(stu);
			else if (stu.defen < H && stu.caifen < H && stu.defen >= stu.caifen)
				vec3.push_back(stu);
			else
				vec4.push_back(stu);
		}
	}

	sort(vec1.begin(), vec1.end(), cmp);
	sort(vec2.begin(), vec2.end(), cmp);
	sort(vec3.begin(), vec3.end(), cmp);
	sort(vec4.begin(), vec4.end(), cmp);
	
	cout << M << endl;
	show(vec1);
	show(vec2);
	show(vec3);
	show(vec4);


	return 0;

}