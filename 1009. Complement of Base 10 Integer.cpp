class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int mult = 1;
        int ans = 0;

        while (n) {
            int rem = n % 2;

            // 0 -> 1, 1 -> 0
            rem ^= 1;

            n /= 2;
            ans += rem * mult;
            mult *= 2;
        }

        return ans;
    }
};
