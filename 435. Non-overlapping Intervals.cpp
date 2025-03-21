class Solution {
public:
    bool static comparator(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);

        int currentMaxEndTime = intervals[0][1];
        int n = intervals.size();
        int overlappingIntervals = 0;

        for(int i=1; i<n; i++){
            if(intervals[i][0] >= currentMaxEndTime){
                currentMaxEndTime = intervals[i][1];
            } else {
                overlappingIntervals++;
            }
        }
        return overlappingIntervals;
    }
};
