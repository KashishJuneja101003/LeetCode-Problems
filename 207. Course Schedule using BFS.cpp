class Solution {
public:
    bool canFinishBFS(unordered_map<int, vector<int>>& adj, int numCourses, vector<int>& inDegree){
        // que stores nodes with 0 indegree (courses with no prerequisites) 
        queue<int> que;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        // countNodes contain the number of nodes pushed into the queue
        // If all the nodes are pushed once, that means, all courses can be finished
        int countNodes = 0;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            countNodes++;

            for(int& v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }

        return countNodes == numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Makind adjacency list and
        // Populate indegree of each node (course)
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for(auto vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

       
        // function call
        return canFinishBFS(adj, numCourses, inDegree);        
    }
};
