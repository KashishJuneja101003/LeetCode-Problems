// TC: O(n) SC: O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = pow(n, 2);
        int sumEven = n * (n + 1);

        while(sumOdd != 0){
            int temp = sumOdd;
            sumOdd = sumEven % sumOdd;
            sumEven = temp;
        }

        return sumEven;
    }
};

// TC: O(1) SC: O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
