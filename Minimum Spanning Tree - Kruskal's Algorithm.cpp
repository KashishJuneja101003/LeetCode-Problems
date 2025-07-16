class Solution {
  public:
    typedef pair<int, pair<int, int>> P;

    int findParent(int node, vector<int> &parent) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node], parent); // Path compression
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // Min-Heap {wt, {u, v}}
        priority_queue<P, vector<P>, greater<P>> pq;
        for (auto& vec : edges) {
            pq.push({vec[2], {vec[0], vec[1]}});
        }

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; ++i) parent[i] = i;

        int sum = 0;

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int wt = curr.first;
            int u = curr.second.first;
            int v = curr.second.second;

            if (findParent(u, parent) != findParent(v, parent)) {
                sum += wt;
                unionSet(u, v, parent, rank);
            }
        }

        return sum;
    }
};
