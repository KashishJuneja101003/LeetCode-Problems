class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // If there are no edges, return -1
        if(m == 0) return {-1};
        
        // Creating adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& vec:edges){
            int n1 = vec[0];
            int n2 = vec[1];
            int wt = vec[2];
            
            adj[n1].push_back({n2, wt});
            adj[n2].push_back({n1, wt});
        }
        
        // Creating Priority Queue to get the min distance found
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        
        // Parent vector will store parent of each node
        vector<int> parent(n+1, 0);
        
        // Initially, parent of each node is the node itself
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
        
        // Distance vector will store the min distance to reach ith node
        vector<int> distance(n+1, INT_MAX);
        distance[1] = 0;
        
        while(!pq.empty()){
            int minDist = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            
            for(auto& p:adj[curr]){
                int neighbour = p.first;
                int dist = p.second;
                int newDist = minDist + dist;
                
                if(newDist < distance[neighbour]){
                    distance[neighbour] = newDist;
                    pq.push({newDist, neighbour});
                    parent[neighbour] = curr;
                }
            }
        }
        
        int destination = n;
        int totalWeight = distance[destination];
        
        // If destination is unreachable, return -1
        if(distance[destination] == INT_MAX) return {-1};
        
        // Path vector will store the path to reach destination
        vector<int>path;
        
        while(parent[destination] != destination){
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(1);
        
        reverse(path.begin(), path.end());
        
        // Add total weight to the front
        path.insert(path.begin(), totalWeight);
        
        return path;
    }
};
