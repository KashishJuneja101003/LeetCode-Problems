class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> leftClosest_R(n, -1);
        vector<int> rightClosest_L(n, -1);
        vector<char> finalState(n);

        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R') leftClosest_R[i] = i;
            if(i != 0 && dominoes[i] == '.') leftClosest_R[i] = leftClosest_R[i-1];
        }

        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L') rightClosest_L[i] = i;
            if(i != n-1 && dominoes[i] == '.') rightClosest_L[i] = rightClosest_L[i+1];
        }

        for(int i=0; i<n; i++){
            if(dominoes[i] != '.') {
                finalState[i] = dominoes[i]; // Keep original force
                continue;
            }

            int leftIdx = leftClosest_R[i];
            int rightIdx = rightClosest_L[i];

            int leftDist = (leftIdx == -1) ? INT_MAX : i - leftIdx;
            int rightDist = (rightIdx == -1) ? INT_MAX : rightIdx - i;

            if(leftDist == rightDist) finalState[i] = '.';
            else if(leftDist < rightDist) finalState[i] = 'R';
            else finalState[i] = 'L';
        }

        return string(finalState.begin(), finalState.end());
    }
};
