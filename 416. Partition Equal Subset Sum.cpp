// Approach 1: Recursion TC: O(2^n) SC: O(n)
class Solution {
public:
    bool subset(vector<int>& nums, int n, int target){
        // If reached at the end, means target not found, return false
        if(n == 0) return false;

        if(target == 0) return true;

        // Exclude
        bool exclude = subset(nums, n-1, target);

        // Include
        bool include = false;
        if(nums[n-1] <= target) include = subset(nums, n-1, target - nums[n-1]);

        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        // Calculate Sum
        int sum = 0;
        for(int& i:nums) sum += i;

        // If sum is odd, nums can't be divided into equal partitions
        if(sum%2 != 0) return false;

        return subset(nums, n, sum/2);
    }
};

// Approach 2: Memoized TC: O(n*target) SC: O(n*target)
class Solution {
public:
    bool subset(vector<int>& nums, int n, int target, vector<vector<int>>& dp){
        // If reached at end, means target not found, return false
        if(n == 0) return false;

        if(target == 0) return true;

        if(dp[n][target] != -1) return dp[n][target];

        // Exclude
        bool exclude = subset(nums, n-1, target, dp);

        // Include
        bool include = false;
        if(nums[n-1] <= target) include = subset(nums, n-1, target - nums[n-1], dp);

        return dp[n][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        // Calculate Sum
        int sum = 0;
        for(int& i:nums) sum += i;

        // If sum is odd, nums can't be divided into equal partitions
        if(sum%2 != 0) return false;

        int target = sum/2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        return subset(nums, n, sum/2, dp);
    }
};
