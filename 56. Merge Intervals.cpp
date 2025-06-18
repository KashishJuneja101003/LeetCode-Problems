class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> nonOverlappingIntervals;

        int lowerBound = intervals[0][0];
        int upperBound = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If the interval lies in current range, update lowerBound and upperBound
            if(start <= upperBound){
                upperBound = max(upperBound, end);
            } else {
                nonOverlappingIntervals.push_back({lowerBound, upperBound});
                lowerBound = start; upperBound = end;
            }
        }
        
        nonOverlappingIntervals.push_back({lowerBound, upperBound});

        return nonOverlappingIntervals;
    }
};
