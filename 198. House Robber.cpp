// Approach 1: Recursion TC: O(2^n) SC: O(n)
class Solution {
public:
    int solve(vector<int>& arr, int idx, int n){
        if(idx >= n){
            return 0;
        }
        int steal = arr[idx] + solve(arr, idx+2, n);
        int skip = solve(arr, idx+1, n);
        return max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
};

// Approach 2: Top Down (Recursion + Memoization) TC: O(n) SC: O(n) + Recursive stack
class Solution {
public:
    int solve(vector<int>& arr, int idx, int n, vector<int>& dp){
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int steal = arr[idx] + solve(arr, idx+2, n, dp);
        int skip = solve(arr, idx+1, n, dp);
        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, n, dp);
    }
};


// Approach 3: Bottom Up TC: O(n) SC: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            int rob = dp[i-2] + nums[i];
            int notRob = dp[i-1];

            dp[i] = max(rob, notRob);
        }

        return dp[n-1];
    }
};

// Space Optimized TC: O(n) SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int secondLast = nums[0];
        int last = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            int rob = secondLast + nums[i];
            int notRob = last;

            int curr = max(rob, notRob);
            secondLast = last;
            last = curr;
        }

        return last;
    }
};
