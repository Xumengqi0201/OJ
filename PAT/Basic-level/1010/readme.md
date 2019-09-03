#	1010 一元多项式求导 （25 分）

设计函数求一元多项式的导数。（注：x<sup>n</sup>（n为整数）的一阶导数为nx<sup>n−1</sup>。）

##	输入格式:

以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

##	输出格式:

以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

##	输入样例:

```
3 4 -5 2 6 1 -2 0
```

##	输出样例:

```
12 3 -10 1 6 0
```
___

#	思路

```C++

# include <iostream>
# include <sstream>
# include <string>
using namespace std;

int str_num(string s){//字符串转为数字
	stringstream ss;
	ss<<s;
	int res;
	ss>>res;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string mystr,tmp;
	int start=1;
	getline(cin,mystr);
	stringstream ss(mystr);

	while(!ss.eof()){
		getline(ss,tmp,' ');
		int coef=str_num(tmp);
		getline(ss,tmp,' ');
		int expo = str_num(tmp);

		if (coef*expo){
			if (start==0)
				cout<<' ';
			else
				start=0;
			cout<<coef*expo<<' '<<expo-1;
		}
	}

	if (start)
		cout<<"0 0";

	return 0;
}
```

这段代码用了`getline`函数，但是测试有两个案例不通过，很奇怪。和main.cpp的代码逻辑是一样的，主要是熟悉sstream的一些用法。