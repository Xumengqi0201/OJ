class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int> > res;
        for (int i = 0; i < numRows; i++){
            vector <int> now(i+1,1);
            if (i >= 2){
                vector <int> above = res[i-1];
                for (int j =1; j <= i-1; j++){
                    now[j] = above[j-1]+above[j];
                }
            }
            res.push_back(now);
        }
        return res;

    }
};
//这一题很简单，没啥写的