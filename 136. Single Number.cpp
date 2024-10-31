class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // n^n = 0 and n^0 = n
        for(int i:nums) result ^= i;
        return result;
    }
};
