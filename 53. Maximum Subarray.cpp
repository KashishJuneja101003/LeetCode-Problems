// Approach 1: Brute Force TC: O(n^2) SC: O(1)
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int currSum = 0;
            for(int j=i; j<n; j++){
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};
*/

// Approach 2: Kadane's Algorithm TC: O(n) SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;

        for(int i:nums){
            sum += i;
            maxSum = max(sum, maxSum);
            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};
