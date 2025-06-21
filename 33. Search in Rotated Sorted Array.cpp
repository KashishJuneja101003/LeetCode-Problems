// Approach 1: Linear Search TC: O(n) SC: O(1)
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                return i;

        return -1;
    }
};
*/

// Approach 2: Binary Search TC: O(log n) SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return mid;

            // Left half is sorted
            if(nums[l] <= nums[mid]){
                // If target lies in left half move to left half, r = mid-1
                if(nums[l] <= target && target <= nums[mid]) r = mid-1;
                // Else move to right half, l = mid+1
                else l = mid+1;
            }

            // Right half is sorted
            else{
                // If target lies in right half move to right half, l = mid+1
                if(nums[mid] <= target && target <= nums[r]) l = mid+1;
                // Else move to left half, r = mid-1
                else r = mid-1;
            }
        }

        return -1;
    }
};
