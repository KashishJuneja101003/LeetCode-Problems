class Solution {
public:
    // Function to count ways to make all values up to maxVal using current denominations
    vector<int> getAllWays(int maxVal, const vector<int>& den) {
        vector<int> dp(maxVal + 1, 0);
        dp[0] = 1;

        for (int coin : den) {
            for (int i = coin; i <= maxVal; i++) {
                dp[i] += dp[i - coin];
            }
        }

        // Remove dp[0], since numWays[0] corresponds to amount 1
        dp.erase(dp.begin());
        return dp;
    }

    vector<int> findCoins(vector<int>& numWays) {
        vector<int> den;

        for (int i = 0; i < numWays.size(); i++) {
            int amount = i + 1;

            if (numWays[i] == 0) continue;

            int currentWays = countWays(amount, den);
            if (currentWays < numWays[i]) {
                den.push_back(amount);
            }
        }

        // Final verification step
        vector<int> allWays = getAllWays(numWays.size(), den);

        if (allWays != numWays) return {};

        return den;
    }

private:
    // Count ways to form specific value using current denominations
    int countWays(int val, const vector<int>& den) {
        vector<int> dp(val + 1, 0);
        dp[0] = 1;

        for (int coin : den) {
            for (int i = coin; i <= val; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[val];
    }
};
