// TC: O(n) SC: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr = 0;
        int maxLen = 0;

        for(int i=0; i<nums.size()-2; i++){
            if(nums[i] + nums[i+1] == nums[i+2]) curr++;
            else curr = 0;
            
            maxLen = max(maxLen, curr+2);
        }

        return maxLen;
    }
};
