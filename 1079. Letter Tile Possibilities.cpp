class Solution {
    set<string> distinctCombinations;
    unordered_map<int, int> flag;
    string S;
public:
    void solve(string tiles){
        for(int i=0; i<tiles.size(); i++){
            if(flag[i] != 1){
                flag[i] = 1;
                S.push_back(tiles[i]);
                distinctCombinations.insert(S);

                // Recursive Call
                solve(tiles);

                // Backtracking
                flag[i] = 0;
                S.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        solve(tiles);

        return distinctCombinations.size();
    }
};
