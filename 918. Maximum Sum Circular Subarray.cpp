// Brute-Force TC: O(n^2) SC: O(1)
- Rotate array n times
- Find subarray sum of each
- Return maxSum

// TC: O(n) SC: O(1)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMinSum = nums[0];
        int minSum = nums[0];

        int currMaxSum = nums[0];
        int maxSum = nums[0];

        int totalSum = nums[0];

        int n = nums.size();

        for (int i = 1; i < n; i++) {
            currMinSum = min(nums[i], currMinSum + nums[i]);
            minSum = min(minSum, currMinSum);

            currMaxSum = max(nums[i], currMaxSum + nums[i]);
            maxSum = max(maxSum, currMaxSum);
            
            totalSum += nums[i];
        }

        int circularMax = totalSum - minSum;

        if (maxSum > 0)
            return max(maxSum, circularMax);
        
        return maxSum;
    }
};
