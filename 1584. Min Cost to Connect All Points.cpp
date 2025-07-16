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
