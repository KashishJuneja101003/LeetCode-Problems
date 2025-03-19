class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        
        vector<vector<int>> mergedIntervals;
        
        int lowerBound = arr[0][0];
        int upperBound = arr[0][1];

        for(int i=1; i<n; i++){
            int start = arr[i][0];
            int end = arr[i][1];

            if(start <= upperBound){
                upperBound = max(upperBound, end);
            } else{
                mergedIntervals.push_back({lowerBound, upperBound});
                lowerBound = start; upperBound = end;
            }
        }
        mergedIntervals.push_back({lowerBound, upperBound});

        return mergedIntervals;
    }
};
