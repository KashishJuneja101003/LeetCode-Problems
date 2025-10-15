// TC: O(n) SC: O(1)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int l1 = 1;
        int l2 = 1;
        int k = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] < nums[i]) {
                l1++;
            } else{
                l2 = l1;
                l1 = 1;
            }

            k = max(k, max(l1/2, min(l1, l2)));
        }

        return k;
    }
};
