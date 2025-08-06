// Recursion O(3^(m+n))
class Solution {
public:
    int getDistance(string word1, int i1, string word2, int i2){
        if(i2 < 0) return i1+1;
        if(i1 < 0) return i2+1;

        if(word1[i1] == word2[i2]){
            return getDistance(word1, i1-1, word2, i2-1);
        } else {
            int insert = 1 + getDistance(word1, i1, word2, i2 - 1);
            int del = 1 + getDistance(word1, i1-1, word2, i2);
            int replace = 1 + getDistance(word1, i1-1, word2, i2-1);

            return min({insert, del, replace});
        }
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        return getDistance(word1, n1-1, word2, n2-1);
    }
};

// Memoization TC: O(m × n) SC: O(m × n).
class Solution {
public:
    int getDistance(string word1, int i1, string word2, int i2, vector<vector<int>>& dp){
        if(i2 == 0) return i1;
        if(i1 == 0) return i2;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(word1[i1-1] == word2[i2-1]){
            return dp[i1][i2] = getDistance(word1, i1-1, word2, i2-1, dp);
        } else {
            int insert = 1 + getDistance(word1, i1, word2, i2 - 1, dp);
            int del = 1 + getDistance(word1, i1-1, word2, i2, dp);
            int replace = 1 + getDistance(word1, i1-1, word2, i2-1, dp);

            return dp[i1][i2] = min({insert, del, replace});
        }
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));


        return getDistance(word1, n1, word2, n2, dp);
    }
};
