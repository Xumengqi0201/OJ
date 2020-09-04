class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	int *indegree = new int[numCourses];
    	memset(indegree, 0, numCourses*sizeof(int));
    	vector <vector<int>> graph(numCourses, vector<int>());
    	for (int i = 0; i < prerequisites.size(); i++){
    		int v1 = prerequisites[i][0];
    		int v2 = prerequisites[i][1];
    		graph[v2].push_back(v1);
    		indegree[v1]++;
    	}
    	queue <int> q;
    	for (int i = 0; i < numCourses; i++){
    		if (indegree[i] == 0){
    			q.push(i);
    		}
    	}
    	
    	while(!q.empty()){
    		int v = q.front(); q.pop();
    		for (int w : graph[v]){
    			indegree[w]--;
    			if (indegree[w] == 0){
    				q.push(w);
    			}
    		}
    	}
    	for (int i = 0; i < numCourses; i++){
    		if (indegree[i] != 0)	return false;
    	}
    	return true;


        
    }
};