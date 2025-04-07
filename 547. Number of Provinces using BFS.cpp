class Solution {
public:
    int V;
    void BFS(vector<vector<int>>& adj, int u, vector<bool> &visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int v=0; v<V; v++){
                if(!visited[v] && adj[u][v] == 1){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        V = adj.size();

        int countProvinces = 0;
        vector<bool> visited(V, false);
       
        for(int i=0; i<V; i++){
            if(!visited[i]){
                BFS(adj, i, visited);
                countProvinces++;
            }
        }
        return countProvinces;
    }
};
