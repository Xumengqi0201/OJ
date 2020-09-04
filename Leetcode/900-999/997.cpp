/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Constraints:

1 <= N <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N



*/

/*
统计每个顶点的初度和入度

*/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int *indegree = new int[N+1];
        int *outdegree = new int[N+1];
        memset(indegree, 0, (N+1)*sizeof(int));
        memset(outdegree, 0, (N+1)*sizeof(int));
        
        for (int i = 0; i < trust.size(); i++){
            int v1 = trust[i][0];
            int v2 = trust[i][1];
            outdegree[v1]++;
            indegree[v2]++;
        }
        int cnt = 0 , vertex = 0;
        for (int i = 1;i <=N; i++){
            if (indegree[i] == N-1 && outdegree[i] == 0){
                cnt++;
                vertex = i;
            }
        }
        //只有一个点满足性质
        if (cnt == 1)   return vertex;
        return -1;
        
    }
};