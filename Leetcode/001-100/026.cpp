/*
Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int nums_size=nums.size();

    	if (nums_size==0||nums_size==1)
    		return nums_size;

    	int length=1;//要求O(1)空间复杂度，维护两个下标即可
    	for (int i=0;i<nums_size-1;i++){
    		if (nums[i] != nums[i+1]){
    			nums[leng++]=nums[i+1];
    		}
    	}
    	nums.resize(length);
    	return length;
    }
};
/*
c++ vector--resize():
Resizes the container so that it contains n elements.

If n is smaller than the current container size, the content is reduced to its first n elements,
 removing those beyond (and destroying them).

If n is greater than the current container size, the content is expanded by inserting at the end
as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as
copies of val, otherwise, they are value-initialized.

If n is also greater than the current container capacity,
an automatic reallocation of the allocated storage space takes place.

Notice that this function changes the actual content of the container by inserting or erasing elements from it.
*/