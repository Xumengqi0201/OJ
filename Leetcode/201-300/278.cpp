// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right){
        	int mid = left +(right-left)/2;　//不要写(left+right)/2,可能会溢出
       		if (isBadVersion(mid)){
       			right = mid; //不能写mid-1,因为有可能mid =1 ,这样ｌｅｆｔ就没有意义了
       		}
       		else{
       			left = mid+1;
       		}
       	}
       	return left;
    }
};
//第一时间想到二分法:O(lgN)