// Time Complexity: O((B-n) * log B) SC: O(1)
// B-n = number of numbers checked before finding the next balanced number.
// log B = number of digits per number.

class Solution {
public:
    bool isBalanced(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            freq[digit]++;
        }

        for (int i = 0; i < 10; i++) {
            if (freq[i] != 0 && freq[i] != i)
                return false;
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i < INT_MAX; i++) {
            if (isBalanced(i)) {
                return i;
            }
        }

        return -1;
    }
};
