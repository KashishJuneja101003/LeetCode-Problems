class Solution {
public:
    long long removeZeros(long long n) {
        long long result = 0, place = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                result += digit * place;
                place *= 10;
            }
            n /= 10;
        }
        return result;
    }
};
