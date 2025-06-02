class Solution {
public:
    vector<int> orderBFS(unordered_map<int, vector<int>>& adj, int numCourses, vector<int>& inDegree){
        // que stores nodes with 0 indegree (courses with no prerequisites) 
        queue<int> que;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        // countNodes contain the number of nodes pushed into the queue
        // courseOrder stores the order of courses
        // If all the nodes are pushed once, that means, all courses can be finished
        int countNodes = 0;
        vector<int> courseOrder;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            countNodes++;
            courseOrder.push_back(u);

            for(int& v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }

        if(countNodes == numCourses){
            return courseOrder;
        } else{
            return {};
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        return orderBFS(adj, numCourses, inDegree);        
    }
};
