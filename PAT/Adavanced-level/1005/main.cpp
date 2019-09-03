#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string num_to_str(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();

}

int main()
{
	const string number_name[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string n;
	cin >> n;
	int sum = 0;
	int len = n.size();
	for (int i = 0 ; i < len ; i++)
	{
		sum += n[i]-'0';
	}
	string res = num_to_str(sum);
	len = res.size();
	for (int i = 0 ; i < len ; i++)
	{
		cout << number_name[res[i]-'0'];
		if (i != len - 1)
		{
			cout << ' ';
		}
	}
	cout <<'\n';

	return 0;
}