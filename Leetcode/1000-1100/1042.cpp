/*
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Note:

1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.



*/

/*
    贪心，题目说了肯定有解


*/


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector <int> ans(N, 0);
        vector <int> graph[N+1];
        for (int i = 0; i< paths.size(); i++){
            int v1 = paths[i][0];
            int v2 = paths[i][1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        for (int i = 1; i <= N; i++){
            vector <int> colors(5, 0);//set
            for (int j = 0; j < graph[i].size(); j++){
                int v = graph[i][j];
                int color = ans[v-1];
                colors[color] = 1; //用过的颜色标记
            }
            for (int c = 1; c <= 4; c++){
                /*
                    如果不存在解，判断就是找不到一个没用过的颜色
                */
                if (colors[c] == 0){//遇到它相邻的点么有用过的颜色，使用它
                    ans[i-1] = c;
                    break;
                }
            }
        }
        return ans;
        
   
    }
    
};
