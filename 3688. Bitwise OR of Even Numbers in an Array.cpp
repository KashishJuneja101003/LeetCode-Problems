// TC: O(n) SC: O(1)
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        for(int& i:nums){
            if((i&1) == 0) ans = ans | i;
        }

        return ans;
    }
};
