#	1030 完美数列 （25 分）

给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

##	输入格式：

输入第一行给出两个正整数 N 和 p，其中 N（≤10<sup>5</sup>）是输入的正整数的个数，p（≤10<sup>9</sup>）是给定的参数。第二行给出 N 个正整数，每个数不超过 10<sup>9</sup>。

##	输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

##	输入样例：
```
10 8
2 3 20 4 5 1 6 7 8 9
```
##	输出样例：
```
8
```
___

#	思路

*	1.mp要定义为long long

*	2.对数组排序

*	3.设置imin和imax，找到mp=array[0]*p对应的imax，从这个imax后面的数判断是否小于等于新的mp，if某一个数大于mp，则这个数之前的数就是mp所对应的imax。
但是有可能到最后也没有数大于mp，设置标志位看imax是否得到更新。如果没有，那么imax就是n-1。