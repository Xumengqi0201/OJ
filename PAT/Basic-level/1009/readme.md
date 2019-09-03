#	1009 说反话 （20 分）

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

##	输入格式：

测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

##	输出格式：

每个测试用例的输出占一行，输出倒序后的句子。

##	输入样例：

```
Hello World Here I Come
```

##	输出样例：

```
Come I Here World Hello
```
___

#	思路

*	1.`stringstream+getline` 实现字符串分割，`stringstream`是一种高级的类，可以实现数字、字符串之间的相互转换。

```c++
	string mystr;
	getline(cin,mystr);
	stringstream ss(mystr);

	while(!ss.eof()){
		getline(ss,mystr,' ');//字符串分割
		sta.push(mystr);
	}
```

*	2.题目要求倒序输出，很容易联想到利用`stack`实现。