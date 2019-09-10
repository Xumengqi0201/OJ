class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
  		int count[10] = {0};
  		int up = numbers.size()/2;
  		for (int i = 0; i < numbers.size(); i++){
  			count[numbers[i]]++;
  			if (count[numbers[i]] > up)	 return numbers[i];
  		}  
  		return 0;
    }
};