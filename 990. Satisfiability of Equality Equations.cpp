class Solution {
public:
    int find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int xp = find(x, parent);
        int yp = find(y, parent);

        if(xp == yp) return;
        
        if(rank[xp] == rank[yp]){
            parent[xp] = yp;
            rank[yp]++;
        }else if(rank[xp] > rank[yp]){
            parent[yp] = xp;
        } else{
            parent[xp] = yp;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> rank(26, 0);

        // Initialising parent of every element
        vector<int> parent(26);
        for(int i = 0; i < 26; ++i) parent[i] = i;

        for(auto str : equations){
            if(str[1] == '='){
                int x = str[0]-'a';
                int y = str[3]-'a';

                Union(x, y, parent, rank);
            }
        }

        for(auto str : equations){
            if(str[1] == '!'){
                int x = str[0]-'a';
                int y = str[3]-'a';
                if(find(x, parent) == find(y, parent)) return false;
            }
        }
        return true;
    }
};
