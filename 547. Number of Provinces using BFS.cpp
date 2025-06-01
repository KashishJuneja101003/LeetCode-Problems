class Solution {
public:
    void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited){
        visited[u] = true;

        queue<int> que;
        que.push(u);

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(int &v : adj[node]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int V = isConnected.size();

        // Creating adjacency list
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i == j){
                    continue;
                }

                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, false);

        int numProvinces = 0;
        for(int i=0; i<V; i++){
            // If a node is found that is unvisited, increment numProvinces and call BFS 
            if(!visited[i]){
                numProvinces++;
                BFS(adj, i, visited);
            }
        }

        return numProvinces;
    }
};
