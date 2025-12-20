// TC: O(n * m) SC: O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].size();
        int del = 0;

        for(int j=0; j<len; j++){
            for(int i=0; i<n-1; i++){
                if(strs[i][j] > strs[i+1][j]){
                    del++;
                    break;
                }
            }
        }

        return del;
    }
};
