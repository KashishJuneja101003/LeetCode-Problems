class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), comparator);
        int end = points[0][1];

        int intervals = 1;

        for (auto& vec : points) {
            int currSt = vec[0];
            int currEnd = vec[1];

            if (currSt > end) {
                intervals++;
                end = currEnd;
            }
        }

        return intervals;
    }
};
