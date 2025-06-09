class Solution {
public:
    int Find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        return parent[i] = Find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int xp = Find(x, parent);
        int yp = Find(y, parent);

        if(xp == yp){
            return;
        }

        if(rank[xp] == rank[yp]){
            parent[xp] = yp;
            rank[yp]++;
        } else if(rank[xp] < rank[yp]){
            parent[xp] = yp;
        } else{
            parent[yp] = xp;
        }
    }

    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i=0; i<n; i++) parent[i] = i;

        int numComponents = n;
        for(auto vec : connections){
            int x = vec[0];
            int y = vec[1];

            if(Find(x, parent) != Find(y, parent)){
                Union(x, y, parent, rank);
                numComponents--;
            }
        }

        return numComponents-1;
    }
};
