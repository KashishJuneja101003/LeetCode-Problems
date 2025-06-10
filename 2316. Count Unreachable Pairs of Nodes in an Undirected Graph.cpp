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

        if(rank[xp] == rank[yp]){
            parent[yp] = xp;
            rank[xp]++;
        } else if (rank[xp] < rank[yp]){
            parent[xp] = yp;
        } else{
            parent[yp] = xp;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i=0; i<n; i++) parent[i] = i;

        for(auto& vec : edges){
            int x = vec[0];
            int y = vec[1];

            Union(x, y, parent, rank);
        }


        unordered_map<int, int> parent_numNodes;
        for(int i=0; i<n; i++){
            parent_numNodes[Find(i, parent)]++;
        }

        long long remainingSize = n;
        long long result = 0;

        for(auto& it : parent_numNodes){
            long long size = it.second;

            result += (size * (remainingSize - size));
            remainingSize -= size;
        }
        return result;
    }
};
