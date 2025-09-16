class Solution {
public:
    bool canComplete(vector<int>& time, int totalTrips, long long maxTime) {
        long long trips = 0;

        for (int& i : time) {
            trips += maxTime / i;
            if (trips >= totalTrips)
                return true;
        }

        return trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right =
            1LL * (*max_element(time.begin(), time.end())) * totalTrips;

        long long minTime = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canComplete(time, totalTrips, mid)) {
                minTime = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minTime;
    }
};
