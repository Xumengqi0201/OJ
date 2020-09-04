class Solution {
public:
   vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> graph[n],degree(n,0);
        for(auto x:edges)
        {
            graph[x[1]].push_back(x[0]);
            graph[x[0]].push_back(x[1]);
            degree[x[0]]++;
            degree[x[1]]++;                        //Updating the degrees of each nodes
        }
        int nodecount=n;
        queue<int> q;
        while(nodecount>2)
        {
            for(int i=0;i<n;i++)
            {
                if(degree[i]==1)
                {
                    q.push(i);
                    degree[i]=-1;                        //We decrement each time we visit a node with degree = 1
                }
            }
            nodecount -= q.size();
            while(!q.empty())
            {
                int t=q.front();
                q.pop();
                for(int x:graph[t])
                    degree[x]--;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0||degree[i]==1)ans.push_back(i);     //If we are left with a node with degrees =0 or 1 that with contibute to an MHT
        }
        return ans;
    }
};