class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), st = 0, end = n-1;

        while(st <= end){
            int mid = st+(end-st)/2;

            if(nums[mid] == target) return true;

            // Start = Mid && End = Mid, reduce search space
            if((nums[st] == nums[mid]) && (nums[end] == nums[mid])){
                st++; end--;
            } 

            // Left Half Sorted
            else if(nums[st] <= nums[mid]){
                if(nums[st] <= target && target <= nums[mid]) end = mid-1;
                else st = mid+1;
            }

            // Right Half Sorted
            else if (nums[mid] <= nums[end]){
                if(nums[mid] <= target && target <= nums[end]) st = mid+1;
                else end = mid-1;
            }
        }

        return false;
    }
};
