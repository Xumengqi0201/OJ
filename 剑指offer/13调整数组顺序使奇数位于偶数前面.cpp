class Solution {
public:
    void reOrderArray(vector<int> &array) {
    	//1个数不需要做任何操作
        for (int i = 1; i < array.size(); i++){
        	//因为==比&优先级高，所以千万不要写成if (array[i]&1 == 0)
        	if (!(array[i] & 1))	continue;
        	/*
        		用位运算判断奇偶更快
        		执行到内层循环说明array[i]是奇数，把这个奇数插到它前面的偶数前面
        	*/
        	for (int j = i; j > 0; j--){
        		if (!(array[j-1] & 1)){
        			int tmp = array[j-1];
        			array[j-1] = array[j];
        			array[j] = tmp;
        		}
        	}
        }
    }
};