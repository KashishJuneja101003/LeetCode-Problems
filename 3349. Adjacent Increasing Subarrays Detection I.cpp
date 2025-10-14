// TC: O(n) SC: O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int l1 = 1;
        int l2 = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                l1++;
            } else {
                l2 = l1;
                l1 = 1;
            }

            // l1/2 - a single array that is capable to be split up into 2 of length k
            // min(l1, l2) >= k - 2 adjacent arrays, min of both the sizes is k, that means both are >= k size
            if (l1 / 2 >= k || min(l1, l2) >= k){
                return true;
            }
        }

        return false;
    }
};
