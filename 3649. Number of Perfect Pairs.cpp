class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = nums[i];
                int b = nums[j];

                long long diff = abs(a - b);
                long long sum = abs(a + b);

                int abs_a = abs(a);
                int abs_b = abs(b);

                if ((min(diff, sum) <= min(abs_a, abs_b)) &&
                    (max(diff, sum) >= max(abs_a, abs_b))) {
                    count++;
                }
            }
        }
        return count;
    }
};
