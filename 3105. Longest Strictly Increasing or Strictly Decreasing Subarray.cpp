class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        // Edge Case
        if(n == 1){
            return 1;
        }

        int inc = 1, dec = 1, maxCount = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                inc++; dec = 1;
            } else if(nums[i-1] > nums[i]){
                dec++; inc = 1;
            } else{
                inc = dec = 1;
            }

            maxCount = max(maxCount, max(inc, dec));
        }

        return maxCount;
    }
};
