
// Moore's Algorithm TC: O(n) SC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int cand = nums[0];

        for(int i:nums){
            if(freq == 0) cand = i;
            if(cand == i) freq++;
            else freq--;
        }

        return cand;
    }
};
