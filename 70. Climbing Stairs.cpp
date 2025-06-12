// Approach 1: Brute Force O(2^n) (TLE)
/*
class Solution {
public:
    void climb(int n, int currStep, int& totalSteps){
        if(n == currStep){
            totalSteps++;
            return;
        }

        if(currStep > n){
            return;
        }

        climb(n, currStep+1, totalSteps);
        climb(n, currStep+2, totalSteps);
    }
    int climbStairs(int n) {
        int totalSteps = 0;
        climb(n, 0, totalSteps);
        return totalSteps;
    }
};
*/

// Approach 2: Top-Down Memoization, SC: O(n) TC: O(n)
/*
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
*/

// Approach 3: Bottom-Up, TC: O(n) SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int secondLast = 1;
        int last = 1;
        for(int i=2; i<=n; i++){
            int curr = last + secondLast;
            secondLast = last;
            last = curr;
        }
        return last;
    }
};
