class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN || x >= INT_MAX) return 0;

        long num = abs(x);
        long result = 0;
        while(num > 0){
            int rem = num%10;
            num /= 10;
            result = (result)*10 + rem;
        }

        if (result <= INT_MIN || result >= INT_MAX) return 0;

        return (x < 0) ? -1*result : result;
    }
};
