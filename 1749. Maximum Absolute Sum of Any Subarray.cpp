// TC: O(n) SC: O(1) - 2 loops
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        currSum = nums[0];
        for (int i = 1; i < n; i++) {
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }

        return max(maxSum, abs(minSum));
    }
};

// TC: O(n) SC: O(1) - 1 loop
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            currMinSum = min(nums[i], currMinSum + nums[i]);
            currMaxSum = max(nums[i], currMaxSum + nums[i]);
            minSum = min(minSum, currMinSum);
            maxSum = max(maxSum, currMaxSum);
        }

        return max(maxSum, abs(minSum));
    }
};
