/*
    利用快速排序的思想，要想把偶数弄到数组右边，
    设置两个指针i,j
    i指向的数是偶数，j指向的数是奇数，且j永远在i右边
    找到后停止，将j的位置的数放到i位置上，再将i和j中间的数组右移
    这样可以保证偶数的顺序不变。
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() <= 1)    return;
        int len = array.size();
        for (int i = 0; i < len ; i++){
            //找到array[i]为偶数，array[j]为奇数
            //位运算效率高
            if ((array[i] & 1) != 0)    continue;
            int j = i+1;
            while (!(array[j] & 1)){
                if (j == len-1)
                    return;
                j++;
            }
            int tmp = array[i];
            array[i] = array[j];
            int cnt = j-i;
            while (cnt > 1){
                array[i+cnt] = array[i+cnt-1];
                cnt--;
            }
            array[i+1] = tmp;
        }
    }
};