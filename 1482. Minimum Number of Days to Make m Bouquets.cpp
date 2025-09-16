class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouq = 0;
        int curr = 0;

        for (int i : bloomDay) {
            if (i <= day) {
                curr++;
                if (curr == k) {
                    bouq++;
                    curr = 0;
                }
            } else {
                curr = 0;
            }
        }

        return bouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
