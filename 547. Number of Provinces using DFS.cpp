class Solution {
public:
    int V;
    void DFS(vector<vector<int>>& adj, int u, vector<bool> &visited){
        visited[u] = true;

        for(int v = 0; v<V; v++){
            if(!visited[v] && adj[u][v] == 1){
                DFS(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        V = adj.size();

        int countProvinces = 0;
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                DFS(adj, i, visited);
                countProvinces++;
            }
        }
        return countProvinces;
    }
};
