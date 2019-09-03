#	1029 旧键盘 （20 分）

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

##	输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

##	输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

##	输入样例：
```
7_This_is_a_test
_hs_s_a_es
```
##	输出样例：
```
7TI
```
___

#	思路

*	1.字符'0'-'9'对应的asc码为48-57，'_'对应的acs码为95,大写字母对应的asc码为65-90。开一个大数组，用字符的acs码作为下标索引。

*	2.遍历s2,在charmap上置位使其不等于0；遍历s1,如果charmap对应位置为0，说明这是缺失字符输出，然后重新置位，避免重新输出。