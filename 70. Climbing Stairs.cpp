// Approach 1: Brute Force O(2^n) (TLE)
class Solution {
public:
    int count(int n, int curr){
        // Base Case
        if(curr > n) return 0;
        if(curr == n) return 1;

        int one = count(n, curr+1);
        int two = count(n, curr+2);

        return one + two;
    }
    int climbStairs(int n) {
        if(n == 1) return 1;
        return count(n, 0);
    }
};

// Approach 2: Top-Down Memoization, SC: O(n) TC: O(n)
class Solution {
public:
    int climb(int n, int cS, vector<int>& dp){
        if(cS > n) return 0;
        if(cS == n) return 1;
        if(dp[cS] != 0) return dp[cS];

        dp[cS] = climb(n, cS+1, dp) + climb(n, cS+2, dp);
        return dp[cS];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return climb(n, 0, dp);
    }
};

// Approach 3: Bottom-Up, TC: O(n) SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> dp(n+1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            int one = dp[i-1];
            int two = dp[i-2];

            dp[i] = one + two;
        }

        return dp[n];
    }
};

// Approach 4: Space-Optimised TC: O(n) SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;

        int last = 1;
        int secondLast = 1;

        for(int i=2; i<=n; i++){
            int curr = last + secondLast;
            secondLast = last;
            last = curr;
        }

        return last;
    }
};
