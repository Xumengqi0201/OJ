class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector <int> above(2,1), now;
    	for (int i = 0; i <= rowIndex; i++){
    		now.resize(i+1, 1);
    		if (i >=2 ){
    			for (int j = 1; j <= i-1; j++){
    				now[j] = above[j-1]+above[j];
    			}
    			above = now;
    		}

    	}
    	return now;
        
    }
};