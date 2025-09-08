class Solution {
public:
    bool noZero(int n) {
        while (n > 0) {
            int rem = n % 10;

            if (rem == 0) return false;
            n /= 10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int num1;
        int num2;
        for (int i = 1; i < n; i++) {
            if (noZero(i) && noZero(n - i)) {
                num1 = i;
                num2 = n - i;
                break;
            }
        }

        return {num1, num2};
    }
};
