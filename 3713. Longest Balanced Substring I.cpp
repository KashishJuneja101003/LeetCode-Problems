class Solution {
public:
    // Helper function to check if all non-zero frequencies are equal
    bool isBalanced(const vector<int>& freq) {
        int expected = 0;
        for (int count : freq) {
            if (count > 0) {
                if (expected == 0) expected = count;   // first non-zero frequency
                else if (count != expected) return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int x = 0; x < n; x++) {
            vector<int> freq(26, 0);  // reset for each starting point
            for (int y = x; y < n; y++) {
                freq[s[y] - 'a']++;    // update freq incrementally

                if (isBalanced(freq)) {
                    maxLen = max(maxLen, y - x + 1);
                }
            }
        }

        return maxLen;
    }
};
