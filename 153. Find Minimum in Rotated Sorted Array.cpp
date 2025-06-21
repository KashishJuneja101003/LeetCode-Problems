// Approach 1: Linear Search TC: O(n) SC: O(1)
/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        int num = nums[0];
        for(int i:nums) num = min(i, num);
        return num;
    }
};
*/

// Approach 2: Binary Search TC: O(log n) SC: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        // l < r is taken bcz l <= r would make it an infinte loop
        while(l < r){
            int m = l + (r-l)/2;

            // If nums[m] > nums[r], min element exists in right half
            if(nums[m] > nums[r]) l = m+1;
            // Else min element exists either in left half or at mid, that's why r=m
            else r = m;
        }

        return nums[l];
    }
};
