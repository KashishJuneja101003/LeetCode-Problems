class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Initialize pointers at the start and end of the array
        int leftPtr = 0, rightPtr = nums.size()-1;

        // Loop until the pointers meet
        while(leftPtr < rightPtr){
            // Calculate the sum of elements at the pointers
            int sum = nums[leftPtr] + nums[rightPtr];

            // If sum matches the target, break the loop
            if(sum == target){
                break;
            } else if (sum < target){
                // If sum is less, move the left pointer to increase the sum
                leftPtr++;
            } else {
                // If sum is more, move the right pointer to decrease the sum
                rightPtr--;
            }
        }

        // Return the 1-indexed positions of the two numbers
        return {leftPtr + 1, rightPtr + 1};
    }
};
