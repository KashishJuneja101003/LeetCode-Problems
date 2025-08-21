// Approach 1: Recursion TC: (n 2^n) SC: O(n)
class Solution {
public:
    void solve(vector<int>& arr, vector<int>& temp, int idx, long long& maxSum){
        if(idx == arr.size()){
            long long oddSum = 0;
            long long evenSum = 0;

            for(int i=0; i<temp.size(); i++){
                if(i%2 == 0) evenSum += temp[i];
                else oddSum += temp[i];
            }
            maxSum = max(maxSum, (evenSum - oddSum));
            return;
        }

        temp.push_back(arr[idx]);
        solve(arr, temp, idx+1, maxSum);

        // BT step
        temp.pop_back();
        solve(arr, temp, idx+1, maxSum);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> temp;
        long long maxSum = 0;

        solve(nums, temp, 0, maxSum);
        return maxSum;
    }
};

// Approach 2: Recursive + Memoization TC: O(2n) = O(n)  SC: O(n)
class Solution {
public:
    long long solve(vector<int>& arr, int idx, int isEven, vector<vector<long long>>& dp){
        if(idx == arr.size()){
            return 0;
        }

        if(dp[idx][isEven] != -1) return dp[idx][isEven];

        long long keep = (isEven ? arr[idx] : -arr[idx]) + solve(arr, idx+1, 1-isEven, dp);

        long long skip = solve(arr, idx+1, isEven, dp);
        
        return dp[idx][isEven] = max(keep, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return solve(nums, 0, 1, dp);
    }
};

// Tabulation TC: O(n) SC: O(n)
class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 1;
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][even] = max(dp[i - 1][odd] - nums[i - 1], dp[i - 1][even]);
            dp[i][odd] = max(dp[i - 1][even] + nums[i - 1], dp[i - 1][odd]);
        }

        return max(dp[n][odd], dp[n][even]);
    }
};
