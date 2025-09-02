class Solution {
public:
    bool isValid(vector<int>& weights, int days, int& maxVal) {
        int numDays = 1;
        int curr = 0;

        for (int& i : weights) {
            if (i > maxVal)
                return false;

            if (curr + i <= maxVal) {
                curr += i;
            } else {
                numDays++;
                curr = i;
            }
        }

        return (numDays <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;

        for (int& i : weights)
            sum += i;

        int ans = -1;
        int left = 0;
        int right = sum;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isValid(weights, days, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
