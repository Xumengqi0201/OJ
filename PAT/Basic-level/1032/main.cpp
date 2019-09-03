#include <iostream>

using namespace std;

#define N 100005

int arr[N] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int max_id = 0;
	for (int i = 0; i < n; i++)
	{
		int id, grade;
		cin >> id >> grade;
		arr[id] += grade;
		max_id = max_id > id ? max_id : id;//找到最大的id，接下来的循环上届设为max_id
	}

	int max_grade = 0, id = 0;
	for (int i = 1; i <= max_id; i++) {
		if (arr[i] > max_grade) {
			max_grade = arr[i];
			id = i;
		}
	}

	cout << id << ' ' << max_grade;

	return 0;
}