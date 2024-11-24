class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true; //2^0 = 1
        if(n%2 != 0) return false;  // Odd number can't be power of 2
        long int x = 2;
        while(x < n){
            x *= 2;
        }
        return (x == n) ? true:false;
    }
};
