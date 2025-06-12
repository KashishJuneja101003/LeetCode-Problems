// Approach 1: Recursion TC: O(2^n) SC: O(n)
/*
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
*/

// Approach 2: Top Down (Recursion + Memoization) TC: O(n) SC: O(n)
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
