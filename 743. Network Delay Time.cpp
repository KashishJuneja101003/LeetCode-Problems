// TC: O(VE log V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Creating adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& vec:times){
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];

            adj[u].push_back({v, t});
        }

        // Priority Queue to store min time and corresponding node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // time vector to store the min time required to reach ith node
        vector<int> time(n+1, INT_MAX);
        time[0] = 0;

        // Initial State
        pq.push({0, k});
        time[k] = 0;

        // Traverse the graph and get time to reach each node
        while(!pq.empty()){
            int minTime = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for(auto& p:adj[curr]){
                int neighbour = p.first;
                int currTime = p.second;
                int newTime = minTime + currTime;

                if(newTime < time[neighbour]){
                    time[neighbour] = newTime;
                    pq.push({newTime, neighbour});
                }
            }
        }

        // Compute max time to reach each node
        // If INT_MAX is found, that means a node is unreachable
        // Thus, return -1
        int timeReq = 0;
        for(int& t : time){
            if(t == INT_MAX) return -1;
            timeReq = max(timeReq, t);
        }

        return timeReq;
    }
};
