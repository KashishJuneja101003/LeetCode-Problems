// Recursion TC: O(2^n)
class Solution {
public:
    int getCount(vector<int>& coins, int amount, int idx, int curr) {
        if (idx >= coins.size())
            return 0;
        if (curr > amount)
            return 0;
        if (curr == amount)
            return 1;

        int exclude = getCount(coins, amount, idx + 1, curr);
        int include = 0;
        if (coins[idx] <= amount)
            include = getCount(coins, amount, idx, curr + coins[idx]);

        return include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        return getCount(coins, amount, 0, 0);
    }
};

// Memoization TC: O(n*amount) SC: O(n*amount)
class Solution {
public:
    int getCount(vector<int>& coins, int idx, int rem, vector<vector<int>>& dp) {
        if (rem < 0)
            return 0;
        if (rem == 0)
            return 1;
        if (idx >= coins.size())
            return 0;
        
        if(dp[idx][rem] != -1) return dp[idx][rem];

        int exclude = getCount(coins, idx + 1, rem, dp);
        int include = getCount(coins, idx, rem - coins[idx], dp);

        return dp[idx][rem] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return getCount(coins, 0, amount, dp);
    }
};
