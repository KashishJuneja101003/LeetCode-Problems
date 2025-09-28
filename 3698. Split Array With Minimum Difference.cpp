class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1; // can't split

        vector<bool> prefixInc(n, true), suffixDec(n, true);
        vector<long long> prefixSum(n);

        // Prefix strictly increasing check
        for (int i = 1; i < n; i++)
            prefixInc[i] = prefixInc[i-1] && (nums[i-1] < nums[i]);

        // Suffix strictly decreasing check
        for (int i = n-2; i >= 0; i--)
            suffixDec[i] = suffixDec[i+1] && (nums[i] > nums[i+1]);

        // Prefix sums
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];

        long long ans = LLONG_MAX;
        bool found = false;

        for (int i = 0; i < n-1; i++) {
            if (prefixInc[i] && suffixDec[i+1]) {
                found = true;
                long long leftSum = prefixSum[i];
                long long rightSum = prefixSum[n-1] - prefixSum[i];
                ans = min(ans, llabs(leftSum - rightSum));
            }
        }

        return found ? ans : -1;
    }
};
