class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector <int> res;
        for (int i = 0 ; i < numbers.size()-1; i++){
        	int tmp = target-numbers[i];
        	int left = i+1, right = numbers.size()-1;
        	while(left < right){
        		int mid = (left+right) / 2;
        		if (numbers[mid] == tmp){
        			res.push_back(i);
        			res.push_back(mid);
        			break;
        		}
        		if (numbers[mid] > tmp){
        			right = mid-1;
        		}
        		else{
        			left = mid+1;
        		}
        	}

        }

        return res;
    }
};

/*
	1.二分法
	2.双指针法
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector <int> res;
        int left = 0, right = numbers.size()-1;
        while (left < right){
        	int tmp = numbers[left] + numbers[right];
        	if (tmp == target){
        		res.push_back(left+1);
        		res.push_back(right+1);
        		break;
        	}
        	else if (tmp < target){
        		left++;
        	}
        	else{
        		right--;
        	}
        }
        return res;
    }
};