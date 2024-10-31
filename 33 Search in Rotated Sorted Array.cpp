class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), start = 0, end = n-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if (nums[mid] == target) return mid;
            else if(nums[start] <= nums[mid])   // If the left half is sorted, go to left
            {
                if(nums[start] <= target && nums[mid] >= target) end = mid-1; //Target must lie in the given range
                else start = mid+1; // Go to RHS
            }
            else    // If the right half is sorted, go to right
            {
                if(nums[mid] <= target && nums[end] >= target) start = mid+1; //Target must lie in the given range
                else end = mid-1;   // Go to LHS
            }
        }
        return -1;
    }
};
