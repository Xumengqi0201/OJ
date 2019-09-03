#include <iostream>
#include <string>

using namespace std;

struct student{
	string name;
	string ID;
	int grade;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n=0;
	student high_stu,low_stu,stu;
	cin>>n;
	cin>> stu.name>> stu.ID>> stu.grade;
	high_stu = low_stu= stu;
	for (int i=1;i<n;i++){
		cin>>stu.name>>stu.ID>>stu.grade;
		if (stu.grade>high_stu.grade)
			high_stu=stu;
		if (stu.grade<low_stu.grade)
			low_stu=stu;
	}

	cout<<high_stu.name<<' '<<high_stu.ID<<endl;
	cout<<low_stu.name<<' '<<low_stu.ID;

	return 0;
}