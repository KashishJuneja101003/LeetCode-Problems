class Solution {
public:
    bool predecessor(string& a, string& b) {
        int n1 = a.size();
        int n2 = b.size();

        if (n1 > n2 || n2 - n1 != 1)
            return false;

        int i = 0;
        int j = 0;
        bool skipped = false;

        while (i < n1 && j < n2) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                if (skipped)
                    return false;
                skipped = true;
                j++;
            }
        }

        return true;
    }

    static bool comparator(string& a, string& b) { return a.size() < b.size(); }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comparator);
        vector<int> dp(n, 1);

        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (predecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
