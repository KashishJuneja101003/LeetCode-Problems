// Approach: Binary Exponentiation
// Calculate 2^5:
// Step 1: Convert 5 into its binary form. exp = 101
// Step 2: Iterate over this exp from RHS. If the digit is 1, multiply with its exponent value in the result;
// Itr 1: exp = 1, x = 2, result *= x => 1*2 => 2, x *= x => 4
// Itr 2: exp = 0, x *= x => 16
// Itr 3: exp = 1, x = 16, result *= 16 => 2*16 => 32
// Thus, 2^5 = 32, which took **time complexity as O(log n + 1) => O(log n) and space complexity of O(1)** 
// log(5)+1 = 3 is the number of times loop worked

class Solution {
public:
    double myPow(double x, int n) {
        // Base Cases
        if (n == 0 || x == 1.0) return 1.0;
        if (x == 0) return 0.0;
        if (x == -1){
            if (n%2 == 0) return 1.0;
            else return -1.0;
        }

        long binary = n;
      
        // If the power is negative, the number gets inversed. Example, 3^(-2) = 1/3 * 1/3 = 1/9
        if (n < 0) {
            x = 1/x;
            binary *= -1;  // Since the loop works for positive "binary", its sign is changed to positive.
        }
      
        double result = 1;

        while(binary > 0){
            if(binary % 2 == 1) result *= x; // Multiply with x^n where the value is 1 in binary exponent form.
            x *= x;
            binary /= 2;
        }

        return result;
    }
};
