class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq;
        sq.reserve(n);
        
        for (int x : nums) {
            sq.push_back(1LL * x * x);
        }

        sort(sq.begin(), sq.end());
        
        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += sq[n - 1 - i] - sq[i];
        }

        if (n % 2 == 1) {
            sum += sq[n / 2];
        }

        return sum;
    }
};
