// Recursion TC: (2^amount) SC: O(amount)
class Solution {
public:
    int getAmt(vector<int>& coins, int amount, int idx, int n, int currAmt, int numCoins) {
        // Base Case
        if (currAmt > amount) return -1;
        if (currAmt == amount) return numCoins;
        if (idx >= n) return -1;

        int exclude = getAmt(coins, amount, idx + 1, n, currAmt, numCoins);
        int include = getAmt(coins, amount, idx, n, currAmt + coins[idx], numCoins + 1);

        if (include == -1) return exclude;
        if (exclude == -1) return include;

        return min(include, exclude);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        return getAmt(coins, amount, 0, coins.size(), 0, 0);
    }
};
