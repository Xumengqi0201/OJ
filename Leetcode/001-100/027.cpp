#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	1.这个题的意思是在给定vector里面删除给定的元素（全部），并且不改变原来vector中元素的顺序。空间复杂度要求O(1)
	2.每找到一个元素等于给定的元素，就从元素后面一个数开始找，找到第一个不等于给定元素的数，交换。
	3.如果发现循环结束以后j == len说明最后一个元素也等于给定元素，这个时候说明从i开始到最后一个元素都是给定的元素，跳出循环即可。
	4.统计一下有多少个给定的元素就对容器执行多少次pop操作，最后返回新的容器的size。
	5.这个题的思想就是，把后面的元素和前面的元素交换，不停的交换，但是不改变相互的顺序。到达循环终止条件全部pop出来就可以。
	6.如果遇到一个给定元素就擦除，会打乱这个指针，又要重头开始遍历。效率低。

*/

int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), i, j;
        for (i = 0; i < len; i++){
            if (val == nums[i]){
                for (j = i+1; j < len && nums[j] == val; j++);
               	if (j == len)  break;
                swap(nums[i], nums[j]);
            }
        }
        int cnt = len - i;
        for (j = 0; j < cnt; j++){
            nums.pop_back();
        }
        return nums.size();
    }


int main(){
	vector <int> nums;
	nums = { 3,2,2,3 };
	removeElement(nums, 3);

	return 0;
}
