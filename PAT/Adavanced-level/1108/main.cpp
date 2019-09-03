#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

using namespace std;

double str_int(string & num){
	double res;
	stringstream ss;
	ss << num;
	ss >> res;
	return res;
}

bool islegal(string & str){
	bool res = true;
	int len = str.size();
	int i =0 , point_cnt = 0 , point_place = 0;
	if (str[0] == '-')  i++; //如果是负数形式的话，从str第一位开始判断
	for ( ; i < len ; i++){
		if (!isdigit(str[i]) && str[i] != '.'){  //如果一个字符即不是小数点也不是数字，那么这个数肯定不合法
			res = false;
			break;
		}
		if (str[i] == '.'){
			point_cnt++;
			point_place = i;  //记录下小数点的位置

		}
		if (point_cnt >= 2){  //只能有一个小数点
			res = false;
			break;
		}
	}
 	//没有多个小数点，没有除了小数点以外的非数字的字符
	if (res == true){ 
		//首先是小数但是精度不符合要求
		if (point_cnt == 1 && len-1-point_place > 2)  res = false;  //说明不止两位小数	
	}
	if (res == true){  //可以把字符串转换为数字看在不在合理范围内
		double tmp = str_int(str);
		if (tmp < -1000 || tmp > 1000)  res = false;
	}

	return res;
}

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n , cnt = 0;
	cin >> n;
	string str;
	double sum = 0;
	for (int i = 0; i < n; i++){
		cin >> str;
		bool sign = islegal(str);
		if (!sign){
			cout << "ERROR: " << str <<  " is not a legal number\n";
		}
		else{
			cnt++;
			sum += str_int(str);
		}
	}

	if (cnt == 0) {
		cout <<"The average of 0 numbers is Undefined\n";
	}
	else{
		if (cnt != 1)  cout << "The average of " << cnt << " numbers is ";
		else  cout <<  "The average of " << cnt << " number is ";
		cout << fixed <<setprecision(2) << sum/cnt << '\n';
	}

	return 0;
}