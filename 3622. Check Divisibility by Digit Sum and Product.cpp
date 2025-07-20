class Solution {
public:
    bool checkDivisibility(int n) {
        long long prod = 1;
        long long sum = 0;

        int num = n;

        while(num != 0){
            int digit = num%10;
            num /= 10;

            prod *= digit;
            sum += digit;
        }

        return (n%(prod+sum) == 0);
        
    }
};
