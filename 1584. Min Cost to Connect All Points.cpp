// Approach 1: Prim's Algorithm
class Solution {
public:
    typedef pair<int, int> P;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist}); 
                adj[j].push_back({i, dist}); 
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,0});

        vector<bool> visited(n, false);
        int sum = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(!visited[node]){
                visited[node] = true;
                sum += dist;

                for(auto& vec:adj[node]){
                    int nbrWt = vec.second;;
                    int nbr = vec.first;

                    if(!visited[nbr]){
                        pq.push({nbrWt, nbr});
                    }
                }
            }

        }

        return sum;
    }
};

// Approach 2: Kruskal's Algorithm
class Solution {
public:
    int Find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        return parent[i] = Find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int xp = Find(x, parent);
        int yp = Find(y, parent);

        if(xp == yp) return;

        if(rank[xp] < rank[yp]) parent[xp] = yp;
        else if(rank[yp] < rank[xp]) parent[yp] = xp;
        else{
            parent[xp] = yp;
            rank[yp]++;
        }
    }

    int Kruskal(vector<vector<int>>& adj, vector<int>& parent, vector<int>& rank){
        int sum = 0;
        for(auto& vec:adj){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            if(Find(u, parent) == Find(v, parent)) continue;

            Union(u, v, parent, rank);
            sum += wt; 
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for(int i=0; i<V; i++) parent[i] = i;

        vector<vector<int>> adj;

        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({i, j, dist});
            }
        }

        auto comparator = [&](auto& v1, auto& v2){
            return v1[2] < v2[2];
        };

        sort(adj.begin(), adj.end(), comparator);

        return Kruskal(adj, parent, rank);
    }
};
