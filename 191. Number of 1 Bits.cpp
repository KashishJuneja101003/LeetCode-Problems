// Approach 1: Convert to Binary (Recursion) TC: O(log n) SC: O(log n)
/*
class Solution {
public:
    int countOnes(int n){
        if(n == 1) return 1;

        int rem = n%2;
        if(rem == 1) return 1 + countOnes(n/2);
        else return countOnes(n/2);
    }

    int hammingWeight(int n) {
        return countOnes(n);
    }
};
*/

// Approach 2: Convert to Binary (Iterative) TC: O(log n) SC: O(1)
/*
class Solution {
public:
    int hammingWeight(int n) {
        int countOnes = 0;
        while(n >= 1){
            countOnes += (n%2 == 1) ? 1 : 0;
            n /= 2;
        }

        return countOnes;
    }
};
*/

// Approach 3: Bit Manipulation (Extract set bit) TC: O(set bits) SC: O(1)
// Brian Kernighan’s Algorithm
class Solution {
public:
    int hammingWeight(int n) {
        int countOnes = 0;
        while(n){
            n = n & (n-1);
            countOnes++;
        }

        return countOnes;
    }
};
