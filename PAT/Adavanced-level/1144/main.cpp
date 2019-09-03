#include <iostream>
#include <map>

using namespace std;

/*
	1.把所有的数字出现的次数存在map中
	2.从number 1开始，如果对应的number[map]==0，对应的number缺失
	3.或者定义迭代器:
	map <int , int> :: iterator iter;
	iter = number_map.find(number)
	if (iter != number_map.end()) //说明字典中有这个number作为key
*/

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	map <int , int> number_map;
	int n , number; 
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> number;
		number_map[number]++;
	}

	/*
	number = 1;
	while (number_map[number] != 0)
	{
		number++;
	}
	cout << number << '\n';
	*/

	map <int , int > :: iterator iter;
	number = 0;
	do
	{
		number++;
		iter = number_map.find(number);
	}while (iter != number_map.end());  //find number
	cout << number;

	return 0;
}