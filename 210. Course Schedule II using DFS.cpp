class Solution {
public:
    void topoDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, stack<int>& stk, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(int& v : adj[u]){
            if(!visited[v]){
                topoDFS(adj, v, visited, stk, inRecursion);
            } else if (inRecursion[v] == true){
                return;
            }
        }
        
        inRecursion[u] = false;
        stk.push(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        stack<int> stk;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                topoDFS(adj, i, visited, stk, inRecursion);
            }
        }

        // If cant finish courses, return {}
        if(stk.size() != numCourses) return {};

        vector<int> orderDFS;
        while(!stk.empty()){
            orderDFS.push_back(stk.top());
            stk.pop();
        }

        return orderDFS;
    }
};
