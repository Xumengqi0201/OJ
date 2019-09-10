class Solution {
private:
	int partition(vector <int>& input, int p, int r){
		int pivot = input[r];
		int i = p-1;
		for (int j = p; j < r; j++){
			if (input[j] <= pivot){
				swap(input[j], input[++i]);
			}
		}
		swap(input[++i], input[r]);
		return i;
	}
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector <int> ans;
        if (input.empty() || k > input.size() || k <= 0){
        	return ans;
        }
        int p = 0, r = input.size()-1;
        while (p < r){
        	int index = partition(input, p, r);
        	if (index == k-1){
        		for (int i = 0; i <= k-1; i++){
        			ans.push_back(input[i]);
        			break;
        		}
        	}
        	else if (index < k-1){
        		p = index+1;
        	}
        	else{
        		r = index-1;
        	}
        }
        return ans;
    }

};