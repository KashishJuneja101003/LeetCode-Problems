class Solution {
public:
    int findRotations(vector<int>& tops, vector<int>& bottoms, int val){
        int topSwap = 0, bottomSwap = 0;

        for(int i=0; i<tops.size(); i++){
            if(tops[i] != val && bottoms[i] != val){
                return -1;
            } else if (tops[i] != val){
                topSwap++;
            } else if (bottoms[i] != val){
                bottomSwap++;
            }
        }

        return min(topSwap, bottomSwap);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minRotations = INT_MAX;
        for(int val=1; val<=6; val++){
            int steps = findRotations(tops, bottoms, val);
            if(steps != -1){
                minRotations = min(minRotations, steps);
            }
        }

        return (minRotations == INT_MAX) ? -1 : minRotations;
    }
};
