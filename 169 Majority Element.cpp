class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // An element appearing more than (n/2) times, will always be in the middle
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
