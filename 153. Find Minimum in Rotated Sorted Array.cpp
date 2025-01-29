class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), st = 0, end = n-1, minEl = INT_MAX;
        
        while(st <= end){
            int mid = st+(end-st)/2;

            minEl = min(minEl, nums[mid]);

            // Right Half Having Smaller Elements than Left Half
            if(nums[end] < nums[mid]){
                st = mid+1;
            }
            // Left Half Having Smaller Elements than Right Half
            else{
                end = mid-1;
            }
        }

        return minEl;
    }
};
