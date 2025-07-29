// Memoization TC: O(n) SC: O(n)
class Solution {
public:
    int check(vector<int>& nums, int idx, int n, vector<int>& dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + check(nums, idx+2, n, dp);
        int notPick = check(nums, idx+1, n, dp);

        
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, -1);
        vector<int> dp1(n, -1);
        int a = check(nums, 0, n-1, dp);
        int b = check(nums, 1, n, dp1);
        return max(a, b);
    }
};

// Tabulation TC: O(n) SC: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            int pick = dp[i - 2] + nums[i];
            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick); 
        }

        vector<int> dp1(n, -1);
        dp1[1] = nums[1];

        if (n > 2)
            dp1[2] = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {
            int pick = dp1[i - 2] + nums[i];
            int notPick = dp1[i - 1];

            dp1[i] = max(pick, notPick);
        }

        return max(dp[n - 2], dp1[n - 1]);
    }
};

// Space-Optimised TC: O(n) SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int a1 = nums[0];
        int a2 = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            int pick = a1 + nums[i];
            int notPick = a2;

            int curr = max(pick, notPick); 
            a1 = a2;
            a2 = curr;
        }

        int b1 = nums[1];
        int b2 = 0;
        if (n > 2)
            b2 = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {
            int pick = b1 + nums[i];
            int notPick = b2;

            int curr = max(pick, notPick);
            b1 = b2;
            b2 = curr;
        }

        return max(a2, b2);
    }
};

// Clean Approach TC: O(n) SC: O(1)
class Solution {
public:
    int robCheck(vector<int>& nums, int start, int end) {
        int secondLast = 0;
        int last = 0;

        for (int i = start; i <= end; i++) {
            int pick = secondLast + nums[i];
            int notPick = last;

            int curr = max(pick, notPick);
            secondLast = last;
            last = curr;
        }

        return last;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int range1 = robCheck(nums, 0, n - 2);
        int range2 = robCheck(nums, 1, n - 1);

        return max(range1, range2);
    }
};
