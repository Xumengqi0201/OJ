#include <iostream>
#include <iomanip>

using namespace std;

char get_choice(int i){
	char res;
	if (i == 0)
		res = 'W';
	else if ( i == 1)
		res = 'T';
	else 
		res = 'L';

	return res;
}

int main()
{
	double arr1[3] , arr2[3] , arr3[3];
	cin >> arr1[0] >> arr1[1] >> arr1[2];
	cin >> arr2[0] >> arr2[1] >> arr2[2];
	cin >> arr3[0] >> arr3[1] >> arr3[2];

	int max_i1 = 0 , max_i2= 0 , max_i3 = 0;
	for (int i = 0 ; i < 3 ; i++)
	{
		if (arr1[max_i1] < arr1[i]){
			max_i1 = i;
		}
	}

	for (int i = 0 ; i < 3 ; i++)
	{
		if (arr2[max_i2] < arr2[i]){
			max_i2 = i;
		}
	}

	for (int i = 0 ; i < 3 ; i++)
	{
		if (arr3[max_i3] < arr3[i]){
			max_i3 = i;
		}
	}
	double sum = (arr1[max_i1]*arr2[max_i2]*arr3[max_i3]*0.65 - 1)*2;
	
	cout << get_choice(max_i1) << ' ' << get_choice(max_i2);
	cout <<' ' << get_choice(max_i3) << ' ';
	cout << fixed << setprecision(2) <<sum;


	
	
	return 0;
}