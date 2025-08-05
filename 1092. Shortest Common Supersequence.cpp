class Solution {
public:
    string getSeq(string s1, int n1, string s2, int n2, vector<vector<int>>& dp) {
        int i=n1;
        int j=n2;

        string seq = "";

        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                seq += s1[i-1];
                i--; j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                seq += s1[i-1];
                i--;
            } else{
                seq += s2[j-1];
                j--;
            }
        }

        while(i > 0){
            seq += s1[i-1];
            i--;
        }

        while(j > 0){
            seq += s2[j-1];
            j--;
        }

        reverse(seq.begin(), seq.end());
        
        return seq;
    }


    void LCS(string s1, int n1, string s2, int n2, vector<vector<int>>& dp) {
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int match = 0;
                int notMatch = 0;

                if (s1[i - 1] == s2[j - 1]) {
                    match = 1 + dp[i - 1][j - 1];
                } else {
                    int reduce1 = dp[i - 1][j];
                    int reduce2 = dp[i][j - 1];

                    notMatch = max(reduce1, reduce2);
                }

                dp[i][j] = max(match, notMatch);
            }
        }
    }

    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        LCS(s1, n1, s2, n2, dp);

        return getSeq(s1, n1, s2, n2, dp);
    }
};
