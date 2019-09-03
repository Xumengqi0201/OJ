#include <iostream>
#include <cmath>
using namespace std;


class Number
{
public:
	long long numer, denom, k = 0;

	Number() {};  //无参构造函数
	Number(long long n, long long d);
	void simplify();
	// 化简有理数之前进行四则运算,运算的结果化简都在simplify函数中进行
	Number plus(Number & n);
	Number minus(Number & n);
	Number multiply(Number & n);
	Number divide(Number & n);
	void showNum();
	//lowest common multiple 最小公倍数 ，greatest common divisor 最大公约数
	long long gcd(long long a, long long b);
};

int main()
{
	int a1, b1, a2, b2;
	char ch = '/';
	cin >> a1 >> ch >> b1;
	cin >> a2 >> ch >> b2;

	Number n1(a1, b1), n2(a2, b2);
	// 做完四则运算以后再化简n1,n2 
	// 1. +,-,*一定是有意义的，/要判断除数是不是0 ; 先判断除数是不是0，不是0才能做除法运算
	Number a = n1.plus(n2);
	a.simplify();
	Number b = n1.minus(n2);
	b.simplify();
	Number c = n1.multiply(n2);
	c.simplify();
	Number d;
	bool isdivide = false;//是否做正常除法用isdivide判断
	if (n2.numer != 0) {
		d = n1.divide(n2);
		d.simplify();
		isdivide = true;
	}

	n1.simplify();
	n2.simplify();

	n1.showNum();
	cout << " + ";
	n2.showNum();
	cout << " = ";
	a.showNum();
	cout << '\n';

	n1.showNum();
	cout << " - ";
	n2.showNum();
	cout << " = ";
	b.showNum();
	cout << '\n';

	n1.showNum();
	cout << " * ";
	n2.showNum();
	cout << " = ";
	c.showNum();
	cout << '\n';

	n1.showNum();
	cout << " + ";
	n2.showNum();
	cout << " = ";
	if (isdivide == false) {
		cout << "Inf\n";
	}
	else {
		d.showNum();
		cout << '\n';
	}

	return 0;
}

Number :: Number(long long n, long long d)
{
	numer = n;
	denom = d;
}

void Number::simplify()
{
	long long k = numer / denom;
	numer = numer % denom;
	// 1.假分数，numer要么是正数要么是0(k!=0的时候，负号肯定在k上，numer肯定是正数，denom就是正数)
	// eg. -5/3=-1,-5%3=-2,那么-5/3 = -1 2/3
	if (k != 0) {
		numer = fabs(numer);
	}
	//	2.真分数，不需要修改numer 和 denom
}

void Number::showNum()   //化简过的分数
{
	if (k < 0 || numer < 0) {
		cout << "(";
	}
	//	1.numer是0的话就是整数,直接输出整数部分( 0和非0都是这种情况 )
	if (numer == 0) {
		cout << k;
	}
	//	2.如果numer！= 0 && k=0,就是真分数;
	else if (k == 0) {
		cout << numer << '/' << denom;
	}
	//	3.如果numer != 0 && k!=0,就是假分数;
	else if (k != 0) {
		cout << k << ' ' << numer << '/' << denom;
	}

	if (k < 0 || numer < 0) {
		cout << ")";
	}

}

long long Number::gcd(long long a, long long b) //先求最大公约数gcd，最小公倍数 = a*b/gcd
{  //gcd(a, b) = gcd(b, a mod b)
	if (b == 0) {
		return a;
	}
	else {
		return  gcd(b, a % b);
	}
}


Number Number::plus(Number & n)
{
	Number res;
	long long _gcd = gcd(denom, n.denom);
	res.denom = (denom * n.denom) / _gcd;
	res.numer = numer * n.denom / _gcd + n.numer * denom / _gcd;
	return res;
}

Number Number::minus(Number & n)
{
	Number res;
	long long _gcd = gcd(denom, n.denom);
	res.denom = (denom * n.denom) / _gcd;
	res.numer = numer * n.denom / _gcd - n.numer * denom / _gcd;
	return res;
}

Number Number::multiply(Number & n)
{
	Number res;
	res.numer = numer * n.numer;
	res.denom = denom * n.denom;
	return res;
}

Number Number::divide(Number & n)  //n不是0
{
	Number res;
	res.numer = numer * n.denom;
	res.denom = denom * n.numer;
	return res;
}