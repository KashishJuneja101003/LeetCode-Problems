// TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            int digit = sum % 10;

            digits[i] = digit;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
