// TC: O(n) SC: O(1)
class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSub(string s) {
        long long ones = 0;
        long long result = 0;

        for (char c : s) {
            if (c == '1') {
                ones++;
            } else {
                result = (result + ones * (ones + 1) / 2) % MOD;
                ones = 0;
            }
        }

        result = (result + ones * (ones + 1) / 2) % MOD;

        return result;
    }
};
