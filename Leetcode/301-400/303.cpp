class NumArray {
private:
	int *f = NULL;
public:
    NumArray(vector<int>& nums) {
        f = new int[nums.size()+1];  //nums为空的话，避免数组访问越界
  		//默认分配的初始值为0，保险起见
  		f[0] = 0; 
        for (int i = 0; i < nums.size(); i++){
        	f[i+1] = f[i]+nums[i];
        }

    }
    
    int sumRange(int i, int j) {
        return f[j+1]-f[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */