// Approach 1: Linear Search TC: O(n) SC: O(1)
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int leftIdx = -1;
    int rightIdx = -1;

    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == target) {
            if(leftIdx == -1) leftIdx = i;  // first time we see the target
            rightIdx = i;                   // keep updating until the end of the target group
        }
        else if(leftIdx != -1) {
            // We've already found the full group of target values
            break;
        }
    }

    return {leftIdx, rightIdx};
  }
};
*/

// Approach 2: Binary Search TC: O(log n) SC: O(1)
class Solution {
public:
    int leftMost(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int leftIdx = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                leftIdx = mid;
                r = mid-1;
            } else if(nums[mid] < target){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }

        return leftIdx;
    }

    int rightMost(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int rightIdx = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                rightIdx = mid;
                l = mid+1;
            } else if(nums[mid] < target){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }

        return rightIdx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = leftMost(nums, target);
        int rightIdx = rightMost(nums, target);
        
        return {leftIdx, rightIdx};
    }
};
