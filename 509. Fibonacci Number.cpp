// Recursion TC : O(2^n)
class Solution {
public:
    int calcFib(int n){
        if(n == 0 || n == 1) return n;
        return calcFib(n-1) + calcFib(n-2);
    }

    int fib(int n) {
        return calcFib(n);
    }
};

// Memoization TC: O(n) SC: O(n) + O(n)
class Solution {
public:
    int calcFib(int n, vector<int>& dp){
        if(n == 0 || n == 1) return n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = calcFib(n-1, dp) + calcFib(n-2, dp);
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);
        return calcFib(n, dp);
    }
};

// Bottom-Up TC: O(n) SC: O(n)
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
};

// Bottom-Up TC: O(n) SC: O(1)
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;

        int a = 0, b=1;
        for(int i=2; i<=n; i++){
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};
