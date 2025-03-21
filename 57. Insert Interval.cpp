class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> updatedIntervals;

        for(int i=0; i<n; i++){
            // Non overlapping intervals before or after newInterval
            if(newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0]){
                updatedIntervals.push_back(intervals[i]);
            } else {
                // Merge Overlapping Interval
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        // Add the merged interval (newInterval)
        updatedIntervals.push_back(newInterval);

        // Sort the updatedIntervals to maintain the order
        sort(updatedIntervals.begin(), updatedIntervals.end());

        return updatedIntervals;
    }
};
