class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> nums;
        int i,j;
        for (i = 0, j = 0; i < m && j < n;){
            if (nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j]){
                nums.push_back(nums2[j]);
                j++;
            }
            else if (nums1[i] == nums2[j]){
                nums.push_back(nums1[i]);
                nums.push_back(nums2[j]);

                i++;
                j++;
            }
        }

        for (; i < m; i++){
            nums.push_back(nums1[i]);
        }
        for (; j < n; j++){
            nums.push_back(nums2[j]);
        }

        for (int k = 0; k < m+n; k++){
            nums1[k] = nums[k];
           // cout << nums[k] <<' ';
        }
    }
};
/*
Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

有序链表合并问题，两个指针，比较数值移动指针完成合并
*/