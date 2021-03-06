#	1013 数素数 （20 分）

令Pi表示第 i 个素数。现任给两个正整数 M≤N≤104，请输出 PM到 PN的所有素数。

##	输入格式：

输入在一行中给出 M 和 N，其间以空格分隔。

##	输出格式：

输出从 PM到 PN的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

##	输入样例：

```
5 27
```

##	输出样例：

```
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
```

<br>

#	思路

*	写一个判断素数的函数，for循环，循环终止条件为`sqrt(num)`(sqrt()需要`include <cmath>`)。

*	2是第一个素数，找出第M个素数:PM后从PM开始往后找到PN停止，计数器cnt计数。

*	输出格式：输出素数。如果这个数不是PN，那么如果这个数在一行的第十个，就换行否则输出空格；如果这个数是PN，那么按照要求仅输出素数。
