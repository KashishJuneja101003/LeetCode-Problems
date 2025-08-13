// TC: O(log_3 (n)) SC: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0){
            n /= 3;
        }

        return n == 1;
    }
};
