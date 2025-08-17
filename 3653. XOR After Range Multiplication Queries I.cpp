class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& vec : queries) {
            int li = vec[0];
            int ri = vec[1];
            int ki = vec[2];
            int vi = vec[3];

            for (int idx = li; idx <= ri; idx += ki) {
                long long a = (1LL * nums[idx] * vi) % 1000000007;
                nums[idx] = a;
            }
        }

        int _xor = 0;

        for (int& i : nums)
            _xor ^= i;

        return _xor;
    }
};
