// Recursion TC: O(2^n) SC: O(n)
class Solution {
public:
    int getSubSeq(vector<int>& nums, int idx, int curr) {
        if (idx >= nums.size()) {
            return 0;
        }

        int skip = getSubSeq(nums, idx + 1, curr);

        int take = 0;
        if (nums[idx] > curr)
            take = 1 + getSubSeq(nums, idx + 1, nums[idx]);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) { 
        return getSubSeq(nums, 0, INT_MIN); 
    }
};

// Memoization TC: O(n^2) SC: O(n^2)
class Solution {
public:
    int getSubSeq(vector<int>& nums, int idx, int prev,
                  vector<vector<int>>& dp) {
        if (idx >= nums.size())
            return 0;

        if (prev != -1 && dp[idx][prev] != -1)
            return dp[idx][prev];

        int skip = getSubSeq(nums, idx + 1, prev, dp);

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev])
            take = 1 + getSubSeq(nums, idx + 1, idx, dp);

        if (prev != -1)
            dp[idx][prev] = max(take, skip);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return getSubSeq(nums, 0, -1, dp);
    }
};

// Tabulation TC: O(n^2) SC: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLIS = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};
