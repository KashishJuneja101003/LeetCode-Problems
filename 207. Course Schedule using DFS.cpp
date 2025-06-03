class Solution {
public:
    bool canFinishDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for(int& v : adj[u]){
            if(!visited[v] && canFinishDFS(adj, v, visited, inRecursion)){
                return true;    // there is a cycle
            } else if (inRecursion[v] == true){
                return true;
            }
        }

        inRecursion[u] = false;

        return false;   // no cycle
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Makind adjacency list and
        unordered_map<int, vector<int>> adj;
        for (auto vec : prerequisites) {
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && canFinishDFS(adj, i, visited, inRecursion)) {
                return false; // Can't complete courses
            }
        }

        return true;
    }
};
