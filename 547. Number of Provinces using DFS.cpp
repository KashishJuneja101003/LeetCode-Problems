class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for (int v=0; v<adj.size(); v++) {
            if (!visited[v] && adj[u][v] == 1) {
                visited[v] = true;
                DFS(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<bool> visited(V, false);

        int numProvinces = 0;
        for (int i = 0; i < V; i++) {
            // If a node is found that is unvisited, increment numProvinces and
            // call DFS
            if (!visited[i]) {
                numProvinces++;
                DFS(adj, i, visited);
            }
        }

        return numProvinces;
    }
};
