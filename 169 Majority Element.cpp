class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Algorithm
        int freq=0, result=0;
        for(int i=0; i<nums.size(); i++){
            if(freq == 0) result = nums[i];

            if(nums[i] == result) freq++;
            else freq--;
        }
        return result;
    }
};
