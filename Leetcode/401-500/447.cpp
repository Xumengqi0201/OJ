class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        int size = points.size();
        for (int i = 0; i < size; i++){
        	unordered_map <int, int> dist;
        	for (int j = 0; j < size; j++){
        		if (i == j)		continue;
        		int dx = points[i][0] - points[j][0];
        		int dy = points[i][1] - points[j][1];
        		dist[dx*dx+ dy*dy]++;
        	}
        	for (auto var : dist){
        		res += var.second*(var.second-1);
        	}
        }

        return res;
    }
};
/*
	开始题目没看懂，后来明白了，这就是个排列组合。。。。
	先固定一个点，然后用一个hashmap记录距离相同的点的对数。
	三个点a ,b,c 假设(a,b,c)和(a,c,b)是符合要求的就有两对
	2*1
	如果b,c,d到a的距离都相等，那么就有3×2= 6种满足要求的组合

*/